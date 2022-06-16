/*
 * ciaa_usb_api.c
 *
 *  Created on: Jun 15, 2022
 *      Author: fabri
 */

#include "ciaa_usb_api.h"

const usb_api_t *g_pUsbApi;
lusb_ctrl_t lusb;

/* Endpoint 0 patch that prevents nested NAK event processing */

/* Flag indicating whether EP0 OUT/RX buffer is busy. */
static uint32_t ep0_rx_busy = 0;
/* Variable to store the pointer to base EP0 handler */
static usb_ep_handler_t ep0_handler;

/**
 * @brief	Initialize USB interface.
 * @param	mem_base	: Pointer to memory address which can be used by libusbdev driver
 * @param	mem_size	: Size of the memory passed
 * @return	If found returns the address of requested interface else returns NULL.
 */
ErrorCode_t usb_init(void) {
	/* Configuration variables */
	usb_api_params_t usb_param;
	usb_descriptors_t desc;
	ErrorCode_t ret = LPC_OK;
	usb_core_controller_t ctrl;
	/* enable clocks and USB PHY/pads */
	usb_config_t config = usb_get_default_config();
	/* Setup PLL clock for USB */
	usb_pll_init(config);
	/* Setup USB0 base clock as clock out from USB PLL */
	Chip_Clock_SetBaseClock(config.baseClk, CLKIN_USBPLL, true, true);
	/* enable USB main clock */
	Chip_Clock_EnableBaseClock(config.baseClk);
	Chip_Clock_EnableOpts(CLK_MX_USB0, true, true, 1);
	/* enable USB0 phy */
	usb_enable_phy();
	/* Init USB API structure */
	usb_init_api_structure();
	/* Initialize call back structures */
	usb_init_api_params(&usb_param);
	/* Set the USB descriptors */
	usb_init_descriptors(&desc);
	/* USB Initialization */
	ret = USBD_API->hw->Init(&lusb.hUsb, &desc, &usb_param);
	/* Set handlers */
	if (ret == LPC_OK) { usb_init_handlers(&ctrl); }
	/* Return status */
	return ret;
}

/* Check if libusbdev is connected USB host application. */
bool usb_is_connected(void) {
	usb_core_controller_t* ctrl = (usb_core_controller_t*) lusb.hUsb;
    return (bool) (ctrl->config_value != 0);
}

/* Queue the read buffer to USB DMA */
ErrorCode_t usb_queue_read(char *buf, uint32_t len) {
	lusb_ctrl_t *usb = (lusb_ctrl_t*) &lusb;
	ErrorCode_t ret = ERR_FAILED;

	clear_buffer((uint8_t*)buf);
	/* Check if a read request is pending */
	while (usb->pRxBuf == 0) {
		/* Queue the read request */
		usb->pRxBuf = (uint8_t*)buf;
		usb->rxBuffLen = len;
		USBD_API->hw->ReadReqEP(usb->hUsb, LUSB_OUT_EP, (uint8_t*)buf, len);
		ret = LPC_OK;
	}

	return ret;
}

/* Check if queued read buffer got any data */
int32_t usb_queue_read_done(void) {

	lusb_ctrl_t *usb = (lusb_ctrl_t *) &lusb;

	/* A read request is pending */
	if (usb->pRxBuf) {
		return -1;
	}
	/* if data received return the length */
	return usb->rxBuffLen;
}

/* A blocking read call */
int32_t usb_read(char *buf, uint32_t len) {

	int32_t ret = -1;

	/* Queue read request  */
	if (usb_queue_read(buf, len) == LPC_OK) {
		/* wait for Rx to complete */
		while ( (ret = usb_queue_read_done()) == -1) {
			/* Sleep until next IRQ happens */
			__WFI();
		}
	}

	return ret;
}

/* Queue the given buffer for transmision to USB host application. */
ErrorCode_t usb_queue_send(char *buf) {

	lusb_ctrl_t *usb = (lusb_ctrl_t *) &lusb;
	ErrorCode_t ret = ERR_FAILED;
	uint32_t len = get_buffer_size((uint8_t*)buf);

	/* Check if a read request is pending */
	if (usb->pTxBuf == 0) {
		/* Queue the read request */
		usb->pTxBuf = (uint8_t*)buf;
		usb->txBuffLen = len;

		USBD_API->hw->WriteEP(usb->hUsb, LUSB_IN_EP, (uint8_t*)buf, len);
		ret = LPC_OK;
	}

	return ret;
}

/* Check if queued send is done. */
int32_t usb_queue_send_done(void) {

	lusb_ctrl_t *usb = (lusb_ctrl_t *) &lusb;

	/* return remaining length */
	return usb->txBuffLen;
}

/* Send the given buffer to USB host application */
ErrorCode_t usb_send(char *buf) {

	ErrorCode_t ret = usb_queue_send(buf);

	/* Queue read request  */
	if (ret == LPC_OK) {
		/* wait for Rx to complete */
		while ( usb_queue_send_done() != 0) {
			/* Sleep until next IRQ happens */
			__WFI();
		}
	}
	return ret;
}

/* Send interrupt signal to USB host application. */
ErrorCode_t usb_send_interrupt(uint32_t status) {

	lusb_ctrl_t *usb = (lusb_ctrl_t *) &lusb;

	/* enter critical section */
	NVIC_DisableIRQ(CIAA_USB_IRQ);
	/* update new status */
	usb->newStatus = status;
	/* exit critical section */
	NVIC_EnableIRQ(CIAA_USB_IRQ);

	/* check if we are in middle of sending current status */
	if ( usb->curStatus == 0) {
		/* If not update current status and send */
		usb->curStatus = usb->newStatus;
		usb->newStatus = 0;
		USBD_API->hw->WriteEP(usb->hUsb, LUSB_INT_EP, (uint8_t *) &usb->curStatus, sizeof(uint32_t));
	}

	return LPC_OK;
}

/* Handle interrupt from USB */
void USB_IRQHandler(void)
{
	USBD_API->hw->ISR(lusb.hUsb);
}

/* Private functions */

void usb_init_api_params(usb_api_params_t *params) {

	memset((void *) params, 0, sizeof(USBD_API_INIT_PARAM_T));
	params->usb_reg_base = CIAA_USB_BASE;
	params->max_num_ep = USB_MAX_EP_NUM;
	params->mem_base = USB_STACK_MEM_BASE;
	params->mem_size = USB_STACK_MEM_SIZE;
	params->USB_Reset_Event = usb_reset_event;
}

void usb_init_descriptors(usb_descriptors_t *desc) {

	desc->device_desc = (uint8_t*) USB_DeviceDescriptor;
	desc->string_desc = (uint8_t*) USB_StringDescriptor;
#ifdef USE_USB0
	desc->high_speed_desc = USB_HsConfigDescriptor;
	desc->full_speed_desc = USB_FsConfigDescriptor;
	desc->device_qualifier = (uint8_t*) USB_DeviceQualifier;
#else
	/* Note, to pass USBCV test full-speed only devices should have both
	 * descriptor arrays point to same location and device_qualifier set
	 * to 0.
	 */
	desc->high_speed_desc = (uint8_t*) USB_FsConfigDescriptor;
	desc->full_speed_desc = (uint8_t*) USB_FsConfigDescriptor;
	desc->device_qualifier = 0;
#endif
}

ErrorCode_t usb_init_handlers(usb_core_controller_t *ctrl) {
	/*	WORKAROUND for artf45032 ROM driver BUG:
	    Due to a race condition there is the chance that a second NAK event will
	    occur before the default endpoint0 handler has completed its preparation
	    of the DMA engine for the first NAK event. This can cause certain fields
	    in the DMA descriptors to be in an invalid state when the USB controller
	    reads them, thereby causing a hang.
	 */
	ErrorCode_t ret;
	ctrl = (usb_core_controller_t*) lusb.hUsb;/* convert the handle to control structure */
	ep0_handler = ctrl->ep_event_hdlr[0];/* retrieve the default EP0_OUT handler */
	ctrl->ep_event_hdlr[0] = usb_ep0_patch;/* set our patch routine as EP0_OUT handler */

	/* register WCID handler */
	ret = USBD_API->core->RegisterClassHandler(lusb.hUsb, usb_wcid_handler, &lusb);
	if (ret == LPC_OK) {
		/* register EP2 interrupt handler */
		ret = USBD_API->core->RegisterEpHandler(lusb.hUsb, 2, usb_bulk_out_handler, &lusb);
		if (ret == LPC_OK) {

			ret = USBD_API->core->RegisterEpHandler(lusb.hUsb, 3, usb_bulk_in_handler, &lusb);
			if (ret == LPC_OK) {
				ret = USBD_API->core->RegisterEpHandler(lusb.hUsb, 5, usb_intr_in_handler, &lusb);
				if (ret == LPC_OK) {
					NVIC_EnableIRQ(CIAA_USB_IRQ);/*  enable USB interrrupts */

					/* now connect */
					USBD_API->hw->Connect(lusb.hUsb, 1);
				}
			}
		}
	}
	return ret;
}

ErrorCode_t usb_reset_event(usb_handle_t handle) {
	/* Reset the control structure */
	memset(&lusb, 0, sizeof(lusb_ctrl_t));
	/* Set handler */
	lusb.hUsb = handle;
	return LPC_OK;
}

/* USB bulk EP_IN endpoint handler */
ErrorCode_t usb_bulk_in_handler(usb_handle_t handle, void *data, uint32_t event) {
	lusb_ctrl_t *pUSB = (lusb_ctrl_t*) data;

	if (event == USB_EVT_IN) {
		pUSB->txBuffLen = 0;
		pUSB->pTxBuf = 0;
	}
	return LPC_OK;
}

/* USB bulk EP_IN endpoint handler */
ErrorCode_t usb_intr_in_handler(usb_handle_t handle, void *data, uint32_t event) {
	lusb_ctrl_t *pUSB = (lusb_ctrl_t*) data;

	if (event == USB_EVT_IN) {
		/* check if we have new status to send */
		if (pUSB->newStatus) {
			/* swap and send status */
			pUSB->curStatus = pUSB->newStatus;
			pUSB->newStatus = 0;
			USBD_API->hw->WriteEP(pUSB->hUsb, LUSB_INT_EP, (uint8_t*) &pUSB->curStatus, sizeof(uint32_t));
		}
		else {
			/* nothing to send */
			pUSB->curStatus = 0;
		}
	}
	return LPC_OK;
}

/* USB bulk EP_OUT endpoint handler */
ErrorCode_t usb_bulk_out_handler(usb_handle_t handle, void *data, uint32_t event) {
	lusb_ctrl_t *pUSB = (lusb_ctrl_t*) data;

	/* We received a transfer from the USB host. */
	if (event == USB_EVT_OUT) {
		pUSB->rxBuffLen = USBD_API->hw->ReadEP(handle, LUSB_OUT_EP, pUSB->pRxBuf);
		pUSB->pRxBuf = 0;
	}

	return LPC_OK;
}

/* Handler for WCID USB device requests. */
ErrorCode_t usb_wcid_handler(usb_handle_t handle, void *data, uint32_t event) {
	USB_CORE_CTRL_T *pCtrl = (USB_CORE_CTRL_T*) handle;
	ErrorCode_t ret = ERR_USBD_UNHANDLED;

	if (event == USB_EVT_SETUP) {
		switch (pCtrl->SetupPacket.bmRequestType.BM.Type) {
		case REQUEST_STANDARD:
			if ((pCtrl->SetupPacket.bmRequestType.BM.Recipient == REQUEST_TO_DEVICE) &&
				(pCtrl->SetupPacket.bRequest == USB_REQUEST_GET_DESCRIPTOR) &&
				(pCtrl->SetupPacket.wValue.WB.H == USB_STRING_DESCRIPTOR_TYPE) &&
				(pCtrl->SetupPacket.wValue.WB.L == 0x00EE)) {
				pCtrl->EP0Data.pData = (uint8_t*) WCID_String_Descriptor;
				pCtrl->EP0Data.Count = pCtrl->SetupPacket.wLength;
				USBD_API->core->DataInStage(pCtrl);
				ret = LPC_OK;
			}
			break;

		case REQUEST_VENDOR:
			switch (pCtrl->SetupPacket.bRequest) {
			case 0x0E:		/* libusbK benchmark test */
				pCtrl->EP0Buf[0] = 0x02;
				pCtrl->EP0Data.pData = (uint8_t*) &pCtrl->EP0Buf[0];
				pCtrl->EP0Data.Count = pCtrl->SetupPacket.wLength;
				USBD_API->core->DataInStage(pCtrl);
				ret = LPC_OK;
				break;

			case 0x11:		/* libusbK benchmark test */
				pCtrl->EP0Buf[0] = 'A';
				pCtrl->EP0Buf[1] = 'B';
				pCtrl->EP0Buf[2] = 'C';
				pCtrl->EP0Data.pData = (uint8_t*) &pCtrl->EP0Buf[0];
				pCtrl->EP0Data.Count = pCtrl->SetupPacket.wLength;
				USBD_API->core->DataInStage(pCtrl);
				ret = LPC_OK;
				break;

			case 0x10:		/* libusbK benchmark test */
				pCtrl->EP0Data.pData = pCtrl->EP0Buf;	/* data to be received */
				ret = LPC_OK;
				break;

			case LUSB_PID:
				switch (pCtrl->SetupPacket.bmRequestType.BM.Recipient) {
				case REQUEST_TO_DEVICE:
					if (pCtrl->SetupPacket.wIndex.W == 0x0004) {
						pCtrl->EP0Data.pData = (uint8_t*) WCID_CompatID_Descriptor;
						pCtrl->EP0Data.Count = pCtrl->SetupPacket.wLength;
						USBD_API->core->DataInStage(pCtrl);
						ret = LPC_OK;
					}
					break;
				}
				break;
			}
		}
	}
	else if ((event == USB_EVT_OUT) && (pCtrl->SetupPacket.bmRequestType.BM.Type == REQUEST_VENDOR)) {
		if (pCtrl->SetupPacket.bRequest == 0x10) {
			USBD_API->core->StatusInStage(pCtrl);
			ret = LPC_OK;
		}
	}

	return ret;
}

/* EP0_patch part of WORKAROUND for artf45032. */
ErrorCode_t usb_ep0_patch(usb_handle_t handle, void *data, uint32_t event) {

	switch (event) {
		case USB_EVT_OUT_NAK:
			if (ep0_rx_busy) {
				/* we already queued the buffer so ignore this NAK event. */
				return LPC_OK;
			}
			else {
				/* Mark EP0_RX buffer as busy and allow base handler to queue the buffer. */
				ep0_rx_busy = 1;
			}
			break;

		case USB_EVT_SETUP:	/* reset the flag when new setup sequence starts */
		case USB_EVT_OUT:
			/* we received the packet so clear the flag. */
			ep0_rx_busy = 0;
			break;
	}
	return ep0_handler(handle, data, event);
}

void usb_pll_init(usb_config_t config) {
	/* Get pll configuration */
	pll_config_t pll = config.pll;
	/* No need to setup anything if PLL is already setup for the frequency */
	if (Chip_Clock_GetClockInputHz(CLKIN_USBPLL) == pll.freq) { return; }
	/* Setup default USB PLL state for a 480MHz output from 12MHz input and attach */
	Chip_Clock_SetupPLL(config.inClk, CGU_USB_PLL, &pll);
	/* enable USB PLL */
	Chip_Clock_EnablePLL(CGU_USB_PLL);
	/* Wait for PLL lock */
	while (!(Chip_Clock_GetPLLStatus(CGU_USB_PLL) & CGU_PLL_LOCKED));
}

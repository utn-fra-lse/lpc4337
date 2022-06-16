/*
 * ciaa_usb_api.h
 *
 *  Created on: Jun 15, 2022
 *      Author: fabri
 */

#ifndef CIAA_USB_API_H_
#define CIAA_USB_API_H_

#include "chip.h"
#include "lpc_types.h"
#include "error.h"
#include "usbd_rom_api.h"
#include <string.h>

typedef CGU_USBAUDIO_PLL_SETUP_T pll_config_t;
typedef CHIP_CGU_CLKIN_T usb_input_clk_t;
typedef CHIP_CGU_BASE_CLK_T usb_base_clk_t;
typedef USBD_HANDLE_T usb_handle_t;
typedef USBD_API_T usb_api_t;
typedef USBD_API_INIT_PARAM_T usb_api_params_t;
typedef USB_CORE_DESCS_T usb_descriptors_t;
typedef USB_EP_HANDLER_T usb_ep_handler_t;
typedef USB_CORE_CTRL_T usb_core_controller_t;

typedef struct {
	pll_config_t pll;
	usb_input_clk_t inClk;
	usb_base_clk_t baseClk;
} usb_config_t;

/**
 * Structure containing Virtual Comm port control data
 */
typedef struct {
	USBD_HANDLE_T hUsb;
	uint8_t *pRxBuf;
	uint32_t rxBuffLen;
	uint8_t *pTxBuf;
	uint32_t txBuffLen;
	uint32_t newStatus;
	uint32_t curStatus;
	volatile uint8_t connected;
} lusb_ctrl_t;

/* USB descriptor arrays defined *_desc.c file */
extern const uint8_t USB_DeviceDescriptor[];
extern uint8_t USB_HsConfigDescriptor[];
extern uint8_t USB_FsConfigDescriptor[];
extern const uint8_t USB_StringDescriptor[];
extern const uint8_t USB_DeviceQualifier[];
extern const uint8_t WCID_String_Descriptor[];
extern const uint8_t WCID_CompatID_Descriptor[];

/* Inline functions */
static inline usb_config_t usb_get_default_config(void) {
	/* USB PLL pre-initialized setup values for 480MHz output rate */
	usb_config_t config  = {
		{
			0x0000601D,		/* Default control with main osc input, PLL disabled */
			0x06167FFA,		/* M-divider value for 480MHz output from 12MHz input */
			0x00000000,		/* N-divider value */
			0x00000000,		/* Not applicable for USB PLL */
			480000000  		/* PLL output frequency */
		},
		CLK_BASE_USB0,		/* USB base clk */
		CLKIN_IRC			/* USB PLL clock input */
	};
	return config;
}

/**
 * @brief	Enables the USB0 high-speed PHY on LPC18xx/LPC43xx parts
 * @return	Nothing
 * @note	The USB0 PLL & clock should be configured before calling this function. This function
 * should be called before the USB0 registers are accessed.
 */
static inline void usb_enable_phy(void) { LPC_CREG->CREG0 &= ~(1 << 5); }

static inline void usb_init_api_structure(void) { USBD_API = (const usb_api_t*) LPC_ROM_API->usbdApiBase; }

static inline void clear_buffer(uint8_t *buf) {
	uint32_t size = 0;
	while(*buf) {
		*buf = 0;
		size++;
	}
	buf = buf - size;
}

static inline uint32_t get_buffer_size(uint8_t *buf) {
	uint32_t size = 0;
	while(*buf) {
		buf++;
		size++;
	}
	buf = buf - size;
	return size;
}

/* Function prototypes */
void usb_init_api_params(usb_api_params_t *params);
void usb_init_descriptors(usb_descriptors_t *desc);
ErrorCode_t usb_init_handlers(usb_core_controller_t *ctrl);

ErrorCode_t usb_init(void);
bool usb_is_connected(void);
ErrorCode_t usb_queue_read(char *buf, uint32_t len);
int32_t usb_queue_read_done(void);
int32_t usb_read(char *buf, uint32_t len);
ErrorCode_t usb_queue_send(char *buf);
int32_t usb_queue_send_done(void);
ErrorCode_t usb_send(char *buf);
ErrorCode_t usb_send_interrupt(uint32_t status);

ErrorCode_t usb_reset_event(usb_handle_t handle);
ErrorCode_t usb_bulk_in_handler(usb_handle_t handle, void *data, uint32_t event);
ErrorCode_t usb_intr_in_handler(usb_handle_t handle, void *data, uint32_t event);
ErrorCode_t usb_bulk_out_handler(usb_handle_t handle, void *data, uint32_t event);
ErrorCode_t usb_wcid_handler(usb_handle_t handle, void *data, uint32_t event);
ErrorCode_t usb_ep0_patch(usb_handle_t handle, void *data, uint32_t event);
void usb_pll_init(usb_config_t config);

#endif /* CIAA_USB_API_H_ */

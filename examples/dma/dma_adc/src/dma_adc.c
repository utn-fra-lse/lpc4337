/*
===============================================================================
 Name        : dma_adc.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_board_api.h"
#include "ciaa_dma_api.h"
#include "ciaa_adc_api.h"

/* DMA buffer size */
#define DMA_BUFFER_SIZE	2048
/* DMA IRQ status flag */
bool dma_flag = false;

/**
 * @brief DMA interrupt handler
 */
void dma_handler(void) {
	/* Toggle blue LED */
	gpio_xor(LEDB);
	/* Set DMA flag */
	dma_flag = true;
}

/**
 * @brief main program
 */
int main(void) {
	/* ADC conversion factor */
	const float conv_factor = 3.3 / (1 << 10);
	/* Buffer to store DMA transfer results */
	uint32_t dst[DMA_BUFFER_SIZE];
	/* Buffer to store ADC results */
	float adc_results[DMA_BUFFER_SIZE];
	/* ADC selected channel */
	const uint8_t adc_channel = ADC_CH0;
	/* Init CIAA board */
	ciaa_board_init();
	/* Get ADC default configuration struct */
	adc_config_t config = adc_get_default_config();
	/* Enable burst mode */
	config.burstMode = ENABLE;
	/* Configure ADC0 */
	adc_config_init(0, config);
	/* Enable interrupt on the selected channel. Needed for DMA to work */
	adc_set_irq_channel_enabled(0, adc_channel, ENABLE);
	/* DMA configuration struct */
	dma_config_t dma = {
			dma_get_free_channel(),					/* Find a free DMA channel */
			conn_adc0,								/* Source from transfer is ADC0 */
			(uint32_t) dst,							/* Transfer destiny is the buffer */
			DMA_BUFFER_SIZE,						/* Buffer size */
			GPDMA_TRANSFERTYPE_P2M_CONTROLLER_DMA	/* Peripheral to memory connection */
	};
	/* Set a DMA channel handler */
	dma_set_channel_handler(dma.channel, dma_handler);
	/* Initialize DMA controller */
	dma_init();

//	DMA_TransferDescriptor_t dma_descriptor;

//	Chip_GPDMA_PrepareDescriptor(
//			LPC_GPDMA,
//			&dma_descriptor,
//			GPDMA_CONN_ADC_0,
//			(uint32_t) dst,
//			DMA_BUFFER_SIZE,
//			GPDMA_TRANSFERTYPE_P2M_CONTROLLER_DMA,
//			NULL
//	);

	//Chip_GPDMA_SGTransfer (LPC_GPDMA, dma.channel, &dma_descriptor, GPDMA_TRANSFERTYPE_P2M_CONTROLLER_DMA);
	//dma_descriptor.ctrl |= GPDMA_DMACCxControl_I;

	while(1) {
		/* Initialize DMA transfer */
		dma_transfer(dma);
		/* Wait for DMA transfer to finish */
		while(!dma_flag);
		/* Clear DMA interrupt flag */
		dma_flag = false;
		/* Get proper ADC results */
		for(uint32_t i = 0; i < DMA_BUFFER_SIZE; i++) {
			/* Need to shift 4 bits to get ADC result */
			adc_results[i] = ADC_DR_RESULT(dst[i]) * conv_factor;
		}
	}

	return 0;
}

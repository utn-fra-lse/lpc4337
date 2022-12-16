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
#include "ciaa_dac_api.h"

#define DAC_INPUT

/* DMA buffer size */
#ifndef DAC_INPUT
#define DMA_BUFFER_SIZE	2048
#else
#define DMA_BUFFER_SIZE 64
#endif
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
	const uint8_t adc_channel = ADC_CH1;
	/* Init CIAA board */
	ciaa_board_init();
	/* Get ADC default configuration struct */
	adc_config_t config = adc_get_default_config();
	/* Enable burst mode */
	config.burstMode = ENABLE;
	/* Configure ADC0 */
	adc_config_init(0, config);
	/* Enable selected channel */
	adc_select_input(0, adc_channel);
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

#ifdef DAC_INPUT
	/* DAC direction */
	bool up = true;
	/* DAC value */
	int16_t dac_value = 0x00;
	/* Get DAC config */
	dac_config_t dac_config = dac_get_default_config();
	/* Set DAC initial value to zero */
	dac_config.value = dac_value;
	/* Initialize DAC */
	dac_config_init(dac_config);
#endif

	while(1) {
#ifdef DAC_INPUT
		/* Check DAC count direction */
		if(up) {
			/* Increment DAC value */
			dac_value+=50;
			/* Check if high limit was surpassed */
			if(dac_value > 0x3ff) {
				/* Change direction */
				up = false;
				/* Decrement */
				dac_value--;
			}
		}
		else {
			/* Decrement DAC value */
			dac_value-=50;
			/* Check if low limit was surpassed */
			if(dac_value < 0) {
				/* Change direction */
				up = true;
				/* Increment */
				dac_value++;
			}
		}
		/* Update value */
		dac_set_output_value(dac_value);
#endif
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

/*
===============================================================================
 Name        : multicore_adc_fft_m0app.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_ipc_api.h"
#include "ciaa_adc_api.h"
#include "ciaa_dma_api.h"
#include "ciaa_stdlib.h"
#include "ciaa_board_api.h"

/* Number of maximum ADC samples */
#define MAX_SAMPLES	256
/* Number of mininum ADC samples */
#define MIN_SAMPLES 32

/* Initialize ADC buffer */
float complexInput[2 * MAX_SAMPLES] = { 0.0 };
/* ADC conversion done flag */
bool adc_done = false;
/* ADC result */
uint16_t adc_result;
/* DMA result buffer */
uint32_t dma_buffer[MAX_SAMPLES];
/* DMA channel */
uint8_t dma_channel;
/* DMA transfer done flag */
bool dma_transfer_done = false;

/**
 * @brief Struct to hold shared data between cores
 */
typedef struct {
	uint16_t size;		/* Size of real samples */
	uint8_t nclocks;	/* Number of clocks that the conversion takes */
	float *samples;		/* Pointer to samples */
} data_t;

/* DMA channel interrupt handler */
void dma_handler(void);


int main(void) {
	/* Initialize board */
	ciaa_board_init();
	/* ADC conversion factor */
	const float conversion_factor = 3.3 / (1 << 10);
	/* Extra variable to store size temporally */
	uint16_t fftSize = MIN_SAMPLES;
	/* Shared data */
	data_t data;
	/* Point to samples */
	data.samples = complexInput;
	/* Default FFT size */
	data.size = MIN_SAMPLES;
	/* Struct address */
	uint32_t addr = (uint32_t)&data;
	/* Get ADC default configuration */
	adc_config_t config = adc_get_default_config();
	/* Enable burst mode */
	config.burstMode = ENABLE;
	/* Configure to 3 bits of resolution. Takes four clocks to finish conversion (1.125MS/s) */
	if(!gpio_get(TEC1)) { config.bitsAccuracy = adc_3bits; }
	/* Configure to 5 bits of resolution. Takes six clocks to finish conversion (750KS/s) */
	else if(!gpio_get(TEC2)) { config.bitsAccuracy = adc_5bits; }
	/* Configure to 7 bits of resolution. Takes eight clocks to finish conversion (562.5KS/2)  */
	else if(!gpio_get(TEC3)) { config.bitsAccuracy = adc_7bits; }
	/* Configure to 9 bits of resolution. Takes ten clocks to finish conversion (450KS/s) */
	else if(!gpio_get(TEC4)) { config.bitsAccuracy = adc_9bits; }
	/* Configure to 10 bits of resolution. Takes eleven clocks to finish conversion (~400KS/s) */
	else { config.bitsAccuracy = adc_10bits; }
	/* Set number of clocks that conversion takes */
	data.nclocks = adc_get_number_of_clocks(config.bitsAccuracy);
	/* ADC initialization */
	adc_config_init(0, config);
	/* Select ADC channel 0 */
	adc_select_input(0, ADC_CH0);
	/* Enable interrupt on channel 0 */
	adc_set_irq_channel_enabled(0, ADC_CH0, true);
	/* IPC quque initialization */
	ipc_queue_init(&addr, sizeof(uint32_t), 1);
	/* Enable DMA controller */
	dma_init();
	/* Get a DMA free channel */
	dma_channel = dma_get_free_channel();
	/* Create DMA config struct */
	dma_config_t dma_config = {
		dma_channel,							/* DMA channel to use */
		conn_adc0,								/* Source of DMA is ADC0 */
		(uint32_t) dma_buffer,					/* Destiny address */
		fftSize,								/* Size of the transfer */
		GPDMA_TRANSFERTYPE_P2M_CONTROLLER_DMA	/* Peripheral to memory */
	};
	/* Set DMA interrupt handler */
	dma_set_channel_handler(dma_config.channel, dma_handler);
	/* Initiate DMA transfer */
	dma_transfer(dma_config);

	while(1) {
		/* Check TEC1 (32 samples) */
		if(!gpio_get(TEC1)) { fftSize = 32; }
		/* Check TEC2 (64 samples) */
		else if(!gpio_get(TEC2)) { fftSize = 64; }
		/* Check TEC3 (128 samples) */
		else if(!gpio_get(TEC3)) { fftSize = 128; }
		/* Check TEC4 (256 samples) */
		else if(!gpio_get(TEC4)) { fftSize = 256; }
		/* Check DMA transfer */
		if(dma_transfer_done) {
			/* Go through every ADC sample */
			for(uint32_t i = 0; i < dma_config.size; i++) {
				/* Clear odd indexes */
				complexInput[(i * 2) + 1] = 0.0;
				/* Copy ADC result */
				complexInput[i * 2] = ADC_DR_RESULT(dst[i]) * conversion_factor;
			}
			/* Clear flag */
			dma_transfer_done = false;
			/* Send data to M4 core */
			ipc_try_push(&addr);
			/* Update DMA transfer size */
			dma_config.size = fftSize;
			/* Update FFT size */
			data.size = fftSize;
			/* Initiate a new DMA transfer */
			dma_transfer(dma_config);
		}
	}
	return 0;
}

/**
 * @brief DMA interrupt handler
 */
void dma_handler(void) {
	/* Raise flag */
	dma_transfer_done = true;
}

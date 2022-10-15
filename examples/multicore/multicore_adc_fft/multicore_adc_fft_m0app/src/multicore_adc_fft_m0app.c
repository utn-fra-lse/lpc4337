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

/**
 * @brief Struct to hold shared data between cores
 */
typedef struct {
	uint16_t size;		/* Size of real samples */
	float *samples;		/* Pointer to samples */
} data_t;

/* ADC interrupt handler prototype */
void adc_conversion_done(void);


int main(void) {
	/* Initialize board */
	ciaa_board_init();
	/* ADC conversion factor */
	const float conversion_factor = 3.3 / (1 << 10);
	/* Index */
	uint16_t i = 0;
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
	/* Enable interrupt */
	config.interrupt = ENABLE;
	/* Takes four clocks to finish conversion (1.6MS/s) */
	config.bitsAccuracy = adc_3bits;
	/* ADC initialization */
	adc_config_init(0, config);
	/* Select ADC channel 0 */
	adc_select_input(0, ADC_CH0);
	/* Set interrupt handler */
	adc_set_irq_handler(0, adc_conversion_done);
	/* Enable interrupt on channel 0 */
	adc_set_irq_channel_enabled(0, ADC_CH0, true);
	/* IPC quque initialization */
	ipc_queue_init(&addr, sizeof(uint32_t), 1);

	while(1) {
		/* Check TEC1 (32 samples) */
		if(!gpio_get(TEC1)) { fftSize = 32; }
		/* Check TEC2 (64 samples) */
		else if(!gpio_get(TEC2)) { fftSize = 64; }
		/* Check TEC3 (128 samples) */
		else if(!gpio_get(TEC3)) { fftSize = 128; }
		/* Check TEC4 (256 samples) */
		else if(!gpio_get(TEC4)) { fftSize = 256; }
		/* Check ADC conversion */
		if(adc_done) {
			/* Clear odd indexes */
			complexInput[(i * 2) + 1] = 0.0;
			/* Copy values in even indexes */
			complexInput[i * 2] = adc_result * conversion_factor;
			/* Reset flag */
			adc_done = false;
			/* Increment index */
			i++;
			/* Check if we reached the necessary samples */
			if(i == data.size) {
				/* Try to push samples address to IPC */
				ipc_try_push(&addr);
				/* Reset index */
				i = 0;
				/* Update size for next sampling */
				data.size = fftSize;
			}
		}
	}
	return 0;
}

/**
 * @brief ADC0 interrupt handler
 */
void adc_conversion_done(void) {
	/* Get ADC value (10 bits) */
	adc_result = adc_read(0);
	/* Conversion done */
	adc_done = true;
}

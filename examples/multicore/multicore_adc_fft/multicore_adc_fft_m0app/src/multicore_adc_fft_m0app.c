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

/* Number of ADC samples */
#define N_SAMPLES	64

/* Initialize ADC buffer */
float complexInput[N_SAMPLES] = { 0.0 };
/* ADC conversion done flag */
bool adc_done = false;
/* ADC result */
uint16_t adc_result;

/* ADC interrupt handler prototype */
void adc_conversion_done(void);


int main(void) {
	/* FFT size */
	const uint32_t fftSize = N_SAMPLES / 2;
	/* ADC conversion factor */
	const float conversion_factor = 3.3 / (1 << 10);
	/* Index */
	uint16_t i = 0;
	/* Results address */
	uint32_t addr = (uint32_t)complexInput;
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
			if(i == fftSize) {
				/* Try to push samples address to IPC */
				ipc_try_push(&addr);
				/* Reset index */
				i = 0;
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

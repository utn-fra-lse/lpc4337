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
#define N_SAMPLES	8

/* Initialize ADC buffer */
float complexInput[N_SAMPLES] = { 0.0 };

int main(void) {
	/* FFT size */
	const uint32_t fftSize = N_SAMPLES / 2;
	/* ADC conversion factor */
	const float conversion_factor = 3.3 / (1 << 10);
	/* Results address */
	uint32_t addr = (uint32_t)complexInput;
	/* ADC initialization */
	adc_init(0);
	/* Select ADC channel 0 */
	adc_select_input(0, ADC_CH0);
	/* IPC quque initialization */
	ipc_queue_init(&addr, sizeof(uint32_t), 1);

	while(1) {
		/* Create complex array for FFT analysis */
		for(uint16_t i = 0; i < fftSize; i++) {
			/* Clear odd indexes */
			complexInput[(i * 2) + 1] = 0.0;
			/* Copy values in even indexes */
			complexInput[i * 2] = adc_read(0) * conversion_factor;
		}
		/* Try to push samples address to IPC */
		ipc_try_push(&addr);
	}
	return 0;
}

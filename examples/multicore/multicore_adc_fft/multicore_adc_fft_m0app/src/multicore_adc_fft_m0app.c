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
#define N_SAMPLES	512

/* Initialize ADC buffer */
uint16_t adcResults[N_SAMPLES] = { 0 };

int main(void) {
	/* ADC result */
	float result;
	/* Array index */
	uint16_t index = 0;
	/* ADC default initialization */
	adc_init(0);
	/* Select ADC channel 0 */
	adc_select_input(0, ADC_CH0);
	/* IPC quque initialization */
	ipc_queue_init(adcResults, sizeof(uint16_t), N_SAMPLES);

	while(1) {
		/* Do ADC conversion and store into results */
		adcResults[index++] = adc_read(0);
		/* Check if array is full already */
		if(index == N_SAMPLES) {
			/* Try to push samples to IPC */
			ipc_try_push(adcResults);
			/* Reset index */
			index = 0;
			/* Wait half a second */
			sleep_ms(500);
		}
	}
	return 0;
}

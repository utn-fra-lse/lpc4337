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
#define N_SAMPLES	2048

int main(void) {
	/* ADC conversion factor */
	const float conv_factor = 3.3 / (1 << 10);
	/* Initialize complex signal buffer */
	float signal[N_SAMPLES * 2] = { 0.0 };
	/* Results address */
	uint32_t addr = (uint32_t)signal;
	/* Array index */
	uint16_t index = 0;
	/* ADC default initialization */
	adc_init(0);
	/* Select ADC channel 0 */
	adc_select_input(0, ADC_CH0);
	/* IPC quque initialization */
	ipc_queue_init(&addr, sizeof(uint32_t), 1);

	while(1) {
		/* Do ADC conversion and store into even indexes */
		signal[index * 2] = conv_factor * adc_read(0);
		/* Clear imaginary indexes */
		signal[(index * 2) + 1] = 0.0;
		/* Increment index */
		index++;
		/* Check if array is full already */
		if(index == N_SAMPLES / 2) {
			/* Try to push samples address to IPC */
			ipc_try_push(&addr);
			/* Reset index */
			index = 0;
			/* Wait half a second */
			sleep_ms(500);
		}
	}
	return 0;
}

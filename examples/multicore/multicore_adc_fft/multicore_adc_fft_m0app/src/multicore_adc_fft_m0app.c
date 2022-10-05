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

int main(void) {
	/* ADC conversion factor */
	const float conv_factor = 3.3 / (1 << 10);
	/* ADC result */
	float result;
	/* ADC default initialization */
	adc_init(0);
	/* Select ADC channel 0 */
	adc_select_input(0, ADC_CH0);
	/* IPC quque initialization */
	ipc_queue_init(&result, sizeof(float), 1);

	while(1) {
		/* Do ADC conversion and get voltage */
		result = conv_factor * adc_read(0);
		/* Try to push value to IPC */
		ipc_try_push(&result);
		/* Wait half a second */
		sleep_ms(500);
	}
	return 0;
}

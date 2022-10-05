/*
===============================================================================
 Name        : multicore_adc_fft_m4.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <stdio.h>
#include "ciaa_ipc_api.h"

int main(void) {
	/* ADC result */
	float result;
	/* Conversion counter */
	uint16_t i = 0;
	/* IPC quque initialization */
	ipc_queue_init(&result, sizeof(float), 1);
    /* Start M0 core */
    multicore_m0_start();

	while(1) {
		/* Try to pop value from IPC */
		if(ipc_try_pop(&result) == queue_valid) {
#ifdef DEBUG
    		/* Print result */
    		printf("%04d: %3.2f\r\n", i++, result);
#endif
		}
	}
	return 0;
}

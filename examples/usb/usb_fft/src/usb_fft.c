/*
===============================================================================
 Name        : usb_fft.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_usb_api.h"
#include "ciaa_stdlib.h"
#include "arm_math.h"
#include "arm_const_structs.h"
#include <string.h>
#include <stdio.h>

/* Number of samples */
#define FFT_SAMPLES 128

/* External test input */
extern float32_t testInput_f32_1khz[128];

/* RFFT instance, needs to be global */
arm_rfft_fast_instance_f32 S;

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Initialize USB0 with default configuration */
	usb_init();
	/* RFFT result goes here */
	float32_t outputSignal[FFT_SAMPLES];
	/* Initialize RFFT instance */
	arm_status status = arm_rfft_fast_init_f32(&S, FFT_SAMPLES);

	if(status == ARM_MATH_SUCCESS) {
		/* Continue if initialization was a success */
		arm_rfft_fast_f32(&S, testInput_f32_1khz, outputSignal, 0);

		while(1) {
			/* Check if host is connected */
			if(usb_is_connected()) {
				/* Send first couple of JSON format characters */
				char str[25] = "{\"values\":[";
				usb_send(str);
				/* Convert every output value to string in scientific notation */
				uint8_t i;
				for(i = 0; i < FFT_SAMPLES - 1; i++) {
					/* Format string and send except the last one */
					sprintf(str, "%e,", outputSignal[i]);
					usb_send(str);
				}
				/* Send last value with closing JSON format characters */
				sprintf(str, "%e]}", outputSignal[i]);
				usb_send(str);
				/* Wait */
				sleep_ms(2000);
			}
		}
	}

	return 0;
}

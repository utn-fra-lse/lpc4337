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
#include "arm_math.h"
#include <stdio.h>

#define N_SAMPLES 1024

/* Input to test */
extern float32_t testInput[N_SAMPLES];
/* Output buffer */
static float32_t testOutput[N_SAMPLES / 2];

/* FFT configuration */
uint32_t fftSize = N_SAMPLES / 2;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;
/* CFFT instance */
arm_cfft_instance_f32 s;

int main(void) {
	/* Initialize USB0 with default configuration */
	usb_init();
	/* ARM math status */
	arm_status status = ARM_MATH_SUCCESS;
	/* Initialize CFFT instance */
	status = arm_cfft_init_f32(&s, fftSize);
	/* Process the data through the CFFT/CIFFT module */
	arm_cfft_f32(&s, testInput, ifftFlag, doBitReverse);
	/* Calculate the magnitude at each bin, it's symmetrical */
	arm_cmplx_mag_f32(testInput, testOutput, fftSize);
	/* Continue if math was successful */
	if (status == ARM_MATH_SUCCESS) {
		/* Wait for host to be connected */
		while(!usb_is_connected());
		/* Get size of FFT result */
		uint16_t n = sizeof(testOutput) / sizeof(testOutput[0]);
		/* Send first couple of JSON format characters */
		char str[25] = "{\"values\":[";
		usb_send(str);
		/* Convert every output value to string in scientific notation */
		uint16_t i;
		for(i = 0; i < n / 2 - 1; i++) {
			/* Format string and send except the last one */
			sprintf(str, "%e,", testOutput[i]);
			usb_send(str);
		}
		/* Send last value with closing JSON format characters */
		sprintf(str, "%e]}", testOutput[i]);
		usb_send(str);

		while(1);
	}
}

/*
===============================================================================
 Name        : fft_cfft.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <stdio.h>
#include "arm_math.h"

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
	/* ARM math status */
	arm_status status = ARM_MATH_SUCCESS;
	/* Initialize CFFT instance */
	status = arm_cfft_init_f32(&s,fftSize);
	/* Process the data through the CFFT/CIFFT module */
	arm_cfft_f32(&s, testInput, ifftFlag, doBitReverse);
	/* Calculate the magnitude at each bin, it's symmetrical */
	arm_cmplx_mag_f32(testInput, testOutput, fftSize);
	/* Continue if math was successful */
	if (status == ARM_MATH_SUCCESS) {
		/* Get size of FFT result */
		uint16_t n = sizeof(testOutput) / sizeof(testOutput[0]);
		/* Print number of samples */
		printf("FFT output with %d samples (symmetric values removed)\r\n", n / 2);
		/* Get rid of second half */
		for(uint16_t i = 0; i < n / 2; i++) {
			/* Print a new line every 16 values */
			if(!(i % 16)) { printf("\r\n"); }
			/* Print values */
			printf("%12.6f,", i, testOutput[i]);
		}
		while (1);
	}
}


/*
===============================================================================
 Name        : fft_rfft.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_stdlib.h"
#include "arm_math.h"
#include <string.h>
#include <stdio.h>

#define N_SAMPLES	512

#define TEST_2
#define PYTHON_OUTPUT
/* Number of samples */
#ifdef TEST_1
/**
 * Test# 1: Fill your input buffer with 512 samples with each sample
 * having an amplitude of +1. Your magnitude spectrum should show energy
 * (magnitude = 512) at zero Hz and no spectral energy at any other frequency.
 */
extern float32_t testInput1[512];
#define testInput	testInput1
#define TEST_N	1
#elif defined(TEST_2)
/**
 * Test# 2: Fill your input buffer with a single sample having an
 * amplitude of +1 and the next 511 samples equal to zero. Your magnitude
 * spectrum should show energy (magnitude = 512) at zero Hz and no spectral
 * energy at any other frequency. Your magnitude spectrum should show a magnitude = 1
 * at all frequencies.(You spectral magnitude curve should be a flat line.)
 */
extern float32_t testInput2[512];
#define testInput	testInput2
#define TEST_N	2
#elif defined(TEST_3)
/**
 * Test# 3: Fill your input buffer with six samples whose amplitudes are all +1
 * followed by 506 samples whose amplitudes are all zero. Your magnitude spectrum
 * should show a classic |sin(x)/x| spectral envelope with the DC, zero Hz, spectral
 * component showing a magnitude of six.
 */
extern float testInput3[512];
#define testInput testInput3
#define TEST_N	3
#endif

/* External test input */

float32_t testOutput[N_SAMPLES];

/* RFFT instance, needs to be global */
arm_rfft_fast_instance_f32 S;

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Initialize RFFT instance */
	arm_status status = arm_rfft_fast_init_f32(&S, N_SAMPLES);
	arm_rfft_fast_f32(&S, testInput, testOutput, 0);

	arm_cmplx_mag_f32(testInput, testOutput, N_SAMPLES);

	sleep_ms(500);
	printf("RFFT Test n%d\n\n", TEST_N);
	sleep_ms(500);

	if(status == ARM_MATH_SUCCESS) {
#ifndef PYTHON_OUTPUT
		printf("N, Freq\r\n");
#endif
		for (int i = 0; i < sizeof(testOutput)/sizeof(testOutput[0]); i++) {
#ifdef	PYTHON_OUTPUT
			printf("%f,", testOutput[i]);
			if((i % 8) == 0) {
				printf("\r\n");
			}
#else
			printf("%d, %f\r\n", i, testOutput[i]);
#endif
		}
	}

	while(1);

	return 0;
}


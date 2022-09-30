/*
===============================================================================
 Name        : multicore_rfft_basic_m4.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "arm_math.h"
#include "arm_const_structs.h"

/* Number of samples */
#define FFT_SAMPLES 2048

/* External test input */
extern float32_t testInput_f32_10khz[2048];

/* RFFT instance, needs to be global */
arm_rfft_fast_instance_f32 S;

int main(void) {

	/* RFFT result goes here */
	float32_t outputSignal[FFT_SAMPLES];

	/* Initialie RFFT instance */
	arm_status status = arm_rfft_fast_init_f32(&S, FFT_SAMPLES);

	if(status == ARM_MATH_SUCCESS) {
		/* Continue if initialization was a success */
		arm_rfft_fast_f32(&S, testInput_f32_10khz, outputSignal, 0);

		while(1);
	}

	return 0;
}

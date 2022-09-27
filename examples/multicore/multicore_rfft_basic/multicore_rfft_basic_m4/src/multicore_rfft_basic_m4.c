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

// using a 1024 point signal
#define FFT_SAMPLES 32
#define FFT_SAMPLES_HALF (FFT_SAMPLES / 2)

float32_t testInput_f32_10khz[FFT_SAMPLES] = {

	0.00000000,  2.01298520,  3.94355855,  5.71268215,
	7.24792787,  8.48644257,  9.37752132,  9.88468324,
	9.98716507,  9.68077119,  8.97804540,  7.90775737,
	6.51372483,  4.85301963,  2.99363123,  1.01168322,
   -1.01168322, -2.99363123, -4.85301963, -6.51372483,
   -7.90775737, -8.97804540, -9.68077119, -9.98716507,
   -9.88468324, -9.37752132, -8.48644257, -7.24792787,
   -5.71268215, -3.94355855, -2.01298520,  0.00000000
};

#define inputSignal testInput_f32_10khz
// see gist
static float32_t complexFFT[FFT_SAMPLES], realFFT[FFT_SAMPLES_HALF],
		imagFFT[FFT_SAMPLES_HALF], angleFFT[FFT_SAMPLES_HALF],
		powerFFT[FFT_SAMPLES_HALF];

uint32_t fftSize = FFT_SAMPLES;
uint32_t ifftFlag = 0;
arm_rfft_fast_instance_f32 S;
uint32_t maxIndex = 0;
arm_status status;
float32_t maxValue;
int i;

int main(void) {

	status = ARM_MATH_SUCCESS;
	status = arm_rfft_fast_init_f32(&S, fftSize);
	// input is real, output is interleaved real and complex
	arm_rfft_fast_f32(&S, inputSignal, complexFFT, ifftFlag);

	// first entry is all real DC offset
	//float32_t DCoffset = complexFFT[0];

	// de-interleave real and complex values
	for (i = 0; i < (FFT_SAMPLES / 2) - 1; i++) {
		realFFT[i] = complexFFT[i * 2];
		imagFFT[i] = complexFFT[(i * 2) + 1];
	}

  	  // find angle of FFT
	for (i = 0; i < FFT_SAMPLES / 2; i++) {
		angleFFT[i] = atan2f(imagFFT[i], realFFT[i]);
	}
	// compute power
	arm_cmplx_mag_squared_f32(complexFFT, powerFFT, FFT_SAMPLES_HALF);
	arm_max_f32(&powerFFT[1], FFT_SAMPLES_HALF - 1, &maxValue, &maxIndex);
	// correct index
	maxIndex += 1;

	while(1);

	return 0;
}

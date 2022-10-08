/*
===============================================================================
 Name        : adc_fft.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <stdio.h>
#include "ciaa_usb_api.h"
#include "ciaa_adc_api.h"
#include "arm_math.h"

/* Number of ADC samples */
#define N_SAMPLES	2048

/* FFT configuration */
uint32_t fftSize = N_SAMPLES / 2;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;

/* Complex data */
float32_t complexInput[N_SAMPLES] = { 0.0 };
/* FFT output */
float32_t fftOutput[N_SAMPLES / 2];

/* CFFT instance */
arm_cfft_instance_f32 s;

int main(void) {
#ifdef DEBUG
	/* Max value of FFT */
	float32_t maxValue;
	/* Max value of FFT index */
	uint32_t maxIndex;
#endif
	/* ADC conversion factor */
	const float32_t conv_factor = 3.3 / (1 << 10);
	/* Initialize USB */
	usb_init();
	/* ARM math status */
	arm_status status = ARM_MATH_SUCCESS;
	/* Initialize CFFT instance */
	status = arm_cfft_init_f32(&s, fftSize);
	/* ADC default configuration */
	adc_config_t config = adc_get_default_config();
	/* Set sampling frequency at 40KHz */
	config.rate = 40000;
	/* Initialize ADC */
	adc_config_init(0, config);
	/* Select ADC channel 0 */
	adc_select_input(0, ADC_CH0);

	while(1) {
		/* Create complex array for FFT analysis */
		for(uint16_t i = 0; i < fftSize; i++) {
			/* Clear odd indexes */
			complexInput[(i * 2) + 1] = 0.0;
			/* Copy values in even indexes */
			complexInput[i * 2] = adc_read(0) * conv_factor;
		}
		/* Process the data through the CFFT/CIFFT module */
		arm_cfft_f32(&s, complexInput, ifftFlag, doBitReverse);
		/* Calculate the magnitude at each bin, it's symmetrical */
		arm_cmplx_mag_f32(complexInput, fftOutput, fftSize);
#ifdef DEBUG
		/* Get max value */
		arm_max_f32(fftOutput, fftSize, &maxValue, &maxIndex);
		/* Print fundamental frequency */
		printf("[%d] : %.2f\r\n", maxIndex, 40000.0 * maxIndex / fftSize);
#endif
		/* Continue if math was successful */
		if (status == ARM_MATH_SUCCESS) {
			/* Wait for host to be connected */
			while(!usb_is_connected());
			/* Send first couple of JSON format characters */
			char str[25] = "{\"values\":[";
			usb_send(str);
#ifdef DEBUG
			/* Print number of samples */
			printf("FFT output with %d samples (symmetric values removed)\r\n", n / 2);
#endif
			/* Get rid of second half */
			uint16_t i;
			for(i = 0; i < fftSize / 2; i++) {
				/* Format string and send except the last one */
				sprintf(str, "%e,", fftOutput[i]);
				usb_send(str);
#ifdef DEBUG
				/* Print a new line every 16 values */
				if(!(i % 16)) { printf("\r\n"); }
				/* Print values */
				printf("%12.6f,", i, fftOutput[i]);
#endif
			}
			/* Send last value with closing JSON format characters */
			sprintf(str, "%e]}", fftOutput[i]);
			usb_send(str);
		}
	}
	return 0;
}

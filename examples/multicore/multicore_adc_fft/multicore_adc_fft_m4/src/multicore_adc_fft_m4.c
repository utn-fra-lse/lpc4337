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
#include "ciaa_usb_api.h"
#include "arm_math.h"

/* Number of ADC samples */
#define N_SAMPLES	512

/* Complex data */
float32_t adcComplex[N_SAMPLES * 2] = { 0.0 };
/* FFT output */
float32_t fftOutput[N_SAMPLES];

/* FFT configuration */
uint32_t fftSize = N_SAMPLES / 2;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;
/* CFFT instance */
arm_cfft_instance_f32 s;

int main(void) {
	/* Initialize ADC buffer */
	uint16_t *adcResults;
	/* Results address */
	uint32_t addr;
	/* ADC conversion factor */
	const float32_t conv_factor = 3.3 / (1 << 10);
	/* Initialize USB */
	usb_init();
	/* IPC quque initialization */
	ipc_queue_init(&addr, sizeof(uint32_t), 1);
	/* ARM math status */
	arm_status status = ARM_MATH_SUCCESS;
	/* Initialize CFFT instance */
	status = arm_cfft_init_f32(&s,fftSize);
    /* Start M0 core */
    multicore_m0_start();

	while(1) {
		/* Try to pop value from IPC */
		if(ipc_try_pop(&addr) == queue_valid) {
			/* Point to address */
			adcResults = (uint16_t*)addr;
			/* Create complex array for FFT analysis */
			for(uint16_t i = 0; i < N_SAMPLES; i++) {
				/* Copy values in even indexes */
				adcComplex[i * 2] = adcResults[i] * conv_factor;
			}
			/* Process the data through the CFFT/CIFFT module */
			arm_cfft_f32(&s, adcComplex, ifftFlag, doBitReverse);
			/* Calculate the magnitude at each bin, it's symmetrical */
			arm_cmplx_mag_f32(adcComplex, fftOutput, fftSize);
			/* Continue if math was successful */
			if (status == ARM_MATH_SUCCESS) {
				/* Wait for host to be connected */
				while(!usb_is_connected());
				/* Get size of FFT result */
				uint16_t n = sizeof(fftOutput) / sizeof(fftOutput[0]);
				/* Send first couple of JSON format characters */
				char str[25] = "{\"values\":[";
				usb_send(str);
#ifdef DEBUG
				/* Print number of samples */
				printf("FFT output with %d samples (symmetric values removed)\r\n", n / 2);
#endif
				/* Get rid of second half */
				uint16_t i;
				for(i = 0; i < n / 2; i++) {
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
	}
	return 0;
}

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
#define MAX_SAMPLES	256

/**
 * @brief Struct to hold shared data between cores
 */
typedef struct {
	uint16_t size;		/* Size of real samples */
	uint8_t nclocks;	/* Number of clocks that the conversion takes */
	float *samples;		/* Pointer to samples */
} data_t;

/* FFT output */
float32_t fftOutput[MAX_SAMPLES];

/* FFT configuration */
uint32_t fftSize = MAX_SAMPLES;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;
/* CFFT instance */
arm_cfft_instance_f32 s;

int main(void) {
	/* Initialize ADC buffer */
	float32_t *complexInput;
	/* Results address */
	uint32_t addr;
	/* Number of ADC clocks to finish conversion */
	uint8_t nclocks;
	/* Initialize USB */
	usb_init();
	/* IPC quque initialization */
	ipc_queue_init(&addr, sizeof(uint32_t), 1);
	/* ARM math status */
	arm_status status = ARM_MATH_SUCCESS;
	/* Initialize CFFT instance */
	status = arm_cfft_init_f32(&s, fftSize);
    /* Start M0 core */
    multicore_m0_start();

	while(1) {
		/* Try to pop value from IPC */
		if(ipc_try_pop(&addr) == queue_valid) {
			/* Point to samples address */
			complexInput = (float32_t*)( ((data_t*) addr)->samples );
			/* Get number of samples */
			fftSize = ((data_t*) addr)->size;
			/* Get number of clocks that takes the ADC to finish */
			nclocks = ((data_t*) addr)->nclocks;
			/* Reinitialize CFFT instance if sizes don't match */
			if(s.fftLen != fftSize) { arm_cfft_init_f32(&s, fftSize); }
			/* Process the data through the CFFT/CIFFT module */
			arm_cfft_f32(&s, complexInput, ifftFlag, doBitReverse);
			/* Calculate the magnitude at each bin, it's symmetrical */
			arm_cmplx_mag_f32(complexInput, fftOutput, fftSize);
			/* Continue if math was successful */
			if (status == ARM_MATH_SUCCESS) {
				/* Wait for host to be connected */
				while(!usb_is_connected());
				/* Send first couple of JSON format characters */
				char str[40];
				sprintf(str, "{\"size\":%d,\"nclocks\":%d,\"values\":[", fftSize, nclocks);
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
	}
	return 0;
}

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

void json_dumps(char *json, const char *key, float32_t *values, uint32_t size) {

	float32_t *ptr = values;
	sprintf(json, "{\n\t%s:[", key);
	while(size--) {
		char str[25];
		sprintf(str, "%f,", *ptr);
		strcat(json, str);
		ptr++;
	}
	json[strlen(json) - 1] = ']';
	strcat(json, "\n}");
}

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Initialize USB0 with default configuration */
	usb_init();
	/* RFFT result goes here */
	float32_t outputSignal[FFT_SAMPLES];
	/* Initialize RFFT instance */
	arm_status status = arm_rfft_fast_init_f32(&S, FFT_SAMPLES);

	char json[4096];

	if(status == ARM_MATH_SUCCESS) {
		/* Continue if initialization was a success */
		arm_rfft_fast_f32(&S, testInput_f32_1khz, outputSignal, 0);

		json_dumps(json, "values", outputSignal, sizeof(outputSignal) / sizeof(float32_t));

		while(1) {
			usb_send(json);
			sleep_ms(1000);
		}
	}

	return 0;
}

/*
===============================================================================
 Name        : multicore_adc_basic_m0app.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_adc_api.h"
#include "ciaa_ipc_api.h"

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Get ADC configuration */
	adc_config_t adc_config = adc_get_default_config();
	/* Configure ADC */
	adc_config_init(0, adc_config);
	/* Select ADC channel */
	adc_select_input(0, ADC_CH0);
	/* ADC value variable */
	uint16_t adc_value;
	/* Initialize IPC queue */
	ipc_queue_init(&adc_value, sizeof(uint16_t), 1);

	while(1) {
		/* Read ADC value */
		adc_value = adc_read(0);
		/* Send data to other core */
		ipc_try_push(&adc_value);
	}

	return 0;
}

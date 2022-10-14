/*
===============================================================================
 Name        : adc_burst.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_adc_api.h"

bool conversion_done = false;
uint16_t result;

void adc_conversion_done(void) {

	result = adc_read(0);
	conversion_done = true;
}

int main(void) {

	adc_config_t config = adc_get_default_config();
	config.burstMode = ENABLE;
	config.interrupt = ENABLE;

	adc_config_init(0, config);

	adc_select_input(0, ADC_CH0);

	adc_set_irq_handler(0, adc_conversion_done);
	adc_set_irq_channel_enabled(0, ADC_CH0, true);

	while(1) {

		if(conversion_done) {
			printf("%d\r\n", result);
			conversion_done = false;
		}

	}
}

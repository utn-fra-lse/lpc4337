/*
===============================================================================
 Name        : adc_burst.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef DEBUG
#include <stdio.h>
#endif

#include "ciaa_adc_api.h"

/* ADC conversion flag */
bool conversion_done = false;
/* ADC result */
uint16_t result;
/* ADC conversion factor */
const float conversion_factor = 3.3 / (1 << 10);

/**
 * @brief ADC interrupt handler
 */
void adc_conversion_done(void) {
	/* Get ADC value (10 bits) */
	result = adc_read(0);
	/* Change flag value */
	conversion_done = true;
}

int main(void) {
	/* Update system core clock */
	SystemCoreClockUpdate();
	/* Get ADC defau;t configuration */
	adc_config_t config = adc_get_default_config();
	/* Enable burst mode */
	config.burstMode = ENABLE;
	/* Enable interrupt */
	config.interrupt = ENABLE;
	/* Takes four clocks to finish conversion (1MS/s) */
	config.bitsAccuracy = adc_3bits;
	/* Initialize ADC0 with said configuration */
	adc_config_init(0, config);
	/* Select channel 0 */
	adc_select_input(0, ADC_CH0);
	/* Set interrupt handler */
	adc_set_irq_handler(0, adc_conversion_done);
	/* Enable interrupt on channel 0 */
	adc_set_irq_channel_enabled(0, ADC_CH0, true);

	while(1) {
		/* Wait for conversion to be ready */
		if(conversion_done) {
#ifdef DEBUG
			printf("Raw: %d | Voltage: %.2f V\r\n", result, result * conversion_factor);
#endif
			/* Change flag status */
			conversion_done = false;
		}

	}
}

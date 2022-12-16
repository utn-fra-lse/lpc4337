/*
===============================================================================
 Name        : multicore_adc_basic_m4.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_board_api.h"
#include "ciaa_ipc_api.h"

#define FIRST_THRESHOLD		0x3ff / 4
#define SECOND_THRESHOLD	0x3ff / 2
#define THIRD_THRESHOLD		3 * 0x3ff / 4

int main(void) {
	/* Initialize CIAA board */
	ciaa_board_init();
	/* Start M0 core */
	multicore_m0_start();
	/* To store ADC value */
	uint16_t adc_value = 0;
	/* Initialize IPC queue */
	ipc_queue_init(&adc_value, sizeof(uint16_t), 1);

	while(1) {
		/* Try to get data from M0 */
		ipc_try_pop(&adc_value);
		/* Compare values and turn on LEDs */
		if(adc_value < FIRST_THRESHOLD) {
			/* Turn off LEDs */
			gpio_clr(LED1);
			gpio_clr(LED2);
			gpio_clr(LED3);
		}
		else if(adc_value < SECOND_THRESHOLD) {
			/* Turn on LED1 */
			gpio_set(LED1);
			/* Turn off LED2 and LED3 */
			gpio_clr(LED2);
			gpio_clr(LED3);
		}
		else if(adc_value < THIRD_THRESHOLD) {
			/* Turn on LED1 and LED2 */
			gpio_set(LED1);
			gpio_set(LED2);
			/* Turn on LED3 */
			gpio_clr(LED3);
		}
		else {
			/* Turn on LEDs */
			gpio_set(LED1);
			gpio_set(LED2);
			gpio_set(LED3);
		}
		/* Print in console */
		printf("ADC value: %d\r\n", adc_value);
	}

	return 0;
}

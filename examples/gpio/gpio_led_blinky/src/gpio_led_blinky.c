/*
===============================================================================
 Name        : gpio_led_blinky.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_gpio_api.h"
#include "ciaa_stdlib.h"

int main(void) {
	/* Update System Clocl */
	SystemCoreClockUpdate();
	/* Set LED1 pin as output */
	gpio_set_dir(LED1, true);

	while(1) {
		/* Toggle LED */
		gpio_xor(LED1);
		/* Wait for 1 second */
		sleep_ms(1000);
	}
	return 0;
}


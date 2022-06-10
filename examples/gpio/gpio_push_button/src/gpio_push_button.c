/*
===============================================================================
 Name        : gpio_push_button.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_gpio_api.h"
#include "ciaa_stdlib.h"

int main(void) {
	/* Pin array */
	pin_t pins[] = { LEDR, LEDG, LEDB, TEC1, TEC2, TEC3 };
    /* Read clock settings and update SystemCoreClock variable */
	SystemCoreClockUpdate();
	/* Go through pins */
	for(uint8_t i = 0; i < 3; i++) {
		/* Set pin as output */
		gpio_set_dir_out(pins[i]);
		/* Set pin to low */
		gpio_put(pins[i], false);
		/* Set pin as input */
		gpio_set_dir_in(pins[i + 3]);
	}

	while(1) {
		/* Turn on LEDs when button is pushed */
    	for(uint8_t i = 0; i < 3; i++) { gpio_put(pins[i], !gpio_get(pins[i + 3])); }

    }
    return 0 ;
}

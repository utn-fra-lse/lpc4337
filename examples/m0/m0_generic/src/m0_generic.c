/*
===============================================================================
 Name        : m0_generic.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_gpio_api.h"

int main(void) {

	gpio_set_dir(LED3, true);

	while(1) {

		for(uint32_t i = 0; i < 1000000; i++);
		gpio_xor(LED3);
	}
	return 0;
}

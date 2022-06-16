/*
===============================================================================
 Name        : usb_echo.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_usb_api.h"
#include "ciaa_stdlib.h"

int main(void) {
	/* Char array to store data */
	char str[50];
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Initialize USB0 with default configuration */
	usb_init();

	while(1) {
		/* Check if host is connected */
		if(usb_is_connected()) {
			/* Read up to 50 bytes and store them */
			usb_read(str, 50);
			/* Send back to host */
			usb_send(str);
			/* Wait for 500 ms */
			sleep_ms(500);
		}
	}
	return 0;
}

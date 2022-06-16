/*
===============================================================================
 Name        : usb_hello_world.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_usb_api.h"
#include "ciaa_stdlib.h"

int main(void) {
	/* String to send */
	char *str = "Hello world!\r\n";
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Initialize USB0 with default configuration */
	usb_init();

	while(1) {
		/* Check if host is connected */
		if(usb_is_connected()) {
			/* Send string to host */
			usb_send(str);
			/* Wait for 500 ms */
			sleep_ms(500);
		}
    }
    return 0 ;
}

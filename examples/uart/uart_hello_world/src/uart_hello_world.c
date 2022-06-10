/*
===============================================================================
 Name        : usart_hello_world.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include <ciaa_uart_api.h>
#include "ciaa_stdlib.h"

int main(void) {
    /* Read clock settings and update SystemCoreClock variable */
    SystemCoreClockUpdate();
    /* Initialize USART0 with default configuration */
    uart_init(UART_0);

    while(1) {
    	/* Send string through USART0 */
    	uart_puts(UART_0, "Hello world!\r\n");
    	/* Wait for 1 second */
    	sleep_ms(1000);
    }
    return 0 ;
}

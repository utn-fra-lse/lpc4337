/*
===============================================================================
 Name        : uart_echo.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_uart_api.h"

int main(void) {
    /* Variable to store string */
    char str[50];
    /* Read clock settings and update SystemCoreClock variable */
    SystemCoreClockUpdate();
    /* Initialize UART0 with default configuration */
    uart_init(UART_0);

    while(1) {
    	/* Read string from UART */
    	uart_gets(UART_0, str);
    	/* Write string back */
    	uart_puts(UART_0, str);
    }
    return 0 ;
}

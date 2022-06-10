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
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();

    uart_init(UART_0);

    char str[50];

    while(1) {

    	uart_gets(UART_0, str);
    	uart_puts(UART_0, str);
    }
    return 0 ;
}

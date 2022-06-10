/*
===============================================================================
 Name        : uart_rx_irq.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_uart_api.h"

/* Rx data ready interrupt handler */
void rx_handler(void) {
	/* Echoes the received char back to the console */
	uart_putc(UART_0, uart_getc(UART_0));
}

int main(void) {
    /* Read clock settings and update SystemCoreClock variable */
    SystemCoreClockUpdate();
    /* Enable UART0 with default configuration */
    uart_init(UART_0);
    /* Enable RX interrupt */
    uart_set_rx_irq_enabled(UART_0, true);
    /* Set an interrupt handler for the RX data ready */
    uart_set_rx_handler(UART_0, rx_handler);

    while(1);

    return 0 ;
}

/*
 * ciaa_uart_api.c
 *
 *  Created on: Jun 9, 2022
 *      Author: fabri
 */

#include <ciaa_uart_api.h>

LPC_USART_T *CIAA_UARTS[] = { CIAA_UART0, CIAA_UART1, CIAA_UART2, CIAA_UART3 };

static const CHIP_CCU_CLK_T CIAA_UART_CLKS[] = { CLK_MX_UART0, CLK_MX_UART1, CLK_MX_UART2, CLK_MX_UART3 };

uart_config_t UART_DEFAULT_CONFIGS[] = {
	{ UART_0, 115200, UART_STOP_BITS_1, UART_PARITY_DISABLE, UART_WORD_LENGTH_8, &GPIO1, &GPIO2 },
	{ UART_1, 115200, UART_STOP_BITS_1, UART_PARITY_DISABLE, UART_WORD_LENGTH_8, NULL, NULL },
	{ UART_2, 115200, UART_STOP_BITS_1, UART_PARITY_DISABLE, UART_WORD_LENGTH_8, &RXD0, &CRS_DV },
	{ UART_3, 115200, UART_STOP_BITS_1, UART_PARITY_DISABLE, UART_WORD_LENGTH_8, &RS485_TXD, &RS485_RXD }
};

void uart_init(ciaa_uart_t uart) {
	/* Get default UART configuration and initialize */
	uart_config_init(uart_get_default_config(uart));
}

void uart_config_init(uart_config_t config) {
	/* Get base register */
	LPC_USART_T *reg = uart_get_base_register(config.uart);
	/* Select TX pin */
	uart_set_tx_pin(config.uart, config.txPin);
	/* Select RX pin */
	uart_set_rx_pin(config.uart, config.rxPin);
	/* Enable UART clocking. UART base clock(s) must already be enabled */
	Chip_Clock_EnableOpts(CIAA_UART_CLKS[config.uart], true, true, 1);
	/* Enable FIFOs by default, reset them */
	uart_setup_fifos(config.uart);
    /* Disable Tx pin */
	uart_set_tx_enabled(config.uart, false);
    /* Disable interrupts */
	reg->IER = 0;
	/* Set LCR to default state */
	reg->LCR = 0;
	/* Set ACR to default state */
	reg->ACR = 0;
    /* Set RS485 control to default state */
	reg->RS485CTRL = 0;
	/* Set RS485 delay timer to default state */
	reg->RS485DLY = 0;
	/* Set RS485 addr match to default state */
	reg->RS485ADRMATCH = 0;
    /* Clear MCR */
    if (reg == CIAA_UART1) {
		/* Set Modem Control to default state */
		reg->MCR = 0;
		/* Configure USART */
	    volatile uint32_t tmp;
		/*Dummy Reading to Clear Status */
		tmp = reg->MSR;
	}
	/* Default 8N1, with DLAB disabled */
    uart_set_config_value(config);
	/* Disable fractional divider */
	reg->FDR = 0x10;
	/* Set USART baud rate */
	uart_set_baud_rate(config.uart, config.baudRate);
	/* Enable TX pin */
	uart_set_tx_enabled(config.uart, true);
}

void uart_set_baud_rate(ciaa_uart_t usart, uint32_t baudRate) {
	/* Get USART base register */
	LPC_USART_T *reg = uart_get_base_register(usart);
	/* Clock divider variables */
	uint32_t div, divh, divl, clkin;
	/* Determine UART clock in rate without FDR */
	clkin = Chip_Clock_GetRate(CIAA_UART_CLKS[usart]);
	div = clkin / (baudRate * 16);
	/* High and low halves of the divider */
	divh = div / 256;
	divl = div - (divh * 256);
	/* Enable divisor access */
	reg->LCR |= UART_LCR_DLAB_EN;
	/* Set divisor latches */
	reg->DLL = divl;
	reg->DLM = divh;
	/* Disable divisor access */
	reg->LCR &= ~UART_LCR_DLAB_EN;
}

void uart_puts(ciaa_uart_t uart, const char* str) {
	/* Loop until null character */
	while(*str) {
		/* Wait until the transmit holding register is empty */
		while ( !uart_is_writable(uart) );
		/* Send byte */
		uart_putc(uart, *str++);
	}
}

void uart_gets(ciaa_uart_t uart, char *str) {

	uint8_t size = 0;
	while(*str) {
		*str = '\0';
		size++;
		str++;
	}
	str = (str - size);

	while(!uart_is_readable(uart));

	while(uart_is_readable(uart)) {
		*str = uart_getc(uart);
		str++;
	}
}

/*
===============================================================================
 Name        : gpio_group.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_board_api.h"

/* Function prototype */
void ggpio_handler(void);

/**
 * @brief main program
 */
int main(void) {
	/* Initialize CIAA board */
	ciaa_board_init();
	/* Select pins to use */
	ggpio_attach_pin(0, TEC1, falling_edge);
	ggpio_attach_pin(0, TEC2, falling_edge);
	ggpio_attach_pin(0, TEC3, falling_edge);
	ggpio_attach_pin(0, TEC4, falling_edge);
	/* Enable interrupt */
	ggpio_enable(0, or_mode, ggpio_handler);

	while(1);

	return 0;
}

/**
 * @brief Group GPIO interrupt
 */
void ggpio_handler(void) { gpio_xor(LEDB); }


/*
===============================================================================
 Name        : gpio_pint.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_board_api.h"
#include "ciaa_pint_api.h"

/* Function prototypes */
void pint0_handler(void);
void pint1_handler(void);
void pint2_handler(void);
void pint3_handler(void);

/**
 * @brief main program
 */
int main(void) {
	/* Enable CIAA board */
	ciaa_board_init();
	/* Enable PINT0 for TEC1 */
	pint_enable(TEC1, rising_edge, 0, pint0_handler);
	/* Enable PINT1 for TEC2 */
	pint_enable(TEC2, rising_edge, 1, pint1_handler);
	/* Enable PINT2 for TEC3 */
	pint_enable(TEC3, rising_edge, 2, pint2_handler);
	/* Enable PINT3 for TEC4 */
	pint_enable(TEC4, rising_edge, 3, pint3_handler);

	while(1);

	return 0;
}

/**
 * @brief PINT0 interrupt handler
 */
void pint0_handler(void) { gpio_xor(LEDB); }

/**
 * @brief PINT1 interrupt handler
 */
void pint1_handler(void) { gpio_xor(LED1); }

/**
 * @brief PINT2 interrupt handler
 */
void pint2_handler(void) { gpio_xor(LED2); }

/**
 * @brief PINT3 interrupt handler
 */
void pint3_handler(void) { gpio_xor(LED3); }

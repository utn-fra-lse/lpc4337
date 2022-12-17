/*
 * ciaa_gpio_api.h
 *
 *  Created on: Jun 2, 2022
 *      Author: fabri
 */

#ifndef CIAA_GPIO_API_H_
#define CIAA_GPIO_API_H_

#include "chip.h"
#include "ciaa_scu_api.h"

/* Definitions */
#define CIAA_GPIO	LPC_GPIO_PORT

#define OFF		false
#define ON		true

#define LOW		false
#define HIGH	true

#define INPUT	false
#define OUTPUT	true

/**
 * @brief Pin struct definition
 */
typedef struct {
	uint8_t SCU_PORT;				/* GPIO PORT number for SCU */
	uint8_t SCU_PIN;				/* GPIO PIN number for SCU */
	uint8_t GPIO_PORT;				/* GPIO PORT to read/write */
	uint8_t GPIO_PIN;				/* GPIO PIN to read/write */
	scu_pin_functions_t *FUNCTIONS;	/* SCU functions for the PIN */
} pin_t;

/**
 * @brief Pin interrupt modes
 */
typedef enum {
	rising_edge = 0x00,				/* Rising edge */
	falling_edge = 0x01,			/* Falling edge */
	high_level = 0x02,				/* High level */
	low_level = 0x03				/* Low level */
} pint_mode_t;

/* Pin declarations */
extern pin_t LEDR;
extern pin_t LEDG;
extern pin_t LEDB;
extern pin_t LED1;
extern pin_t LED2;
extern pin_t LED3;

extern pin_t TEC1;
extern pin_t TEC2;
extern pin_t TEC3;
extern pin_t TEC4;

extern pin_t GPIO0;
extern pin_t GPIO1;
extern pin_t GPIO2;
extern pin_t GPIO3;
extern pin_t GPIO4;
extern pin_t GPIO5;
extern pin_t GPIO6;
extern pin_t GPIO7;
extern pin_t GPIO8;

extern pin_t TFIL0;
extern pin_t TFIL1;
extern pin_t TFIL2;
extern pin_t TFIL3;

extern pin_t TCOL0;
extern pin_t TCOL1;
extern pin_t TCOL2;

extern pin_t LCD1;
extern pin_t LCD2;
extern pin_t LCD3;
extern pin_t LCD4;
extern pin_t LCD_RS;
extern pin_t LCD_EN;

extern pin_t RXD1;
extern pin_t TX_EN;
extern pin_t RXD0;
extern pin_t CRS_DV;
extern pin_t MDIO;
extern pin_t TXD0;
extern pin_t TXD1;
extern pin_t MDC;

extern pin_t RS232_TXD;
extern pin_t RS232_RXD;

extern pin_t RS485_DIR;
extern pin_t RS485_TXD;
extern pin_t RS485_RXD;

extern pin_t CAN_RD;
extern pin_t CAN_TD;

extern pin_t SPI_MISO;
extern pin_t SPI_MOSI;

/* PINT handlers */
extern void (*pint_handlers[8])(void);

/* Function prototypes */

/**
 * @brief Set GPIO pin direction to input
 * @param pin: struct to the pin
 */
static void inline gpio_set_dir_in(pin_t pin) {
	/* Set pin function */
	scu_set_pin_mode(pin.SCU_PORT, pin.SCU_PIN, SCU_MODE_INACT | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS | pin.FUNCTIONS->GPIO);
	/* Set pin direction */
	CIAA_GPIO->DIR[pin.GPIO_PORT] &= ~(1UL << pin.GPIO_PIN);
}

/**
 * @brief Set GPIO pin direction to output
 * @param pin: struct to the pin
 */
static void inline gpio_set_dir_out(pin_t pin) {
	/* Set pin function */
	scu_set_pin_mode(pin.SCU_PORT, pin.SCU_PIN, SCU_MODE_INACT | SCU_MODE_ZIF_DIS | SCU_MODE_INBUFF_EN | pin.FUNCTIONS->GPIO);
	/* Set pin direction */
	CIAA_GPIO->DIR[pin.GPIO_PORT] |= 1UL << pin.GPIO_PIN;
}

/**
 * @brief Set GPIO pin direction
 * @param pin: struct to the pin
 * @param dir: direction of the pin:
 * 		- false for input
 * 		- true for output
 */
static void inline gpio_set_dir(pin_t pin, bool dir) {
	/* Check direction and set */
	if (dir) { gpio_set_dir_out(pin); }
	else { gpio_set_dir_in(pin); }
}

/**
 * @brief Set GPIO pin output value
 * @param pin: struct to the pin to initialize
 * @param value: output value:
 * 		- false for low
 * 		- true for high
 */
static void inline gpio_put(pin_t pin, bool value) { CIAA_GPIO->B[pin.GPIO_PORT][pin.GPIO_PIN] = value; }

/**
 * @brief Set GPIO pin output value to high
 * @param pin: struct to the pin to initialize
 */
static void inline gpio_set(pin_t pin) { CIAA_GPIO->SET[pin.GPIO_PORT] = (1 << pin.GPIO_PIN); }

/**
 * @brief Set GPIO pin output value to low
 * @param pin: struct to the pin to initialize
 */
static void inline gpio_clr(pin_t pin) { CIAA_GPIO->CLR[pin.GPIO_PORT] = (1 << pin.GPIO_PIN); }

/**
 * @brief Toggle GPIO pin output value
 * @param pin: struct to the pin to initialize
 */
static void inline gpio_xor(pin_t pin) { CIAA_GPIO->NOT[pin.GPIO_PORT] = (1 << pin.GPIO_PIN); }

/**
 * @brief Get GPIO pin value
 * @param pin: struct to the pin to initialize
 * @return pin value:
 * 		- false for low
 * 		- true for high
 */
static bool inline gpio_get(pin_t pin) { return (bool) CIAA_GPIO->B[pin.GPIO_PORT][pin.GPIO_PIN]; }

/**
 * @brief Clear interrupt status on selected PINT channel
 * @param pint_channel: PINT channel number (0 - 7)
 */
static void inline pint_clear_status(uint8_t pint_channel) { LPC_GPIO_PIN_INT->IST = PININTCH(pint_channel); }

/**
 * @brief Set PINT interrupt mode to rising edge
 * @param pint_channel: PINT channel number (0 -7)
 */
static void inline pint_set_mode_rising_edge(uint8_t pint_channel) {
	/* Enable edge mode */
	LPC_GPIO_PIN_INT->ISEL &= ~PININTCH(pint_channel);
	/* Enable high mode */
	LPC_GPIO_PIN_INT->SIENR |= PININTCH(pint_channel);
}

/**
 * @brief Set PINT interrupt mode to falling edge
 * @param pint_channel: PINT channel number (0 - 7)
 */
static void inline pint_set_mode_falling_edge(uint8_t pint_channel) {
	/* Enable edge mode */
	LPC_GPIO_PIN_INT->ISEL &= ~PININTCH(pint_channel);
	/* Enable low mode */
	LPC_GPIO_PIN_INT->SIENF |= PININTCH(pint_channel);
}

/**
 * @brief Set PINT interrupt mode to level high
 * @param pint_channel: PINT channel number (0 - 7)
 */
static void inline pint_set_mode_level_high(uint8_t pint_channel) {
	/* Enable level mode */
	LPC_GPIO_PIN_INT->ISEL |= PININTCH(pint_channel);
	/* Enable high mode */
	LPC_GPIO_PIN_INT->SIENR |= PININTCH(pint_channel);
}

/**
 * @brief Set PINT interrupt mode to level low
 * @param pint_channel: PINT channel number (0 - 7)
 */
static void inline pint_set_mode_level_low(uint8_t pint_channel) {
	/* Enable level mode */
	LPC_GPIO_PIN_INT->ISEL |= PININTCH(pint_channel);
	/* Enable low mode */
	LPC_GPIO_PIN_INT->SIENF |= PININTCH(pint_channel);
}

/**
 * @brief Choose PINT mode
 * @param pint_channel: PINT channel (0 - 7)
 * @param mode: interrupt trigger type (rising_edge, falling_edge, high_level, low_level)
 */
static void inline pint_set_mode(uint8_t pint_channel, pint_mode_t mode) {
	/* Check mode and enable */
	if(mode == rising_edge) { pint_set_mode_rising_edge(pint_channel); }
	else if(mode == falling_edge) { pint_set_mode_falling_edge(pint_channel); }
	else if(mode == high_level) { pint_set_mode_level_high(pint_channel); }
	else { pint_set_mode_level_low(pint_channel); }
}

/**
 * @brief Enable pin interrupt for a specified pin
 * @param mode: interrupt trigger type (rising_edge, falling_edge, high_level, low_level)
 * @param pint_channel: PINT channel (0 - 7)
 * @param handler: function handler
 */
static void inline pint_enable(pin_t pin, pint_mode_t mode, uint8_t pint_channel, void (*handler)(void)) {
	/* PINT interrupts */
	LPC43XX_IRQn_Type irqs[8] = {
			PIN_INT0_IRQn, PIN_INT1_IRQn, PIN_INT2_IRQn, PIN_INT3_IRQn,
			PIN_INT4_IRQn, PIN_INT5_IRQn, PIN_INT6_IRQn, PIN_INT7_IRQn
	};
	/* Map GPIO to PINT */
	scu_gpio_pint_select(pint_channel, pin.GPIO_PORT, pin.GPIO_PIN);
	/* Clear pending status */
	pint_clear_status(pint_channel);
	/* Select mode */
	pint_set_mode(pint_channel, mode);
	/* Attach interrupt */
	pint_handlers[pint_channel] = handler;
	/* Enable interrupt in the NVIC */
	NVIC_ClearPendingIRQ(irqs[pint_channel]);
	NVIC_EnableIRQ(irqs[pint_channel]);

}

#endif /* CIAA_GPIO_API_H_ */

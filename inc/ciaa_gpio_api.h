/*
 * EDU_CIAA.h
 *
 *  Created on: Jun 2, 2022
 *      Author: fabri
 */

#ifndef CIAA_GPIO_API_H_
#define CIAA_GPIO_API_H_

#include "chip.h"

/* Definitions */
#define CIAA_GPIO	LPC_GPIO_PORT
#define CIAA_SCU	LPC_SCU

#define OFF		false
#define ON		true

#define LOW		false
#define HIGH	true

#define INPUT	false
#define OUTPUT	true

/* Pin struct definition */
typedef struct {
	uint8_t SCU_PORT;
	uint8_t SCU_PIN;
	uint8_t GPIO_PORT;
	uint8_t GPIO_PIN;
} pin_t;

/* Pin declarations */
extern const pin_t LEDR;
extern const pin_t LEDG;
extern const pin_t LEDB;
extern const pin_t LED1;
extern const pin_t LED2;
extern const pin_t LED3;

/* Function prototypes */

/**
 * @brief	initialize GPIO pin
 *
 * @param	pin: struct to the pin
 *
 * @return	None
 */
static void inline gpio_init(pin_t pin) { CIAA_SCU->SFSP[pin.SCU_PORT][pin.SCU_PIN] = (SCU_MODE_INACT | SCU_MODE_ZIF_DIS | SCU_MODE_INBUFF_EN); }

/**
 * @brief	set GPIO pin direction
 *
 * @param	pin: struct to the pin
 * @param	dir: direction of the pin:
 * 		- false for input
 * 		- true for output
 *
 * @return	None
 */
static void inline gpio_set_dir(pin_t pin, bool dir) {

	if (dir) {
		CIAA_GPIO->DIR[pin.GPIO_PORT] |= 1UL << pin.GPIO_PIN;
	}
	else {
		CIAA_GPIO->DIR[pin.GPIO_PORT] &= ~(1UL << pin.GPIO_PIN);
	}
}

/**
 * @brief	set GPIO pin direction to input
 *
 * @param	pin: struct to the pin
 *
 * @return	None
 */
static void inline gpio_set_dir_in(pin_t pin) { CIAA_GPIO->DIR[pin.GPIO_PORT] &= ~(1UL << pin.GPIO_PIN); }

/**
 * @brief	set GPIO pin direction to output
 *
 * @param	pin: struct to the pin
 *
 * @return	None
 */
static void inline gpio_set_dir_out(pin_t pin) { CIAA_GPIO->DIR[pin.GPIO_PORT] |= 1UL << pin.GPIO_PIN; }

/**
 * @brief	set GPIO pin output value
 *
 * @param	pin: struct to the pin to initialize
 * @param	value: output value:
 * 		- false for low
 * 		- true for high
 *
 * @return	None
 */
static void inline gpio_put(pin_t pin, bool value) { CIAA_GPIO->B[pin.GPIO_PORT][pin.GPIO_PIN] = value; }

/**
 * @brief	set GPIO pin output value to high
 *
 * @param	pin: struct to the pin to initialize
 *
 * @return	None
 */
static void inline gpio_set(pin_t pin) { CIAA_GPIO->SET[pin.GPIO_PORT] = (1 << pin.GPIO_PIN); }

/**
 * @brief	set GPIO pin output value to low
 *
 * @param	pin: struct to the pin to initialize
 *
 * @return	None
 */
static void inline gpio_clr(pin_t pin) { CIAA_GPIO->CLR[pin.GPIO_PORT] = (1 << pin.GPIO_PIN); }

/**
 * @brief	toggle GPIO pin output value
 *
 * @param	pin: struct to the pin to initialize
 *
 * @return	None
 */
static void inline gpio_xor(pin_t pin) { CIAA_GPIO->NOT[pin.GPIO_PORT] = (1 << pin.GPIO_PIN); }

/**
 * @brief	get GPIO pin value
 *
 * @param	pin: struct to the pin to initialize
 *
 * @return	pin value:
 * 		- false for low
 * 		- true for high
 */
static bool inline gpio_get(pin_t pin) { return (bool) CIAA_GPIO->B[pin.GPIO_PORT][pin.GPIO_PIN]; }

#endif /* CIAA_GPIO_API_H_ */

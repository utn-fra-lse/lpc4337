/*
 * ciaa_scu_api.h
 *
 *  Created on: Jun 6, 2022
 *      Author: fabri
 */

#ifndef CIAA_SCU_API_H_
#define CIAA_SCU_API_H_

#include "chip.h"

#define CIAA_SCU	LPC_SCU

#define SCU_MODE_PULLUP            (0x0 << 3)		/* Enable pull-up resistor at pad */
#define SCU_MODE_REPEATER          (0x1 << 3)		/* Enable pull-down and pull-up resistor at resistor at pad (repeater mode) */
#define SCU_MODE_INACT             (0x2 << 3)		/* Disable pull-down and pull-up resistor at resistor at pad */
#define SCU_MODE_PULLDOWN          (0x3 << 3)		/* Enable pull-down resistor at pad */
#define SCU_MODE_HIGHSPEEDSLEW_EN  (0x1 << 5)		/* Enable high-speed slew */
#define SCU_MODE_INBUFF_EN         (0x1 << 6)		/* Enable Input buffer */
#define SCU_MODE_ZIF_DIS           (0x1 << 7)		/* Disable input glitch filter */
#define SCU_MODE_4MA_DRIVESTR      (0x0 << 8)		/* Normal drive: 4mA drive strength */
#define SCU_MODE_8MA_DRIVESTR      (0x1 << 8)		/* Medium drive: 8mA drive strength */
#define SCU_MODE_14MA_DRIVESTR     (0x2 << 8)		/* High drive: 14mA drive strength */
#define SCU_MODE_20MA_DRIVESTR     (0x3 << 8)		/* Ultra high- drive: 20mA drive strength */
#define SCU_MODE_FUNC0             0x0				/* Selects pin function 0 */
#define SCU_MODE_FUNC1             0x1				/* Selects pin function 1 */
#define SCU_MODE_FUNC2             0x2				/* Selects pin function 2 */
#define SCU_MODE_FUNC3             0x3				/* Selects pin function 3 */
#define SCU_MODE_FUNC4             0x4				/* Selects pin function 4 */
#define SCU_MODE_FUNC5             0x5				/* Selects pin function 5 */
#define SCU_MODE_FUNC6             0x6				/* Selects pin function 6 */
#define SCU_MODE_FUNC7             0x7				/* Selects pin function 7 */
#define SCU_PINIO_FAST             (SCU_MODE_INACT | SCU_MODE_HIGHSPEEDSLEW_EN | SCU_MODE_INBUFF_EN | SCU_MODE_ZIF_DIS)
/* Pin configuration for STANDARD/FAST mode I2C */
#define I2C0_STANDARD_FAST_MODE		(1 << 3 | 1 << 11)
/* Pin configuration for Fast-mode Plus I2C */
#define I2C0_FAST_MODE_PLUS			(2 << 1 | 1 << 3 | 1 << 7 | 1 << 10 | 1 << 11)

/*
 *	@brief	Sets IO control pin mux
 *
 *	@param	scu_port: SCU PORT of the GPIO
 *	@param	scu_pin: SCU PIN of the GPIO
 *	@param	mode: function to set to the pin
 *
 *	@return	None
 */
static inline void scu_set_pin_mode(uint8_t scu_port,  uint8_t scu_pin, uint16_t mode) { CIAA_SCU->SFSP[scu_port][scu_pin] = mode; }

/*
 *	@brief	I2C0 configuration
 *
 *	@param	mode: I2C0 mode. Should be:
 *		- I2C0_STANDARD_FAST_MODE
 *		- I2C0_FAST_MODE_PLUS
 *
 *	@return	None
 */
static inline void scu_i2c0_config(uint32_t mode) { CIAA_SCU->SFSI2C0 = mode; }

/*
 *	@brief	Configure ADC channel
 *
 *	@param	adc: ADC number
 *	@param	channel: one of the 8 available ADC channels
 *
 *	@return	None
 */
static inline void scu_adc_channel_config(uint8_t adc, uint8_t channel) { CIAA_SCU->ENAIO[adc] |= 1UL << channel; }

/*
 *	@brief	Enable/Disable DAC output on P4_4
 *
 *	@param	enabled: whether to enable or disable the DAC output
 *
 *	@param	None
 */
static inline void scu_dac_config(bool enabled) {
	/* Clear ENAIO bit that enables P4_4 DAC output */
	CIAA_SCU->ENAIO[2] &= ~1;
	/* Set bit if the output in P4_4 is required */
	if(enabled) { CIAA_SCU->ENAIO[2] |= 1; }
}

#endif /* CIAA_SCU_API_H_ */

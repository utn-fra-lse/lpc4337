/*
 * ciaa_pwm_api.c
 *
 *  Created on: Jun 5, 2022
 *      Author: fabri
 */

#include "ciaa_pwm_api.h"

pwm_output_t PWM1 = { &LED1, CTOUT_2, 1 };
pwm_output_t PWM2 = { &LED2, CTOUT_5, 2 };
pwm_output_t PWM3 = { &LED3, CTOUT_4, 3 };
pwm_output_t PWM4 = { &GPIO2, CTOUT_6, 4 };
pwm_output_t PWM5 = { &GPIO8, CTOUT_7, 5 };

void pwm_init(void) {
	pwm_config_t config = pwm_get_default_config();
	pwm_config_init(config);
}

void pwm_config_init(pwm_config_t config) {
	/* Enable SCT clock */
	Chip_Clock_EnableOpts(CLK_MX_SCT, true, true, config.clkdiv);
	/* Set frequency */
	pwm_set_frequency(config.frequency);
}

void pwm_set_frequency(uint32_t frequency) {

	uint32_t rate;

	rate = Chip_Clock_GetRate(CLK_MX_SCT) / frequency;;

	/* Stop the SCT before configuration */
	pwm_stop();

	/* Set MATCH0 for max limit */
	CIAA_PWM->REGMODE_L = 0;
	CIAA_PWM->REGMODE_H = 0;
	pwm_set_match(SCT_MATCH_0, 0);
	pwm_set_wrap(rate);
	CIAA_PWM->EVENT[0].CTRL = 1 << 12;
	CIAA_PWM->EVENT[0].STATE = 1;
	CIAA_PWM->LIMIT_L = 1;

	/* Set SCT Counter to count 32-bits and reset to 0 after reaching MATCH0 */
	CIAA_PWM->CONFIG = SCT_CONFIG_32BIT_COUNTER | SCT_CONFIG_AUTOLIMIT_L;
	pwm_start();
}

void pwm_set_output_pin(pwm_output_t output) {

	pwm_stop();
	scu_set_pin_mode(output.pin->SCU_PORT, output.pin->SCU_PIN, (SCU_MODE_INACT | SCU_MODE_FUNC1));
	uint8_t index = output.index;
	uint8_t pin = output.pwm;

	CIAA_PWM->EVENT[pin].CTRL = pin | (1 << 12);
	CIAA_PWM->EVENT[pin].STATE = 1;
	CIAA_PWM->OUT[index].SET = 1;
	CIAA_PWM->OUT[index].CLR = 1 << pin;

	/* Clear the output in-case of conflict */
	CIAA_PWM->RES = (CIAA_PWM->RES & ~(3 << (index << 1))) | (0x01 << (index << 1));

	/* Set and Clear do not depend on direction */
	CIAA_PWM->OUTPUTDIRCTRL = (CIAA_PWM->OUTPUTDIRCTRL & ~(3 << (index << 1)));
	pwm_start();
}

/*
 * ciaa_dac_api.h
 *
 *  Created on: Jun 4, 2022
 *      Author: fabri
 */

#ifndef CIAA_DAC_API_H_
#define CIAA_DAC_API_H_

#include "chip.h"

#define CIAA_DAC	LPC_DAC

#define DMA_ENA_BIT	3

typedef DAC_CURRENT_OPT_T dac_bias_t;

typedef struct {
	bool enabled;
	uint16_t value;
	dac_bias_t bias;
	bool alternativeOutput;
} dac_config_t;

void dac_init(void);
void dac_config_init(dac_config_t config);


static inline dac_config_t dac_get_default_config(void) {

	dac_config_t config = {
		true,						/* DAC output enabled */
		0x200,						/* DAC output to half */
		DAC_MAX_UPDATE_RATE_1MHz,	/* Bias for max update rate */
		false						/* Output on default pin */
	};
	return config;
}

static inline void dac_set_bias(dac_bias_t bias) {

	CIAA_DAC->CR &= ~DAC_BIAS_EN;

	if (bias == DAC_MAX_UPDATE_RATE_400kHz) {
		CIAA_DAC->CR |= DAC_BIAS_EN;
	}
}

static inline void dac_set_enabled(bool enabled) {

	CIAA_DAC->CTRL &= ~(1 << DMA_ENA_BIT);
	if(enabled) {
		CIAA_DAC->CTRL |= 1 << DMA_ENA_BIT;
	}
}

static inline void dac_set_output_value(uint16_t output) {
	uint32_t tmp;

	tmp = CIAA_DAC->CR & DAC_BIAS_EN;
	tmp |= DAC_VALUE(output);
	/* Update value */
	CIAA_DAC->CR = tmp;
}

static inline void dac_set_alternative_output_enabled(bool enabled) {

	LPC_SCU->ENAIO[2] &= ~1;
	if(enabled) {
		LPC_SCU->ENAIO[2] |= 1;
	}
}

#endif /* CIAA_DAC_API_H_ */

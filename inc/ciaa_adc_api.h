/*
 * ciaa_adc_api.h
 *
 *  Created on: Jun 3, 2022
 *      Author: fabri
 */

#ifndef CIAA_ADC_API_H_
#define CIAA_ADC_API_H_

#include "chip.h"

#define CIAA_ADC0	LPC_ADC0
#define CIAA_ADC1	LPC_ADC1

#define ADC_CHANNELS_MASK	0xff

#define ADC_MAX_CHANNELS	8

#define ADC_FULL_CONV_CLK	11

typedef struct {
	uint32_t rate;			/* ADC rate */
	uint8_t bitsAccuracy;	/* ADC bit accuracy */
	bool burstMode;			/* ADC Burt Mode */
	bool interrupt;			/* ADC Interrupt */
} adc_config_t;

extern void (*handlers[])(void);

/* Prototype functions */
void adc_init(uint8_t adc);
void adc_config_init(uint8_t adc, adc_config_t config);
void adc_set_burst_mode_enabled(uint8_t adc, bool enabled);
void adc_select_input(uint8_t adc, uint8_t channel);
uint8_t adc_get_selected_input(uint8_t adc);
uint16_t adc_read(uint8_t adc);
uint16_t adc_get_conversion_value(uint8_t adc, uint8_t channel);
void adc_set_irq_enabled(uint8_t adc, bool enabled);

/* Inline functions */
static inline LPC_ADC_T* adc_get_base_reg(uint8_t adc) {
	/* Get ADC register */
	return (adc)? CIAA_ADC1 : CIAA_ADC0;
}

static inline adc_config_t adc_get_default_config(void) {
	/* Set up default ADC config */
	adc_config_t config = {
		ADC_MAX_SAMPLE_RATE,	/* 400 kSamples/s */
		ADC_10BITS,				/* Max resolution */
		DISABLE,				/* No burst mode */
		DISABLE					/* No interrupt */
	};
	/* Return configuration */
	return config;
}

static inline void adc_set_start_mode(uint8_t adc, uint8_t start_mode) {
	/* Get ADC register */
	LPC_ADC_T *reg;
	reg = adc_get_base_reg(adc);
	/* Auxiliary variable */
	uint32_t temp;
	/* Clear start mode bits */
	temp = reg->CR & (~ADC_CR_START_MASK);
	/* Set new start mode with rising edge*/
	reg->CR = temp | (ADC_CR_START_MODE_SEL((uint32_t) start_mode)) | ADC_CR_EDGE;
}

static inline void adc_run(uint8_t adc) {
	/* Start conversion */
	adc_set_start_mode(adc, ADC_START_NOW);
}

static inline void adc_set_irq_channel_enabled(uint8_t adc, uint8_t channel, bool enabled) {
	/* Enable/Disable interrupt in the requested channel */
	if (enabled) { adc_get_base_reg(adc)->INTEN |= (1UL << channel); }
	else { adc_get_base_reg(adc)->INTEN &= (~(1UL << channel)); }
}

static inline void adc_set_irq_handler(uint8_t adc, void (*handler)(void)) {
	/* Set interrupt handler */
	handlers[adc] = handler;
}

static inline bool adc_get_conversion_state(uint8_t adc, uint8_t channel) {
	return (adc_get_base_reg(adc)->STAT & (1UL << channel))? true : false;
}

#endif /* CIAA_ADC_API_H_ */

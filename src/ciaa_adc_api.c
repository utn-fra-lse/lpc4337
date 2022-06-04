/*
 * ciaa_adc_api.c
 *
 *  Created on: Jun 3, 2022
 *      Author: fabri
 */

#include "ciaa_adc_api.h"

ADC_CHANNEL_T channels[] = {
	ADC_CH0, ADC_CH1, ADC_CH2, ADC_CH3,
	ADC_CH4, ADC_CH5, ADC_CH6, ADC_CH7
};

void adc_init(uint8_t adc) {
	/* Default config */
	ADC_CLOCK_SETUP_T config = {
		ADC_MAX_SAMPLE_RATE,	/* 400 kSamples/s */
		ADC_10BITS,				/* Max resolution */
		DISABLE					/* No burst mode */
	};

	/* Get ADC register */
	LPC_ADC_T *reg;
	reg = (adc)? CIAA_ADC1 : CIAA_ADC0;
	/* Initialize ADC */
	Chip_ADC_Init(reg, &config);
}

void adc_gpio_init(uint8_t adc, uint8_t channel) {
	/* Get ADC register */
	LPC_ADC_T *reg;
	reg = (adc)? CIAA_ADC1 : CIAA_ADC0;
	/* Enable selected channel with no interrupt */
	Chip_ADC_EnableChannel(reg, (ADC_CHANNEL_T)ADC_CH1, DISABLE);
}

void adc_select_input(uint8_t adc, uint8_t channel) {
	/* Get ADC register */
	LPC_ADC_T *reg;
	reg = (adc)? CIAA_ADC1 : CIAA_ADC0;
	/* Disable all channels */
	reg->CR &= ~0xff;
	/* Enable desired channel */
	reg->CR |= 1UL << channel;
}

uint8_t adc_get_selected_input(uint8_t adc) {
	/* Get ADC register */
	LPC_ADC_T *reg;
	reg = (adc)? CIAA_ADC1 : CIAA_ADC0;
	/* Get and return the selected channel */
	for(uint8_t channel = 0; channel < ADC_MAX_CHANNELS; channel++) {
		bool match = (reg->CR & (1UL << channel));
		if(match) { return channel; }
	}
	return 0xff;
}

uint16_t adc_read(uint8_t adc) {
	/* Get ADC register */
	LPC_ADC_T *reg;
	reg = (adc)? CIAA_ADC1 : CIAA_ADC0;
	/* ADC return value */
	uint16_t value;
	/* ADC selected value */
	ADC_CHANNEL_T channel = (ADC_CHANNEL_T)adc_get_selected_input(adc);
	/* Start conversion */
	Chip_ADC_SetStartMode(reg, ADC_START_NOW, ADC_TRIGGERMODE_RISING);
	/* Wait for conversion to finish */
	while( Chip_ADC_ReadStatus(reg, channel, ADC_DR_DONE_STAT) != SET );
	/* Read value from channel */
	Chip_ADC_ReadValue(reg, channel, &value);
	/* Return value */
	return value;
}

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

/* Prototype functions */
void adc_init(uint8_t adc);
void adc_gpio_init(uint8_t adc, uint8_t channel);
void adc_select_input(uint8_t adc, uint8_t channel);
uint8_t adc_get_selected_input(uint8_t adc);
uint16_t adc_read(uint8_t adc);

#endif /* CIAA_ADC_API_H_ */

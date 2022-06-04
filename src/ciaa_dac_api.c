/*
 * ciaa_dac_api.c
 *
 *  Created on: Jun 4, 2022
 *      Author: fabri
 */


#include "ciaa_dac_api.h"

void dac_init(void) {

	dac_config_t config = dac_get_default_config();
	dac_config_init(config);
}

void dac_config_init(dac_config_t config) {

	Chip_Clock_EnableOpts(CLK_APB3_DAC, true, true, 1);

	dac_set_bias(config.bias);

	dac_set_enabled(config.enabled);

	dac_set_alternative_output_enabled(config.alternativeOutput);

	dac_set_output_value(config.value);
}

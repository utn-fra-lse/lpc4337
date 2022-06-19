/*
 * ciaa_multicore_api_m0.c
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#include "ciaa_multicore_api_m0.h"

/*
 * 	@brief	Enable/Disbale M4 interrupt for M0 core
 *
 * 	@param	enabled: whether to enable or disable
 *
 * 	@return	None
 */
void multicore_irq_set_enabled(bool enabled) {
	if(enabled) { NVIC_EnableIRQ(M4_IRQn); }
	else { NVIC_DisableIRQ(M4_IRQn); }
}

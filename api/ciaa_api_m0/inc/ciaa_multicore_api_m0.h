/*
 * ciaa_multicore_api_m0.h
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#ifndef CIAA_MULTICORE_API_M0_H_
#define CIAA_MULTICORE_API_M0_H_

#include "ciaa_multicore_api.h"

/*
 * 	@brief	Alternative macro for the M4_IRQHandler
 *
 * 	@param	handler: function to execute when interrupt is triggered
 */
#define m4_handler(handler); 	void M4_IRQHandler(void) {	\
									/* Clear interrupt */	\
									multicore_irq_clear();	\
									/* Call handler */		\
									handler();				\
								}

#endif /* CIAA_MULTICORE_API_M0_H_ */

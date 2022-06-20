/*
 * ciaa_multicore_api_m0.h
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#ifndef CIAA_MULTICORE_API_M0_H_
#define CIAA_MULTICORE_API_M0_H_

#include "ciaa_multicore_api.h"

#define m4_handler(handler); 	void M4_IRQHandler(void) {	\
									multicore_irq_clear();	\
									handler();				\
								}

#endif /* CIAA_MULTICORE_API_M0_H_ */

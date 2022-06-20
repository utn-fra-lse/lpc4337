/*
 * ciaa_stdlib_m0.h
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#ifndef CIAA_STDLIB_M0_H_
#define CIAA_STDLIB_M0_H_

#include "ciaa_stdlib.h"

/*
 * 	@brief	M0 sleep for a number of milliseconds
 *
 * 	@param	ms: number of milliseconds
 *
 * 	@return	None
 */
static inline void delay_ms(uint32_t ms) { sleep_ms(TIMER_3, ms); }

/*
 * 	@brief	M0 sleep for a number of microseconds
 *
 * 	@param	us: number of microseconds
 *
 * 	@return	None
 */
static inline void delay_us(uint32_t us) { sleep_us(TIMER_3, us); }

#endif /* CIAA_STDLIB_M0_H_ */

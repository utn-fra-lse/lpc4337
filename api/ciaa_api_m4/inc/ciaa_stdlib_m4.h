/*
 * ciaa_stdlib_m4.h
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#ifndef CIAA_STDLIB_M4_H_
#define CIAA_STDLIB_M4_H_

#include "ciaa_stdlib.h"

/*
 * 	@brief	M0 sleep for a number of milliseconds
 *
 * 	@param	ms: number of milliseconds
 *
 * 	@return	None
 */
static inline void delay_ms(uint32_t ms) { sleep_ms(TIMER_0, ms); }

/*
 * 	@brief	M0 sleep for a number of microseconds
 *
 * 	@param	us: number of microseconds
 *
 * 	@return	None
 */
static inline void delay_us(uint32_t us) { sleep_us(TIMER_0, us); }

#endif /* CIAA_STDLIB_M4_H_ */

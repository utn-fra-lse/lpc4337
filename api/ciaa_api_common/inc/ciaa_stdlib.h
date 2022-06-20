/*
 * ciaa_stdlib.h
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#ifndef CIAA_STDLIB_H_
#define CIAA_STDLIB_H_

#include "ciaa_timer_api.h"

/* Extern sleep end flag */
extern bool sleep_flags[];

/* Function prototypes */
void sleep_ms(ciaa_timer_t timer, uint32_t ms);
void sleep_us(ciaa_timer_t timer, uint32_t us);
void sleep_ticks(ciaa_timer_t timer, uint32_t ticks);

/* Inline functions */

/*
 * 	@brief	Sleep for a number of microseconds
 * 			without TIMER usage
 *
 * 	@param	us: number of microseconds
 *
 * 	@return	None
 */
static inline void _sleep_us(uint32_t us) {
	/* Get number of ticks necessary */
	uint32_t ticks = timer_us_to_ticks(us);
	/* For loop takes 10 instructions to run */
	for(uint32_t i = 0; i < ticks / 10; i++);
}

/*
 * 	@brief	Sleep for a number of milliseconds
 * 			without TIMER usage
 *
 * 	@param	ms: number of milliseconds
 *
 * 	@return	None
 */
static inline void _sleep_ms(uint32_t ms) {
	/* Get number of ticks necessary */
	uint32_t ticks = timer_ms_to_ticks(ms);
	/* For loop takes 10 instructions to run */
	for(uint32_t i = 0; i < ticks / 10; i++);
}

/*
 * 	@brief	Set sleep flag
 *
 * 	@param	None
 *
 * 	@return	None
 */
static inline void sleep_set_flag(ciaa_timer_t timer) { sleep_flags[timer] = true; }

/*
 * 	@brief	Clear sleep flag
 *
 * 	@param	None
 *
 * 	@return None
 */
static inline void sleep_clear_flag(ciaa_timer_t timer) { sleep_flags[timer] = false; }

/*
 * 	@brief	Get sleep flag value
 *
 * 	@param	None
 *
 * 	@return	true or false
 */
static inline bool sleep_get_flag(ciaa_timer_t timer) { return sleep_flags[timer]; }

#endif /* CIAA_STDLIB_H_ */

/*
 * ciaa_stdlib.h
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#ifndef CIAA_STDLIB_H_
#define CIAA_STDLIB_H_

#include "ciaa_timer_api.h"

#define DELAY_TIMER	TIMER_0

/* Extern sleep end flag */
extern bool sleep_flag;

/* Function prototypes */
void sleep_ms(uint32_t ms);
void sleep_us(uint32_t us);
void sleep_ticks(uint32_t ticks);

/* Inline functions */

/*
 * 	@brief	Set sleep flag
 *
 * 	@param	None
 *
 * 	@return	None
 */
static inline void sleep_set_flag(void) { sleep_flag = true; }

/*
 * 	@brief	Clear sleep flag
 *
 * 	@param	None
 *
 * 	@return None
 */
static inline void sleep_clear_flag(void) { sleep_flag = false; }

/*
 * 	@brief	Get sleep flag value
 *
 * 	@param	None
 *
 * 	@return	true or false
 */
static inline bool sleep_get_flag(void) { return sleep_flag; }

#endif /* CIAA_STDLIB_H_ */

/*
 * ciaa_systick_api.h
 *
 *  Created on: Jun 7, 2022
 *      Author: fabri
 */

#ifndef CIAA_SYSTICK_API_H_
#define CIAA_SYSTICK_API_H_

#include "chip.h"

extern void (*handler)(void);

typedef uint32_t absolute_time_t;

extern absolute_time_t absoluteTimeMs;

void systick_init(uint32_t frequency);

static inline void systick_start(void) { SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk; }

static inline void systick_stop(void) { SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; }

static inline void systick_reset(void) { SysTick->VAL = 0; }

static inline void systick_set_period_us(uint32_t us) {
	/* Stop the counter */
	systick_stop();
	/* Calculate the number of ticks to match */
	uint32_t ticks = SystemCoreClock * (us / 1E6);
	/* Configure SysTick */
	SysTick->LOAD = ticks - 1;
	/* Reset counter */
	systick_reset();
	/* Start counter */
	systick_start();
}

static inline absolute_time_t systick_get_absolute_time(void) { return absoluteTimeMs; }

static inline void systick_set_irq_handler(void (*handler)(void)) { handler = handler; }

#endif /* CIAA_SYSTICK_API_H_ */

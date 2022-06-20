/*
 * ciaa_stdlib.c
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#include "ciaa_stdlib.h"

/* Extern sleep end flag */
bool sleep_flags[] = { false, false, false, false };

/*
 * 	@brief	Delay for a number of milliseconds
 *
 *	@param	timer: TIMER to control de the dalay
 * 	@param	ms: number of milliseconds
 *
 * 	@return	None
 */
void sleep_ms(ciaa_timer_t timer, uint32_t ms) {
	/* Get the number of ticks necessary */
	uint32_t ticks = timer_ms_to_ticks(ms);
	/* Sleep said number of ticks */
	sleep_ticks(timer, ticks);
}

/*
 * 	@brief	Delay for a number of microseconds
 *
 *	@param	timer: TIMER to control de the dalay
 * 	@param	us: number of microseconds
 *
 * 	@return	None
 */
void sleep_us(ciaa_timer_t timer, uint32_t us) {
	/* Get the number of ticks necessary */
	uint32_t ticks = timer_us_to_ticks(us);
	/* Sleep said number of ticks */
	sleep_ticks(timer, ticks);
}

/*
 * 	@brief	Delay for a number of ticks
 *
 *	@param	timer: TIMER to control de the dalay
 * 	@param	ticks: number of ticks
 *
 * 	@return	None
 */
void sleep_ticks(ciaa_timer_t timer, uint32_t ticks) {
	/* Initialize TIMER */
	timer_init(timer);
	/* Reset counter value */
	timer_reset(timer);
	/* Set a new match to trigger interrupt */
	timer_set_match_ticks(timer, ticks);
	/* Enable TIMER0 interrupt */
	timer_set_irq_enabled(timer, true);
	/* Set a handler for the interrupt */
	timer_set_irq_handler(timer, sleep_set_flag);
	/* Start TIMER0 counter */
	timer_start(timer);
	/* Wait for interrupt to trigger */
	while(!sleep_get_flag(timer));
	/* Clear sleep flag */
	sleep_clear_flag(timer);
	/* Stop TIMER conter */
	timer_stop(timer);
	/* Reset counter value */
	timer_reset(timer);
	/* Disable TIMER */
	timer_deinit(timer);
}

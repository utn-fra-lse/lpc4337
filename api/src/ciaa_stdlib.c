/*
 * ciaa_stdlib.c
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#include "ciaa_stdlib.h"

/* Extern sleep end flag */
bool sleep_flag = false;

/*
 * 	@brief	Delay for a number of milliseconds
 *
 * 	@param	ms: number of milliseconds
 *
 * 	@return	None
 */
void sleep_ms(uint32_t ms) {
	/* Get the number of ticks necessary */
	uint32_t ticks = timer_ms_to_ticks(ms);
	/* Sleep said number of ticks */
	sleep_ticks(ticks);
}

/*
 * 	@brief	Delay for a number of microseconds
 *
 * 	@param	us: number of microseconds
 *
 * 	@return	None
 */
void sleep_us(uint32_t us) {
	/* Get the number of ticks necessary */
	uint32_t ticks = timer_us_to_ticks(us);
	/* Sleep said number of ticks */
	sleep_ticks(ticks);
}


void sleep_ticks(uint32_t ticks) {
	/* Initialize TIMER0 */
	timer_init(TIMER_0);
	/* Reset counter value */
	timer_reset(TIMER_0);
	/* Set a new match to trigger interrupt */
	timer_set_match_ticks(TIMER_0, ticks);
	/* Enable TIMER0 interrupt */
	timer_set_irq_enabled(TIMER_0, true);
	/* Set a handler for the interrupt */
	timer_set_irq_handler(TIMER_0, sleep_set_flag);
	/* Start TIMER0 counter */
	timer_start(TIMER_0);
	/* Wait for interrupt to trigger */
	while(!sleep_get_flag());
	/* Clear sleep flag */
	sleep_clear_flag();
	/* Stop TIMER0 conter */
	timer_stop(TIMER_0);
	/* Reset counter value */
	timer_reset(TIMER_0);
	/* Disable TIMER0 */
	timer_deinit(TIMER_0);
}

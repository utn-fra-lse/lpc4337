/*
 * ciaa_systick_api.c
 *
 *  Created on: Jun 7, 2022
 *      Author: fabri
 */

#include "ciaa_systick_api.h"

void (*handler)(void) = { NULL };

absolute_time_t absoluteTimeMs = 0;

void systick_init(uint32_t us) {
	/* Calculate the number of ticks to match */
	uint32_t ticks = SystemCoreClock * (us / 1E6);
    /* Configure SysTick */
	SysTick_Config(ticks);
}

void SysTick_Handler(void) {
	/* Increment absolute time counter by 1 every milliseccond */
	absoluteTimeMs++;
	/* Check if there is any handler and call it */
	if(*handler) {
		(*handler)();
	}
}

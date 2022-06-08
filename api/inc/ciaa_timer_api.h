/*
 * ciaa_timer_api.h
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#ifndef CIAA_TIMER_API_H_
#define CIAA_TIMER_API_H_

#include "chip.h"

#define CIAA_TIMER0	LPC_TIMER0
#define CIAA_TIMER1	LPC_TIMER1
#define CIAA_TIMER2	LPC_TIMER2
#define CIAA_TIMER3	LPC_TIMER3

extern LPC_TIMER_T *CIAA_TIMERS[];
extern CHIP_CCU_CLK_T TIMER_CLKS[];
extern LPC43XX_IRQn_Type TIMER_IRQS[];

extern void (*timer_handlers[])(void);

void timer_reset(uint8_t timer);
void timer_set_irq_enabled(uint8_t timer, bool enabled);

static inline LPC_TIMER_T* timer_get_base_register(uint8_t timer) { return CIAA_TIMERS[timer]; }

static inline void timer_init(uint8_t timer) { Chip_Clock_Enable(TIMER_CLKS[timer]); }

static inline void timer_deinit(uint8_t timer) { Chip_Clock_Disable(TIMER_CLKS[timer]); }

static inline void timer_set_match_ticks(uint8_t timer, uint32_t ticks) { timer_get_base_register(timer)->MR[0] = ticks; }

static inline void timer_start(uint8_t timer) { timer_get_base_register(timer)->TCR |= TIMER_ENABLE; }

static inline void timer_stop(uint8_t timer) { timer_get_base_register(timer)->TCR &= ~TIMER_ENABLE; }

static inline void timer_set_start(uint8_t timer, bool enabled) {
	/* Disable interrupt */
	timer_stop(timer);
	/* Enable if required */
	if(enabled) { timer_start(timer); }
}

static inline bool timer_get_match_pending(uint8_t timer) { return (bool) ((timer_get_base_register(timer)->IR & TIMER_MATCH_INT(0)) != 0); }

static inline void timer_clear_irq_flag(uint8_t timer) { timer_get_base_register(timer)->IR = TIMER_IR_CLR(0); }

static inline void timer_set_irq_handler(uint8_t timer, void (*handler)(void)) { timer_handlers[timer] = handler; }

static inline void timer_clear_irq_handler(uint8_t timer) { timer_handlers[timer] = NULL; }

#endif /* CIAA_TIMER_API_H_ */

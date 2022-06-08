/*
 * ciaa_timer_api.h
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#ifndef CIAA_TIMER_API_H_
#define CIAA_TIMER_API_H_

#include "chip.h"

/* Base TIMER register redefinitions */
#define CIAA_TIMER0	LPC_TIMER0
#define CIAA_TIMER1	LPC_TIMER1
#define CIAA_TIMER2	LPC_TIMER2
#define CIAA_TIMER3	LPC_TIMER3

/* Extern arrays */
extern LPC_TIMER_T *CIAA_TIMERS[];
extern CHIP_CCU_CLK_T TIMER_CLKS[];
extern LPC43XX_IRQn_Type TIMER_IRQS[];
/* Extern interrupt handlers pointer */
extern void (*timer_handlers[])(void);

/* Function prototypes */
void timer_reset(uint8_t timer);
void timer_set_irq_enabled(uint8_t timer, bool enabled);

/*
 *	@brief	Gets the TIMER base register
 *
 *	@param	timer: TIMER number (0, 1, 2, 3)
 *
 *	@return	TIMER base register
 */
static inline LPC_TIMER_T* timer_get_base_register(uint8_t timer) { return CIAA_TIMERS[timer]; }

/*
 * 	@brief	Enable TIMER clock
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 *
 * 	@return	None
 */
static inline void timer_init(uint8_t timer) { Chip_Clock_Enable(TIMER_CLKS[timer]); }

/*
 *	@brief	Disable TIMER clock
 *
 *	@param	timer: TIMER number (0, 1, 2, 3)
 *
 *	@return	None
 */
static inline void timer_deinit(uint8_t timer) { Chip_Clock_Disable(TIMER_CLKS[timer]); }

/*
 * 	@brief	Set TIMER match value in ticks
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 * 	@param	ticks: match value in ticks
 *
 * 	@return	None
 */
static inline void timer_set_match_ticks(uint8_t timer, uint32_t ticks) { timer_get_base_register(timer)->MR[0] = ticks; }

/*
 * 	@brief	Start TIMER counter
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 *
 * 	@return	None
 */
static inline void timer_start(uint8_t timer) { timer_get_base_register(timer)->TCR |= TIMER_ENABLE; }

/*
 * 	@brief	Stop TIMER counter
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 *
 * 	@return	None
 */
static inline void timer_stop(uint8_t timer) { timer_get_base_register(timer)->TCR &= ~TIMER_ENABLE; }

/*
 * 	@brief	Start/Stop TIMER counter
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 * 	@param	enabled: whether the TIMER starts or stops:
 * 		- false: to stop
 * 		- true: to start
 *
 * 	@return	None
 */
static inline void timer_set_start(uint8_t timer, bool enabled) {
	/* Disable interrupt */
	timer_stop(timer);
	/* Enable if required */
	if(enabled) { timer_start(timer); }
}

/*
 * 	@brief	Get if there is a match interrupt pending
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 *
 * 	@return	true if there is, false if not
 */
static inline bool timer_get_match_pending(uint8_t timer) { return (bool) ((timer_get_base_register(timer)->IR & TIMER_MATCH_INT(0)) != 0); }

/*
 * 	@brief	Clear interrupt match flag
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 *
 * 	@return None
 */
static inline void timer_clear_irq_flag(uint8_t timer) { timer_get_base_register(timer)->IR = TIMER_IR_CLR(0); }

/*
 * 	@brief	Set an interrupt handler
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 * 	@param	handler: function handler to call
 *
 * 	@return None
 */
static inline void timer_set_irq_handler(uint8_t timer, void (*handler)(void)) { timer_handlers[timer] = handler; }

/*
 * 	@brief	Clear an interrupt handler
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 *
 * 	@return None
 */
static inline void timer_clear_irq_handler(uint8_t timer) { timer_handlers[timer] = NULL; }

#endif /* CIAA_TIMER_API_H_ */

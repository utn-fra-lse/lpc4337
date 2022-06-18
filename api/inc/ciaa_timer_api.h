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
#ifdef CORE_M4
#define CIAA_TIMER1	LPC_TIMER1
#define CIAA_TIMER2	LPC_TIMER2
#endif
#define CIAA_TIMER3	LPC_TIMER3

/* CIAA available TIMERS */
typedef enum {
	TIMER_0,
#ifdef CORE_M4
	TIMER_1,
	TIMER_2,
#endif
	TIMER_3
} ciaa_timer_t;

/* Extern arrays */
extern LPC_TIMER_T *CIAA_TIMERS[];
extern CHIP_CCU_CLK_T TIMER_CLKS[];
#ifdef CORE_M4
extern LPC43XX_IRQn_Type TIMER_IRQS[];
#elif defined(CORE_M0)
extern LPC43XX_M0_IRQn_Type TIMER_IRQS[];
#endif
/* Extern interrupt handlers pointer */
extern void (*timer_handlers[])(void);

/* Function prototypes */
void timer_reset(ciaa_timer_t timer);
void timer_set_irq_enabled(ciaa_timer_t timer, bool enabled);

/*
 * 	@brief	Convert milliseconds to ticks
 *
 * 	@param	ms: number of milliseconds
 *
 * 	@return None
 */
static inline uint32_t timer_ms_to_ticks(uint32_t ms) { return (SystemCoreClock / 1E3) * ms; }

/*
 * 	@brief	Convert microseconds to ticks
 *
 * 	@param	us: number of microseconds
 *
 * 	@return	None
 */
static inline uint32_t timer_us_to_ticks(uint32_t us) { return (SystemCoreClock / 1E6) * us; }

/*
 *	@brief	Gets the TIMER base register
 *
 *	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 *	@return	TIMER base register
 */
static inline LPC_TIMER_T* timer_get_base_register(ciaa_timer_t timer) { return CIAA_TIMERS[timer]; }

/*
 * 	@brief	Enable TIMER clock
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 * 	@return	None
 */
static inline void timer_init(ciaa_timer_t timer) { Chip_Clock_Enable(TIMER_CLKS[timer]); }

/*
 *	@brief	Disable TIMER clock
 *
 *	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 *	@return	None
 */
static inline void timer_deinit(ciaa_timer_t timer) { Chip_Clock_Disable(TIMER_CLKS[timer]); }

/*
 * 	@brief	Set TIMER match value in ticks
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 * 	@param	ticks: match value in ticks
 *
 * 	@return	None
 */
static inline void timer_set_match_ticks(ciaa_timer_t timer, uint32_t ticks) { timer_get_base_register(timer)->MR[0] = ticks; }

/*
 * 	@brief	Start TIMER counter
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 * 	@return	None
 */
static inline void timer_start(ciaa_timer_t timer) { timer_get_base_register(timer)->TCR |= TIMER_ENABLE; }

/*
 * 	@brief	Stop TIMER counter
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 * 	@return	None
 */
static inline void timer_stop(ciaa_timer_t timer) { timer_get_base_register(timer)->TCR &= ~TIMER_ENABLE; }

/*
 * 	@brief	Start/Stop TIMER counter
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 * 	@param	enabled: whether the TIMER starts or stops:
 * 		- false: to stop
 * 		- true: to start
 *
 * 	@return	None
 */
static inline void timer_set_start(ciaa_timer_t timer, bool enabled) {
	/* Disable interrupt */
	timer_stop(timer);
	/* Enable if required */
	if(enabled) { timer_start(timer); }
}

/*
 * 	@brief	Get if there is a match interrupt pending
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 * 	@return	true if there is, false if not
 */
static inline bool timer_get_match_pending(ciaa_timer_t timer) { return (bool) ((timer_get_base_register(timer)->IR & TIMER_MATCH_INT(0)) != 0); }

/*
 * 	@brief	Clear interrupt match flag
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 * 	@return None
 */
static inline void timer_clear_irq_flag(ciaa_timer_t timer) { timer_get_base_register(timer)->IR = TIMER_IR_CLR(0); }

/*
 * 	@brief	Set an interrupt handler
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 * 	@param	handler: function handler to call
 *
 * 	@return None
 */
static inline void timer_set_irq_handler(ciaa_timer_t timer, void (*handler)(void)) { timer_handlers[timer] = handler; }

/*
 * 	@brief	Clear an interrupt handler
 *
 * 	@param	timer: TIMER number (ciaa_ttimer_t)
 *
 * 	@return None
 */
static inline void timer_clear_irq_handler(ciaa_timer_t timer) { timer_handlers[timer] = NULL; }

#endif /* CIAA_TIMER_API_H_ */

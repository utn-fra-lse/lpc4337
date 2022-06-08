/*
 * ciaa_timer_api.c
 *
 *  Created on: Jun 8, 2022
 *      Author: fabri
 */

#include "ciaa_timer_api.h"

/* TIMER base registers array */
LPC_TIMER_T *CIAA_TIMERS[] = { CIAA_TIMER0, CIAA_TIMER1, CIAA_TIMER2, CIAA_TIMER3 };
/* Base clocks for TIMERs */
CHIP_CCU_CLK_T TIMER_CLKS[] = { CLK_MX_TIMER0, CLK_MX_TIMER1, CLK_MX_TIMER2, CLK_MX_TIMER3 };
/* TIMER interrupt vectors */
LPC43XX_IRQn_Type TIMER_IRQS[] = { TIMER0_IRQn, TIMER1_IRQn, TIMER2_IRQn, TIMER3_IRQn };

/* Interrupt handlers function pointer */
void (*timer_handlers[])(void) = { NULL, NULL, NULL, NULL };

/*
 * 	@brief	Resets the timer terminal and prescale counts to 0
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 *
 * 	@return	None
 */
void timer_reset(uint8_t timer) {
	/* Disable timer, set terminal count to non-0 */
	uint32_t reg = timer_get_base_register(timer)->TCR;
	timer_get_base_register(timer)->TCR = 0;
	timer_get_base_register(timer)->TC = 1;
	/* Reset timer counter */
	timer_get_base_register(timer)->TCR = TIMER_RESET;
	/* Wait for terminal count to clear */
	while (timer_get_base_register(timer)->TC);
	/* Restore timer state */
	timer_get_base_register(timer)->TCR = reg;
}

/*
 * 	@brief	Enable/Disbale TIMER interrupt
 *
 * 	@param	timer: TIMER number (0, 1, 2, 3)
 * 	@param	enabled: whether to enable or disable interrupt
 *
 * 	@return None
 */
void timer_set_irq_enabled(uint8_t timer, bool enabled) {
	/* Disable interrupt */
	timer_get_base_register(timer)->MCR &= ~TIMER_INT_ON_MATCH(0);
	/* Enable if required */
	if(enabled) { timer_get_base_register(timer)->MCR |= TIMER_INT_ON_MATCH(0); }
	/* Reset counter on match */
	timer_get_base_register(timer)->MCR |= TIMER_RESET_ON_MATCH(0);
	/* Clear pending interrupt */
	NVIC_ClearPendingIRQ(TIMER_IRQS[timer]);
	NVIC_EnableIRQ(TIMER_IRQS[timer]);
}

/*
 *	@brief	TIMER0 interrupt handler
 *
 *	@param	None
 *
 *	@return	None
 */
void TIMER0_IRQHandler(void) {

	if(timer_get_match_pending(0)) {
		if(timer_handlers[0]) { timer_handlers[0](); }
		timer_clear_irq_flag(0);
	}
}

/*
 *	@brief	TIMER1 interrupt handler
 *
 *	@param	None
 *
 *	@return	None
 */
void TIMER1_IRQHandler(void) {

	if(timer_get_match_pending(1)) {

		if(timer_handlers[1]) { timer_handlers[1](); }
		timer_clear_irq_flag(1);
	}
}

/*
 *	@brief	TIMER2 interrupt handler
 *
 *	@param	None
 *
 *	@return	None
 */
void TIMER2_IRQHandler(void) {

	if(timer_get_match_pending(2)) {

		if(timer_handlers[2]) { timer_handlers[2](); }
		timer_clear_irq_flag(2);
	}
}

/*
 *	@brief	TIMER3 interrupt handler
 *
 *	@param	None
 *
 *	@return	None
 */
void TIMER3_IRQHandler(void) {

	if(timer_get_match_pending(3)) {

		if(timer_handlers[3]) { timer_handlers[3](); }
		timer_clear_irq_flag(3);
	}
}

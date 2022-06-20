/*
 * ciaa_multicore_api_m4.h
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#ifndef CIAA_MULTICORE_API_H_
#define CIAA_MULTICORE_API_H_

#include "chip.h"

/* Size of applications in flash */
#define IMG_SZ_M4      (32 * 1024)
#define IMG_SZ_M0APP   (16 * 1024)

#define IFLASH_A_BASE_ADDR  0x1A000000	/* IFLASH BANK-A */
#define IFLASH_B_BASE_ADDR  0x1B000000	/* IFLASH BANK-B */

#define BASE_ADDRESS_M0APP     (IFLASH_B_BASE_ADDR)

extern void (*multicore_irq_handler[])(void);

typedef enum {
	CM4,
	CM0
} multicore_cores_t;

/* Multicore inline functions */

#ifdef CORE_M0
/*
 * 	@brief	Enable/Disbale M4 interrupt for M0 core
 *
 * 	@param	enabled: whether to enable or disable
 *
 * 	@return	None
 */

static inline void multicore_m4_irq_set_enabled(bool enabled) {
	if(enabled) { NVIC_EnableIRQ(M4_IRQn); }
	else { NVIC_DisableIRQ(M4_IRQn); }
}

#elif defined(CORE_M4)
static inline void multicore_m0app_irq_set_enabled(bool enabled) {
	if(enabled) { NVIC_EnableIRQ(M0APP_IRQn); }
	else { NVIC_DisableIRQ(M0APP_IRQn); }
}
#endif
/*
 * Initiate interrupt on other processor
 * Upon calling this function generates and interrupt on the other
 * core. Ex. if called from M0 core it generates interrupt on M4 core
 * and vice versa.
 */
#ifdef CORE_M0
static inline void multicore_interrupt_m4_core(void) {
#elif defined(CORE_M4)
static inline void multicore_interrupt_m0_core(void) {
#endif
	__DSB();
	__SEV();
}

static inline void multicore_irq_clear(void) {
#ifdef CORE_M0
	LPC_CREG->M4TXEVENT = 0;
#elif defined(CORE_M4)
	LPC_CREG->M0APPTXEVENT = 0;
#endif
}

static inline void multicore_irq_set_handler(void (*handler)(void)) {
#ifdef CORE_M0
	multicore_irq_handler[CM4] = handler;
#elif defined(CORE_M4)
	multicore_irq_handler[CM0] = handler;
#endif
}

#endif /* CIAA_MULTICORE_API_H_ */

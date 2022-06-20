/*
 * ciaa_multicore_api_m4.h
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#ifndef CIAA_MULTICORE_API_M4_H_
#define CIAA_MULTICORE_API_M4_H_

#include "ciaa_multicore_api.h"

/*
 * 	@brief	Alternative macro for the M0APP_IRQHandler
 *
 * 	@param	handler: function to execute when interrupt is triggered
 */
#define m0app_handler(handler);		void M0APP_IRQHandler(void) {	\
										/* Clear interrupt */		\
										multicore_irq_clear();		\
										/* Call handler */			\
										handler();					\
									}

/* Function prototypes */
int multicore_m0_start(void);

/* Multicore inline functions */

/*
 * 	@brief	Check memory alignment
 *
 * 	@param	address: address to the M0APP flash memory
 *
 * 	@return memory alignment value
 */
static inline uint32_t multicore_m0_check_alignment(uint32_t address) { return address & 0xFFF; }

/*
 * 	@brief	Perform a sanity check on the M0 memory address
 *
 * 	@param	address: address to the M0APP flash memory
 *
 * 	@return	true if valid, false if not
 */
static inline bool multicore_m0_sanity_check(uint32_t address) { return (address & 0xFFF00000) != ((*(unsigned long*) (address + 4)) & 0xFFF00000); }

/*
 * 	@brief	Set M0 memory map
 *
 * 	@param	address: address to the M0APP flash memory
 *
 * 	@return	None
 */
static inline void multicore_m0_set_memory_map(uint32_t address) { LPC_CREG->M0APPMEMMAP = address & ~0xFFF; }

#endif /* CIAA_MULTICORE_API_M4_H_ */

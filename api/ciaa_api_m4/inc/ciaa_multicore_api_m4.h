/*
 * ciaa_multicore_api_m4.h
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#ifndef CIAA_MULTICORE_API_M4_H_
#define CIAA_MULTICORE_API_M4_H_

#include "ciaa_multicore_api.h"

#define m0app_handler(handler);		void M0APP_IRQHandler(void) {	\
										multicore_irq_clear();		\
										handler();					\
									}

/* Function prototypes */
int multicore_m0_start(void);

/* Multicore inline functions */
static inline uint32_t multicore_m0_check_alignment(uint32_t m0_image_addr) {
	return m0_image_addr & 0xFFF;
}

static inline bool multicore_m0_sanity_check(uint32_t m0_image_addr) {
	return (m0_image_addr & 0xFFF00000) != ((*(unsigned long *) (m0_image_addr + 4)) & 0xFFF00000);
}

static inline void multicore_m0_set_memory_map(uint32_t address) {
	LPC_CREG->M0APPMEMMAP = address & ~0xFFF;
}

#endif /* CIAA_MULTICORE_API_M4_H_ */

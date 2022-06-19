/*
 * ciaa_multicore_api_m4.h
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#ifndef CIAA_MULTICORE_API_M4_H_
#define CIAA_MULTICORE_API_M4_H_

#include "ciaa_multicore_api.h"

/* Function prototypes */
int multicore_m0_start(void);

/* Multicore inline functions */
static inline uint32_t multicore_m0_check_alignment(uint32_t m0_image_addr) {
	return m0_image_addr & 0xFFF;
}

static inline bool multicore_m0_sanity_check(uint32_t m0_image_addr) {
	return (m0_image_addr & 0xFFF00000) != ((*(unsigned long *) (m0_image_addr + 4)) & 0xFFF00000);
}

#endif /* CIAA_MULTICORE_API_M4_H_ */

/*
 * ciaa_multicore_api_m4.c
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#include "ciaa_multicore_api_m4.h"

/*
 * 	@brief	Start M0 core
 *
 * 	@param	None
 *
 * 	@return	zero if initialized correctly
 */
int multicore_m0_start(void) {
	uint32_t m0_image_addr = BASE_ADDRESS_M0APP;
	/* Make sure the alignment is OK */
	if (multicore_m0_check_alignment(m0_image_addr)) { return -1; }
	/* Sanity check, see if base address and reset handler address resides in same region */
	if (multicore_m0_sanity_check(m0_image_addr)) { return -2; }
	/* Make sure the M0 core is being held in reset via the RGU */
	Chip_RGU_TriggerReset(RGU_M0APP_RST);
	Chip_Clock_Enable(CLK_M4_M0APP);
	/* Keep in mind the M0 image must be aligned on a 4K boundary */
	multicore_m0_set_memory_map(m0_image_addr);
	Chip_RGU_ClearReset(RGU_M0APP_RST);
	return 0;
}

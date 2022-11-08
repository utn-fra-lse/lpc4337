/*
 * ciaa_dma_api.c
 *
 *  Created on: Nov 7, 2022
 *      Author: carlassaraf
 */

#include "ciaa_dma_api.h"

void dma_config_init(dma_config_t config) {
	/* Initialize DMA controller */
	Chip_GPDMA_Init(LPC_GPDMA);
	/* Find a free DMA channel */
	uint8_t dma_channel = Chip_GPDMA_GetFreeChannel(LPC_GPDMA, 0x00);
	/* Setup DMA transfer */
	Chip_GPDMA_Transfer(
			LPC_GPDMA,
			dma_channel,
			(uint32_t) config.src,
			(uint32_t) config.dst,
			(dma_flow_control_t) config.type,
			(uint32_t) config.size
	);
	/* Enable DMA Interrupt */
	NVIC_EnableIRQ(DMA_IRQn);
}

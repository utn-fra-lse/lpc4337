#include "ciaa_multicore_api.h"

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Enable interrupt from M0 core */
	multicore_m0app_irq_set_enabled(true);
	/* Start M0 core */
	multicore_m0_start();

	while (1) {
		/* Interrupt M0 core */
		//	multicore_interrupt_m0_core();
	}
	return 0;
}

/* @brief	M0APP interrupt handler
 *
 * @note	produces same effect as using macro: m0app_handler(m0app_callback);
 */
void M0APP_IRQHandler(void) {
	/* Clear interrupt */
	multicore_irq_clear();
}

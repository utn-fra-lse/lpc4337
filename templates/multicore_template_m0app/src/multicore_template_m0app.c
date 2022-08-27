#include "ciaa_multicore_api.h"

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Enable interrupt from M4 core */
	multicore_m4_irq_set_enabled(true);

	while (1) {
		/* Interrupt M4 core */
		//	multicore_interrupt_m4_core();
	}

	return 0;
}

/* @brief	M4 interrupt handler
 *
 * @note	produces same effect as using macro: m4_handler(m4_callback);
 */
void M4_IRQHandler(void) {
	/* Clear interrupt */
	multicore_irq_clear();
}


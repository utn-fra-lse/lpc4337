#include "ciaa_multicore_api.h"
#include "ciaa_gpio_api.h"

/* Callback for M4 interrupt */
void m4_callback(void) {
	/* Toggle LED2 */
	gpio_xor(LED2);
	/* Interrupt M4 core */
	multicore_interrupt_m4_core();
}

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Set LED2 as output */
	gpio_set_dir_out(LED2);
	/* Enable interrupt from M4 core */
	multicore_m4_irq_set_enabled(true);
	/* Clear LED2 */
	gpio_clr(LED2);

	while (1);

	return 0;
}

/* @brief	M4 interrupt handler
 *
 * @note	produces same effect as using macro: m4_handler(m4_callback);
 */
void M4_IRQHandler(void) {
	/* Clear interrupt */
	multicore_irq_clear();
	/* Call callback */
	m4_callback();
}


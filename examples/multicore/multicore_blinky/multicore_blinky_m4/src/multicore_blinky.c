#include "ciaa_multicore_api.h"
#include "ciaa_gpio_api.h"
#include "ciaa_stdlib.h"

/* Callback for M0APP interrupt  */
void m0app_callback(void) {
	/* Toggle LED3 */
	gpio_xor(LED3);
}

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Set LED1 and LED3 as output */
	gpio_set_dir_out(LED1);
	gpio_set_dir_out(LED3);
	/* Enable interrupt from M0 core */
	multicore_m0app_irq_set_enabled(true);
	/* Start M0 core */
	multicore_m0_start();
	/* Clear LED1 and LED3 */
	gpio_clr(LED1);
	gpio_clr(LED3);

	while (1) {
		/* Wait for 1 second */
		sleep_ms(1000);
		/* Toggle LED1 */
		gpio_xor(LED1);
		/* Interrupt M0 core */
		multicore_interrupt_m0_core();

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
	/* Call callback */
	m0app_callback();
}

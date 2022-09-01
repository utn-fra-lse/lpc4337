#include "ciaa_multicore_api.h"
#include "ciaa_gpio_api.h"
#include "ciaa_systick_api.h"
#include "ciaa_stdlib.h"

uint8_t systick_cnt = 0;
uint8_t m0_cnt = 0;

/* Callback for M0APP interrupt  */
void m0app_callback(void) {
	/* Toggle LED every 2 M0 to M4 interrupts */
	if(m0_cnt++ == 1) {
		/* Toggle LED3 */
		gpio_xor(LED3);
		/* Reset counter */
		m0_cnt = 0;
	}
}

/* Callback for Systick Interrupt */
void systick_callback(void) {
	/* Interrupt M0 at 500 ms */
	if(systick_cnt++ == 9) {
		/* Interrupt M0 core */
		multicore_interrupt_m0_core();
		/* Reset counter */
		systick_cnt = 0;
	}
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
	/* Initialize Systick with 1 ms */
	systick_init(50000);
	/* Add Systick callback */
	systick_set_irq_handler(systick_callback);

	while (1) {
		/* Wait for 1 second */
		sleep_ms(2000);
		/* Toggle LED1 */
		gpio_xor(LED1);
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


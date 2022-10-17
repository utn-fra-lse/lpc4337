/*
===============================================================================
 Name        : freertos_multicore_blinky_m0app.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "FreeRTOS.h"
#include "task.h"
#include "ciaa_gpio_api.h"

/* Task priority */
#define tskLED2_PRIORITY	tskIDLE_PRIORITY + 1UL

/**
 * @brief Task that blinks LED2 every 500 ms
 * @param params: aditional parameters for the task
 * @return None
 */
void task_led2(void *params) {
	/* Delay in ms */
	const uint16_t delay_ms = 500;

	while(1) {
		/* Toggle LED2 */
		gpio_xor(LED2);
		/* Block task for 500 ms */
		vTaskDelay(delay_ms / portTICK_RATE_MS);
	}
}


int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* Task creation */
	xTaskCreate(
		task_led2,					/* Callback function */
		(const char*) "LED2 task",	/* Debugging info */
		configMINIMAL_STACK_SIZE,	/* Stack size */
		NULL,						/* No parameters */
		tskLED2_PRIORITY,			/* Task priority */
		NULL						/* No handler */
	);

	/* Start scheduler */
	vTaskStartScheduler();

	while(1);

}

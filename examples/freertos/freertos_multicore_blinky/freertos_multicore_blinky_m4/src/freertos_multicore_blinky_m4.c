/*
===============================================================================
 Name        : freertos_multicore_blinky_m4.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "FreeRTOS.h"
#include "task.h"
#include "ciaa_board_api.h"
#include "ciaa_multicore_api.h"

/* Task priority */
#define tskLED1_PRIORITY	tskIDLE_PRIORITY + 1UL

/**
 * @brief Task that blinks LED1 every 1000 ms
 * @param params: aditional parameters for the task
 * @return None
 */
void task_led1(void *params) {
	/* Delay in ms */
	const uint16_t delay_ms = 1000;

	while(1) {
		/* Toggle LE12 */
		gpio_xor(LED1);
		/* Block task for 1000 ms */
		vTaskDelay(delay_ms / portTICK_RATE_MS);
	}
}

int main(void) {
	/* Initialize board */
	ciaa_board_init();
	/* Start M0 core */
	multicore_m0_start();
	/* Task creation */
	xTaskCreate(
		task_led1,					/* Callback function */
		(const char*) "LED1 task",	/* Debugging info */
		configMINIMAL_STACK_SIZE,	/* Stack size */
		NULL,						/* No parameters */
		tskLED1_PRIORITY,			/* Task priority */
		NULL						/* No handler */
	);

	/* Start scheduler */
	vTaskStartScheduler();

	while(1);
}

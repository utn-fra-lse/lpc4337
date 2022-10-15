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

void task_led2(void *params) {

	const uint16_t delay_ms = 500;

	while(1) {

		gpio_xor(LED2);
		vTaskDelay(delay_ms / portTICK_RATE_MS);
	}
}

int main(void) {


	xTaskCreate(
		task_led2,
		(const char*) "LED2 task",
		configMINIMAL_STACK_SIZE,
		NULL,
		tskIDLE_PRIORITY,
		NULL
	);

	vTaskStartScheduler();

	while(1);

}

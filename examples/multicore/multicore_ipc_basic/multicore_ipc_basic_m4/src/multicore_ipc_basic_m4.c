/*
===============================================================================
 Name        : multicore_ipc_basic_m4.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_ipc_api.h"
#include "ciaa_systick_api.h"
#include "ciaa_board_api.h"

/* Define M4 function */
#define M4_MASTER

/* Shared data */
uint32_t data = 0;

void systick(void) {
	/* SysTick interrupt counter */
	static uint8_t ctn = 0;
	ctn++;
	/* When counter reaches 100 equals 1s has passed */
	if(ctn > 99) {
		/* Reset SysTick counter */
		ctn = 0;
#if defined(M4_SLAVE) && !defined(M4_MASTER)
		/* Interrupt M0 to request data */
		multicore_interrupt_m0_core();
		/* Try to push data if M4 is the master */
#elif defined(M4_MASTER) && !defined(M4_SLAVE)
		/* Send data to M0 */
		ipc_try_push(&data);
		/* Increment data to send */
		data++;
		/* Reset data when reaches 8 */
		if(data > 7) { data = 0; }
#endif
	}
}

int main(void) {
	/* Initialize board */
	ciaa_board_init();
    /* IPC quque initialization */
    ipc_queue_init(&data, sizeof(uint32_t), 1);
    /* Start M0 core */
    multicore_m0_start();
    /* Add callback function for the SysTick */
    systick_set_irq_handler(systick);
    /* Initialize SysTick at 10ms */
    systick_init(10000);

    while(1) {
    	/* Try to pop data if M4 is the slave */
#if defined(M4_SLAVE) && !defined(M4_MASTER)
    	/* Check if there is data to pop */
    	if(ipc_try_pop(&data) == queue_valid) {
    		/* Toggle LED3 for every value */
    		gpio_xor(LED3);
    		/* Toggle LED2 for values 0, 2, 4, 6 */
    		if(!(data % 2)) { gpio_xor(LED2); }
    		/* Toggle LED1 for values 0, 4 */
    		if(!(data % 4)) { gpio_xor(LED1); }
    	}
#endif
    }
}


/*
===============================================================================
 Name        : multicore_ipc_basic_m0app.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#include "ciaa_ipc_api.h"
#include "ciaa_board_api.h"

/* Define M0 function */
#define M0_SLAVE

/* Function to push a message into queue with timeout */
static ipc_status_t ipc_push_tout(void *data, int tout) {
	/* Point to shared memory */
	ipc_queue_t *qwr = (ipc_queue_t*) SHARED_MEM_IPC;
	/* Check if queue is initialized */
	if (!ipc_queue_is_valid(qwr)) { return queue_error; }
	/* Check if queue has space to push data */
	if ((tout == 0) && ipc_queue_is_full(qwr)) { return queue_full; }
	/* Wait for queue to have space with timeout */
	while (ipc_queue_is_full(qwr)) {
		if (ipc_event_handler()) { return queue_timeout; }
	}
	/* Push the item to the queue */
	return ipc_queue_push(qwr, data);
}

/* Function to read a message from queue with timeout */
static ipc_status_t ipc_pop_tout(void *data, int tout) {
	/* Point to shared memory */
	ipc_queue_t *qrd = (ipc_queue_t*) SHARED_MEM_IPC;
	/* Check if queue is initialized */
	if (!ipc_queue_is_valid(qrd)) { return queue_error; }
	/* Check if queue has data to pop */
	if ((tout == 0) && ipc_queue_is_empty(qrd)) { return queue_empty; }
	/* Wait for queue to have some data with timeout */
	while (ipc_queue_is_empty(qrd)) {
		if (ipc_event_handler()) { return queue_timeout; }
	}
	/* Pop the queue item */
	return ipc_queue_pop(qrd, data);
}

/* Push and pop with no timeout version */
static inline ipc_status_t ipc_try_push(void *data) { return ipc_push_tout(data, 0); }
static inline ipc_status_t ipc_try_pop(void *data) { return ipc_pop_tout(data, 0); }

/* Shared data */
uint32_t data = 0;

int main(void) {
	/* IPC quque initialization */
    ipc_queue_init(&data, sizeof(uint32_t), 1);
    /* Enable interrupts from M4 */
    multicore_m4_irq_set_enabled(true);

    while(1) {
    	/* Delay for the blue LED */
    	for(uint32_t i = 0; i < 100000; i++)
    		for(uint32_t j = 0; j < 4; j++);
    	/* Toggle blue LED */
    	gpio_xor(LEDB);

    	/* Try to pop data if M0 is the slave */
#if defined(M0_SLAVE) && !defined(M0_MASTER)
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

/* Try to push data if M0 is the master */
#if defined(M0_MASTER) && !defined(M0_SLAVE)
void M4_IRQHandler(void) {
	/* Clear interrupt from M4 */
	multicore_irq_clear();
	/* Send data to M4 */
	ipc_try_push(&data);
	/* Increment data */
	data++;
	/* Reset data when reaches 8 */
	if(data > 7) { data = 0; }
}
#endif

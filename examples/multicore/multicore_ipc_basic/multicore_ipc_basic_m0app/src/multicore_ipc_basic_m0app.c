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
#include "ciaa_gpio_api.h"

/* Define M0 function */
#define M0_SLAVE

/* Function to push a message into queue with timeout */
int push(void *data, int tout) {

	ipc_queue_t *qwr;

	qwr = (ipc_queue_t*) SHARED_MEM_IPC;

	/* Check if write queue is initialized */
	if (!ipc_queue_is_valid(qwr)) { return queue_error; }

	if ((tout == 0) && ipc_queue_is_full(qwr)) { return queue_full; }

	/* Wait for read queue to have some data */
	while (ipc_queue_is_full(qwr)) {
		if (ipc_event_handler()) { return queue_timeout; }
	}

	qwr->data = data;

	memcpy(qwr->data + ((qwr->head & (qwr->count - 1)) * qwr->size), data, qwr->size);
	qwr->head++;

	return queue_insert;
}

/* Function to read a message from queue with timeout */
int pop(void *data, int tout) {

	ipc_queue_t *qrd;

	qrd = (ipc_queue_t*) SHARED_MEM_IPC;

	if (!ipc_queue_is_valid(qrd)) { return queue_error; }

	if ((tout == 0) && ipc_queue_is_empty(qrd)) { return queue_empty; }

	while (ipc_queue_is_empty(qrd)) {
		if (ipc_event_handler()) { return queue_timeout; }
	}

	/* Pop the queue Item */
	memcpy(data, qrd->data + ((qrd->tail & (qrd->count - 1)) * qrd->size), qrd->size);
	qrd->tail++;
	data = qrd->data;

	return queue_valid;
}

/* Shared data */
uint32_t data = 0;

int main(void) {
	/* Update system clock */
	SystemCoreClockUpdate();
	/* IPC quque initialization */
    ipc_queue_init(&data, sizeof(uint32_t), 1);
    /* Enable interrupts from M4 */
    multicore_m4_irq_set_enabled(true);

    while(1) {

    	for(uint32_t i = 0; i < 100000; i++)
    		for(uint32_t j = 0; j < 4; j++);

    	gpio_xor(LEDB);

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

/*
 * ciaa_ipc_api.c
 *
 *  Created on: Aug 27, 2022
 *      Author: carlassaraf
 */

#include "ciaa_ipc_api.h"

static ipc_queue_t *q_ipc = (ipc_queue_t*) SHARED_MEM_IPC;

/* Initialize the IPC queue */
void ipc_queue_init(void *data, int size, int count) {

	ipc_queue_t *qrd;

	/* Sanity Check */
	if (!size || !count || !data) { while (1); }

	/* Check if size is a power of 2 */
	if (count & (count - 1)) { while (1); }

	qrd = q_ipc;

	memset(qrd, 0, sizeof(*qrd));
	qrd->count = count;
	qrd->size = size;
	qrd->data = data;
	qrd->valid = QUEUE_MAGIC_VALID;
}

/* Function to push a message into queue with timeout */
int ipc_push_tout(const void *data, int tout) {

	ipc_queue_t *qwr = q_ipc;

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
int ipc_pop_tout(void *data, int tout) {

	ipc_queue_t *qrd = q_ipc;

	if (!ipc_queue_is_valid(qrd)) { return queue_error; }

	if ((tout == 0) && ipc_queue_is_empty(qrd)) { return queue_empty; }

	while (ipc_queue_is_empty(qrd)) {
		if (ipc_event_handler()) {
			return queue_timeout;
		}
	}

	/* Pop the queue Item */
	memcpy(data, qrd->data + ((qrd->tail & (qrd->count - 1)) * qrd->size), qrd->size);
	qrd->tail++;
	data = qrd->data;

	return queue_valid;
}

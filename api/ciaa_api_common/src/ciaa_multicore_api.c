/*
 * ciaa_multicore_api_m4.c
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#include "ciaa_multicore_api.h"

/* Array of IPC Event callback functions */
static void(*ipc_callback_lookup[IPC_MAX_PID]) (const ipc_msg_t*);
/* Message QUEUE used by IPC library to exchange message between cores */
static ipc_msg_t ipc_queue[IPC_QUEUE_SZ];
/* IPC Shared global variables */
static uint32_t g_cfg[IPC_MAX_GBLCFG];
/* Function pointer to store notification pointer */
static ipc_global_update_function_t g_updater;
/* M4/M0 shared queue */
static ipc_queue_t *ipc_shared_queue = (ipc_queue_t*) SHARED_MEM_IPC;
/**
 * @brief	Pointer to a call back function
 * The function pointed by EVENT_IPC_RxHandler will be at the end of Rx ISR
 */
int (*ipc_event_handler)(ipc_event_t, uint16_t, int);



/* This task will receive the message from the other core
 * and will invoke the appropriate callback with the message
 */
static void ipc_dispatch_task(void *unused) {
	int ret;
	ipc_msg_t msg;
	do {
		ret = ipc_msg_try_pop(&msg);
		if ((ret != QUEUE_VALID) || (msg.id.pid >= IPC_MAX_PID)) {
			continue;
		}
		if (ipc_callback_lookup[msg.id.pid]) {
			ipc_callback_lookup[msg.id.pid](&msg);
		}
	} while(0);
}

/* Call back function to update the global variable */
static void ipc_global_update(const ipc_msg_t *msg) {
	if (msg->data0 >= IPC_MAX_GBLCFG) {
		return;
	}
	g_cfg[msg->data0] = msg->data1;

	/* Call registered functions */
	if (g_updater) {
		g_updater((int) msg->data0);
	}
}

/* Simple event handler for non OS implementations */
static int ipc_event_handler_implementation(ipc_event_t event, uint16_t cpu, int tout) {
	__WFI();
	return 0;
}

/*
 *	@brief	IPC initialization function
 *
 *	@param	None
 *
 *	@return	None
 */
void ipc_init(void) {
	/* Initialize queue */
	ipc_queue_init(ipc_queue, sizeof(ipc_msg_t), IPC_QUEUE_SZ);
	/* Register updater function */
	ipc_register_callback(PID_GBLUPDATE, ipc_global_set);
}

/*
 * @brief	Function to initialize the IPC message queue
 *
 * @param	data: pointer to the array of messages
 * @param	size: size of the single data element in queue
 * @param	count: maximum number of items that can be stored in Queue. Must be power of two
 *
 * @return	None
 */
void ipc_queue_init(void *data, int size, int count) {
	ipc_queue_t *qrd;
	if (ipc_queue_sanity_check(data, size, count)) { while (1); }
	/* Get address of shared queue */
	qrd = &ipc_shared_queue[CPUID_CURR];
	/* Set to null */
	memset(qrd, 0, sizeof(*qrd));
	/* Set number of elements */
	qrd->count = count;
	/* Set size of items */
	qrd->size = size;
	/* Pointer to the data */
	qrd->data = data;
	/* Valid code */
	qrd->valid = QUEUE_MAGIC_VALID;
	/* Set event handler */
	if (!ipc_event_handler) { ipc_event_handler = ipc_event_handler_implementation; }
}

/*
 * @brief	IPC register callback function pointer. Whenever a message with
 *			id is received the register call-back function will be invoked.
 *
 * @param	pid: ID of message to which the callback func be associated
 * @param	func: pointer to callback function
 *
 * @return	0 on failure [given \a id is greater than
 */
int ipc_register_callback(uint16_t pid, void (*func)(const ipc_msg_t *)) {
	/* Check if the ID message is valid */
	if (pid < IPC_MAX_PID) {
		/* Register callback */
		ipc_callback_lookup[pid] = func;
	}
	return 0;
}

/* IPC example implementation task */
void ipc_tasks(void) {
	sys_taskCreate(ipc_dispatch_task, SYS_OS_ID, "IPC Ex", TASK_PRIO_IPC_DISPATCH);
}

/* Sets value of an M0-M4 shared global variable */
int ipc_global_set(int index, uint32_t val) {
	cpu_id_t i;
	int ret = 0;
	for (i = CPUID_MIN; i < CPUID_MAX; i++) {
		if (i == CPUID_CURR) {
			g_cfg[index] = val;
			if (g_updater) {
				g_updater(index);
			}
		}
		else {
			ipc_msg_t msg;
			msg.id.cpu = (uint16_t) i;
			msg.id.pid = PID_GBLUPDATE;
			msg.data0 = (uint32_t) index;
			msg.data1 = val;
			ret |= (ipc_msg_push(i, &msg) != QUEUE_INSERT) << msg.id.cpu;
		}
	}
	return 0;
}

/* Gets value of an M0-M4 shared global variable */
uint32_t ipc_global_get(int index) {
	if (index < IPC_MAX_GBLCFG) { return g_cfg[index]; }
	return 0;
}

/* Shared global variable update notification register function */
ipc_global_update_function_t ipc_global_register_function(ipc_global_update_function_t fn) {
	/* Save old updater */
	ipc_global_update_function_t old = g_updater;
	/* Replace with new function */
	g_updater = fn;
	/* Return old function */
	return old;
}

/* Function to send notificaton interrupt */
void ipc_msg_notify(void) {
	//ipc_send_signal();
}

/* Function to push a message into queue with timeout */
int ipc_msg_push_timeout(uint16_t cpuid, const void *data, int tout) {
	ipc_queue_t *qwr = &ipc_shared_queue[cpuid];

	/* Check if write queue is initialized */
	if (!ipc_queue_is_valid(qwr)) {
		return QUEUE_ERROR;
	}

	if ((tout == 0) && ipc_queue_is_full(qwr)) {
		return QUEUE_FULL;
	}

	/* Wait for read queue to have some data */
	/* This one had full, not empty */
	while (ipc_queue_is_full(qwr)) {
		if (ipc_event_handler(IPC_EVENT_WAIT_TX, cpuid, tout) && (tout > 0)) {
			return QUEUE_TIMEOUT;
		}
	}

	memcpy(qwr->data + ((qwr->head & (qwr->count - 1)) * qwr->size), data, qwr->size);
	qwr->head++;
	//ipc_send_signal();

	return QUEUE_INSERT;
}

/* Function to read a message from queue with timeout */
int ipc_msg_pop_timeout(void *data, int tout) {
	ipc_queue_t *qrd   = &ipc_shared_queue[CPUID_CURR];
	int raise_event = ipc_queue_is_full(qrd);

	if (!ipc_queue_is_valid(qrd)) {
		return QUEUE_ERROR;
	}

	if ((tout == 0) && ipc_queue_is_empty(qrd)) {
		return QUEUE_EMPTY;
	}

	while (ipc_queue_is_empty(qrd)) {
		if (ipc_event_handler(IPC_EVENT_WAIT_RX, CPUID_CURR, tout) && (tout > 0)) {
			return QUEUE_TIMEOUT;
		}
	}

	/* Pop the queue Item */
	memcpy(data, qrd->data + ((qrd->tail & (qrd->count - 1)) * qrd->size), qrd->size);
	qrd->tail++;

	if (raise_event) {
		//ipc_send_signal();
	}
	return QUEUE_VALID;
}

/* Get number of pending items in queue */
int ipc_msg_pending(uint16_t cpu) {
	ipc_queue_t *q = &ipc_shared_queue[cpu];
	if (!ipc_queue_is_valid(q)) {
		return QUEUE_ERROR;
	}

	return ipc_queue_data_count(q);
}

/* Function to convert IPC error number to string */
const char *ipc_err_str(int errnum) {
	static const char *ipc_errstr[] = {
		"Queue Insert OK",
		"Queue Pop OK/Valid",
		"Queue is Full",
		"Queue is Empty",
		"Queue Error/Not initialized",
		"Queue operation timed out",
	};
	if (errnum < 0) {
		errnum = 1 - errnum;
	}
	return ipc_errstr[errnum];
}


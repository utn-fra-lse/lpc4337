/*
 * ciaa_ipc_api.h
 *
 *  Created on: Aug 27, 2022
 *      Author: carlassaraf
 */

#ifndef CIAA_IPC_API_H_
#define CIAA_IPC_API_H_

#include <string.h>
#include "ciaa_multicore_api.h"

/**
 * @brief IPC Queue Structure used for sync between M0 and M4.
 *
 * This structure provides head and tail indexes
 * to the uint32_t array of messages.
 */
typedef struct {
	int32_t size;				/* Size of a single item in queue */
	int32_t count;				/* Total number of elements that can be stored in the queue */
	volatile uint32_t head;		/* Head index of the queue */
	volatile uint32_t tail;		/* Tail index of the queue */
	uint8_t *data;				/* Pointer to the data */
	uint32_t valid;				/* Queue is valid only if this is #QUEUE_MAGIC_VALID */
	uint32_t reserved[2];		/* Reserved entry to keep the structure aligned */
} ipc_queue_t;


typedef enum {
	queue_timeout = -4,	/* Push/pop action timeout */
	queue_error = -3,	/* Queue was not initialized */
	queue_empty = -2,	/* Queue is empty, pop failed */
	queue_full = -1,	/* Queue is full, insert failed */
	queue_insert = 0,	/* Item successfully inserted */
	queue_valid = 1		/* Item successfully fetched */
} ipc_status_t;

/**
 * \def QUEUE_MAGIC_VALID
 * Macro used to identify if a queue is valid
 */
#define QUEUE_MAGIC_VALID  0xCAB51053

/**
 * @brief	Function to push a message into queue with timeout
 *
 * This function will push an message of size \a size, specified by
 * IPC_initMsgQueue. If this function is called from M4 Core the message
 * will be pushed to M4 Queue and will be popped by M0, and vice-versa.
 *
 * @param   cpuid   : ID of the CPU which will receive the message
 * @param	data	: Pointer to data to be pushed
 * @param	tout	: non-zero value - timeout value in milliseconds,
 *                      zero value - no blocking,
 *                      negative value - blocking
 * @return  #QUEUE_INSERT on success,
 * @note	#QUEUE_FULL or #QUEUE_ERROR on failure,
 *          #QUEUE_TIMEOUT when there is a timeout
 */
int ipc_push_tout(const void *data, int tout);

/**
 * @brief	Function to read a message from queue with timeout
 *
 * This function will pop a message of size \a size, specified by
 * IPC_initMsgQueue of the other core. If this function is called from
 * M4 Core the message will be popped from M0 Queue and vice-versa.
 *
 * @param	data	: Pointer to store popped data
 * @param	tout	: non-zero value - timeout value in milliseconds,
 *                      zero value - no blocking,
 *                      negative value - blocking
 * @return	#QUEUE_VALID on success,
 * @note	#QUEUE_EMPTY or #QUEUE_ERROR on failure,
 *          #QUEUE_TIMEOUT when there is a timeout
 */
int ipc_pop_tout(void *data, int tout);

/**
 * @brief	Get number of pending items in queue
 *
 * This function will get the number of pending items in the queue. If
 * this function is called by M4 core with param \a queue_write set to
 * non zero then this function will return the number of messages waiting
 * in M4's Push Queue that is yet to be popped by the M0 core, or vice versa.
 * If this function is called by M4 core with param \a queue_write set to
 * zero then it returns the number of elements that can be popped without
 * waiting (in other words number of messages pending in the M0's Push queue
 * that is yet to be popped by M4 core), or vice versa.
 *
 * @param	cpu		: ID of the CPU for which the status is requested
 * @return	On success - Number of elements in queue (which will be >= 0),
 * @note	On Error   - #QUEUE_ERROR (when queue is not initialized/valid)
 */
/**
 * \def IPCEX_MAX_GBLCFG
 * Maximum number of synchronized global variables
 */
int ipc_pending(void);

/**
 * @brief	Function to initialize the IPC message queue
 *
 * This function intializes the interprocessor communication message queue.
 * **IMPORTANT NOTE: \a MaxNoOfMsg must always be a power of 2.**
 *
 * @param	data	: Pointer to the array of messages of size \a msgSize
 * @param	msgSize	: Size of the single data element in queue
 * @param	maxNoOfMsg	: Maximum number of items that can be stored in Queue
 * @return	None, will not return if there is error in given arguments
 */
void ipc_queue_init(void *data, int size, int count);


/**
 * @brief	Function to push the message into queue with no wait
 *
 * The function tries to push the \a data to the IPC queue. If the
 * queue is full, it will return without blocking. It is equivalent
 * to calling IPC_pushMsgTout(data, 0).
 *
 * @param   cpuid   : ID of the CPU which will receive the message
 * @param	data	: Pointer to data to be pushed
 * @return	#QUEUE_INSERT on success, #QUEUE_FULL or #QUEUE_ERROR on failure
 */
static inline int ipc_try_push(const void *data) { return ipc_push_tout(data, 0); }

/**
 * @brief	Function to pop the message from queue with no wait
 *
 * The function tries to pop the data from the IPC queue. If the queue is empty,
 * it will return without blocking.
 *
 * @param	data	: Pointer to store popped data
 * @return	#QUEUE_VALID on success, #QUEUE_ERROR or #QUEUE_EMPTY on failure
 */
static inline int ipc_try_pop(void *data) { return ipc_pop_tout(data, 0); }

/**
 * @brief	Function to push the message into queue with wait
 *
 * The function to push the data to the IPC queue. If the queue is full, it will
 * wait till data is pushed (blocking).
 *
 * @param   cpuid   : ID of the CPU which will receive the message
 * @param	data	: Pointer to data to be pushed
 * @return	#QUEUE_INSERT on success, #QUEUE_ERROR on failure
 */
static inline int ipc_push(const void *data) { return ipc_push_tout(data, -1); }

/**
 * @brief	Function to pop the message from queue with wait
 *
 * The function will pop the data from the IPC queue. If the queue is empty,
 * it will wait (blocking) till the data is available.
 *
 * @param	data	: Pointer to store popped data
 * @return	status	: Pop status
 */
static inline int ipc_pop(void *data) { return ipc_pop_tout(data, -1); }

/* Simple event handler for non OS implementations */
static inline int ipc_event_handler(void) {
	__WFI();
	return 0;
}

/**
 * \def QUEUE_DATA_COUNT(q)
 * This macro will get the number of items pending in \a q
 */
static inline uint32_t ipc_queue_data_count(ipc_queue_t *q) {
	return ((uint32_t) ((q)->head - (q)->tail));
}

/**
 * \def QUEUE_IS_FULL(q)
 * This macro will evaluate to 1 if queue \a q is full, 0 if it is not
 */
static inline bool ipc_queue_is_full(ipc_queue_t *q) {
	return (ipc_queue_data_count(q) >= (q)->count);
}

/**
 * \def QUEUE_IS_EMPTY(q)
 * This macro will evaluate to 1 if queue \a q is empty, 0 if it is not
 */
static inline bool ipc_queue_is_empty(ipc_queue_t *q) {
	return ((q)->head == (q)->tail);
}

/**
 * \def QUEUE_IS_VALID(q)
 * This macro will evaluate to 1 if queue \a q is initialized & valid, 0 if it is not
 */
static inline bool ipc_queue_is_valid(ipc_queue_t *q) {
	return ((q)->valid == QUEUE_MAGIC_VALID);
}

#endif /* CIAA_IPC_API_H_ */

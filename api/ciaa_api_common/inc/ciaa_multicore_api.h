/*
 * ciaa_multicore_api_m4.h
 *
 *  Created on: Jun 16, 2022
 *      Author: fabri
 */

#ifndef CIAA_MULTICORE_API_H_
#define CIAA_MULTICORE_API_H_

#include "chip.h"
#include <string.h>

#define LPC43XX_CORE_M0APP

#define SYS_OS_ID	0


#define sys_taskCreate(tsk, arg, name, prio) tsk(arg)

typedef enum CPUID {
	CPUID_MIN,
	CPUID_M4 = CPUID_MIN,
	CPUID_M0APP,
	CPUID_M0SUB,
	CPUID_MAX
} cpu_id_t;

#ifdef LPC43XX_CORE_M0APP
#define CPUID_CURR     CPUID_M0APP
#endif

#define SYS_OS_ID      0/* 0 - No OS, 1 - FreeRTOS, 2 - UCOS-III */

/* Size of applications in flash */
#define IMG_SZ_M4      (32 * 1024)
#define IMG_SZ_M0APP   (16 * 1024)

#define SPIFI_BASE_ADDR     0x14000000	/* SPIFI BASE ADDR */
#define IFLASH_A_BASE_ADDR  0x1A000000	/* IFLASH BANK-A */
#define IFLASH_B_BASE_ADDR  0x1B000000	/* IFLASH BANK-B */

#define SHARED_MEM_IPC      0x10088000	/* Shared memory used by IPC */

#define BASE_ADDRESS_M0APP     (IFLASH_B_BASE_ADDR)

/* Size of the IPC Queue. Can be overridden */
#define IPC_QUEUE_SZ	64
/* Maximum number of message IDs that this IPC examples uses */
#define IPC_MAX_PID		20
/* Maximum number of synchronized global variables */
#define IPC_MAX_GBLCFG	8
/* Update global variable or other core */
#define PID_GBLUPDATE	1

/* IPC Function return values */
/* Returned when an item is successfully fetched */
#define QUEUE_VALID      1
/* Returned when an item is successfully inserted into the queue */
#define QUEUE_INSERT     0
/* Returned when an attempt is made to insert item into a full queue. */
#define QUEUE_FULL      -1
/* Returned when an attempt is made to fetch/pop an item from an empty queue. */
#define QUEUE_EMPTY     -2
/* Returned when an push/pop is made to a queue which was not initialized */
#define QUEUE_ERROR     -3
/* Returned when a push/pop operation did not complete within a given time. */
#define QUEUE_TIMEOUT   -4
/* Macro used to identify if a queue is valid */
#define QUEUE_MAGIC_VALID   0xCAB51053

typedef enum {
	IPC_EVENT_WAIT_TX,
	IPC_EVENT_WAIT_RX,
} ipc_event_t;

typedef struct {
	struct {
		uint16_t cpu;
		uint16_t pid;
	} id;
	uint32_t data0;
	uint32_t data1;
} ipc_msg_t;

/*
 * @brief IPC Queue Structure used for sync between M0 and M4.
 *
 * This structure provides head and tail indexes
 * to the uint32_t array of messages.
 */
typedef struct {
	int32_t size;				/* Size of a single item in queue */
	int32_t count;				/* Toal number of elements that can be stored in the queue */
	volatile uint32_t head;		/* Head index of the queue */
	volatile uint32_t tail;		/* Tail index of the queue */
	uint8_t *data;				/* Pointer to the data */
	uint32_t valid;				/* Queue is valid only if this is #QUEUE_MAGIC_VALID */
	uint32_t reserved[2];		/* Reserved entry to keep the structure aligned */
} ipc_queue_t;

/* M0-M4 Shared variable update notification function type */
typedef void (*ipc_global_update_function_t)(int);

/* Function prototypes */
void ipc_init(void);
void ipc_queue_init(void *data, int msgSize, int maxNoOfMsg);
int ipc_register_callback(uint16_t pid, void (*func)(const ipc_msg_t *));

/**
 * @brief	Sets the value of a shared global variable
 * @param	index	: index of the shared variable
 * @param	val		: Value of the shared global variable
 * @return	0 on success 1 on error
 */
int ipc_global_set(int index, uint32_t val);

/**
 * @brief	Read a shared global variable
 * @param	index	: Index of the shared variable
 * @return	Value of the shared variable
 */
uint32_t ipc_global_get(int index);

/**
 * @brief		Register notification function for shared global value update
 * @param		newfn		: New function pointer that will handle notification
 * @return		Old function pointer that was handling the notfication
 * @note		The new function, after completing the handling of shared global
 * variable change, **MUST** call the old function handler if it is not NULL.
 */
ipc_global_update_function_t ipc_global_register_function(ipc_global_update_function_t fn);

/* Multicore inline functions */

/*
 * 	@brief	Enable/Disbale M4 interrupt for M0 core
 *
 * 	@param	enabled: whether to enable or disable
 *
 * 	@return	None
 */
static inline void multicore_irq_set_enabled(bool enabled) {
#ifdef CORE_M0
	if(enabled) { NVIC_EnableIRQ(M4_IRQn); }
	else { NVIC_DisableIRQ(M4_IRQn); }
#elif defined(CORE_M4)
	if(enabled) { NVIC_EnableIRQ(M0APP_IRQn); }
	else { NVIC_DisableIRQ(M0APP_IRQn); }
#endif

}

/*
 * Initiate interrupt on other processor
 * Upon calling this function generates and interrupt on the other
 * core. Ex. if called from M0 core it generates interrupt on M4 core
 * and vice versa.
 */
#ifdef CORE_M0
static inline void multicore_interrupt_m4_core(void) {
#elif defined(CORE_M4)
static inline void multicore_interrupt_m0_core(void) {
#endif
	__DSB();
	__SEV();
}

static inline bool ipc_queue_sanity_check(void *data, int size, int count) {
	/* Sanity Check */
	if(!size || !count || !data) { return -1; }
	/* Check if size is a power of 2 */
	if(count & (count - 1)) { return -2; }
	else { return 0; }
}

/* Queue status inline functions */

/*
 * @brief	Get the number of items pending
 *
 * @param	queue: IPC queue to check
 *
 * @return	number of items pending
 */
static inline uint32_t ipc_queue_data_count(ipc_queue_t *queue) { return ((uint32_t) ((queue)->head - (queue)->tail)); }

/*
 * @brief	Check if queue is full
 *
 * @param	queue: IPC queue to check
 *
 * @return	true if full, false if not
 */
static inline bool ipc_queue_is_full(ipc_queue_t *queue) { return (ipc_queue_data_count(queue) >= (queue)->count); }

/*
 * @brief	Check if queue is empty
 *
 * @param	queue: IPC queue to check
 *
 * @return	true if empty, false if not
 */
static inline bool ipc_queue_is_empty(ipc_queue_t *queue) { return ((queue)->head == (queue)->tail); }

/*
 * @brief	Check if queue is valid
 *
 * @param	queue: IPC queue to check
 *
 * @return	true if valid, false if not
 */
static inline bool ipc_queue_is_valid(ipc_queue_t *queue) { return ((queue)->valid == QUEUE_MAGIC_VALID); }

/**
 * @brief	Pointer to a call back function
 * @param	event	: Event ID see #IPC_EVENT_T
 * @param   cpu		: ID of the CPU
 * @param	tout	: Timout value
 * @return  0 on success and 1 on timeout/failure
 */
extern int (*ipc_event_handler)(ipc_event_t event, uint16_t cpu, int tout);

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
int ipc_msg_push_timeout(uint16_t cpuid, const void *data, int tout);

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
int ipc_msg_pop_timeout(void *data, int tout);

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
static inline int ipc_msg_try_push(uint16_t cpuid, const void *data) { return ipc_msg_push_timeout(cpuid, data, 0); }

/**
 * @brief	Function to pop the message from queue with no wait
 *
 * The function tries to pop the data from the IPC queue. If the queue is empty,
 * it will return without blocking.
 *
 * @param	data	: Pointer to store popped data
 * @return	#QUEUE_VALID on success, #QUEUE_ERROR or #QUEUE_EMPTY on failure
 */
static inline int ipc_msg_try_pop(void *data) { return ipc_msg_pop_timeout(data, 0); }

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
static inline int ipc_msg_push(uint16_t cpuid, const void *data) { return ipc_msg_push_timeout(cpuid, data, -1); }

/**
 * @brief	Function to pop the message from queue with wait
 *
 * The function will pop the data from the IPC queue. If the queue is empty,
 * it will wait (blocking) till the data is available.
 *
 * @param	data	: Pointer to store popped data
 * @return	status	: Pop status
 */
static inline int ipc_msg_pop(void *data) { return ipc_msg_pop_timeout(data, -1); }

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
int ipc_msg_pending(uint16_t cpu);

/**
 * @brief	Function to send notificaton interrupt
 *
 * When called from the M0, it sends the notification interrupt to M4 and vice-versa.
 *
 * @return	None
 */
void ipc_msg_notify(void);

/**
 * @brief	Function to convert IPC error number to string
 *
 * This function returns the error string for the error value.
 *
 * @param	errnum : IPC error value
 * @return	pointer to error string
 */
const char *ipc_err_str(int errnum);

#endif /* CIAA_MULTICORE_API_H_ */

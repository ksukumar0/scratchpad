#ifndef HM_SRT_BATTERY_BUFFER_H_
#define HM_SRT_BATTERY_BUFFER_H_

#include <stdint.h>
#include <stdbool.h>

#define NUMBER_OF_VOLTAGE_MEASUREMENTS 16
#define EMPTY_BATTERY_VOLTAGE_THRESHOLD_MV 4750
typedef uint16_t voltage_mV_t;

typedef struct {
	voltage_mV_t voltage_measurements[NUMBER_OF_VOLTAGE_MEASUREMENTS];
	/* head can also be used as a counter reference for total number of entries to date */
	uint64_t head;
	bool full;
} circular_buffer_t;

/**
 *	\brief	Clears the buffer and initialises all field to zeros
 */
void
hm_srt_battery_buffer_clear(void);

/**
 *	\brief A function to read the number of occupied slots in the buffer
 *  \return returns the occupied size of the buffer
 */
uint32_t
hm_srt_battery_buffer_get_size(void);

/**
 *	\brief Gets the maximum voltage measurement entry in the buffer
 *	\param voltage_mv is a pointer where the maximum value of the
 *	voltage in the last NUMBER_OF_VOLTAGE_MEASUREMENTS readings
 *	is copied to.
 *	\return returns a uint32_t, that reflects which past reading
 *	the value copied into voltage_mv corresponds to.
 */
uint32_t
hm_srt_battery_buffer_get_maximum(voltage_mV_t *voltage_mv);

/**
 *	\brief Adds new reading to the buffer. If the buffer is not yet
 *	full the reading is appended, and if its full the last reading is
 *	overwritten
 *	\param voltage_mv new reading to add to the circular buffer
 *	\return number of elements in the list
 */
uint32_t
hm_srt_battery_buffer_put_item(voltage_mV_t voltage_mv);


void printArray(void);
circular_buffer_t * getArrayPtr(void);


#endif /* HM_SRT_BATTERY_BUFFER_H_ */

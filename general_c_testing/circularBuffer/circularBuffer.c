#include "circularBuffer.h"
#include <string.h>

static circular_buffer_t buf;

void
hm_srt_battery_buffer_clear(void)
{
	memset(&buf, 0, sizeof(buf));
}

uint32_t
hm_srt_battery_buffer_get_size(void)
{
	return buf.full ? NUMBER_OF_VOLTAGE_MEASUREMENTS : buf.head%NUMBER_OF_VOLTAGE_MEASUREMENTS;
}

uint32_t
hm_srt_battery_buffer_get_maximum(voltage_mV_t *voltage_mv)
{
	int i;
	voltage_mV_t max_voltage_mv = buf.voltage_measurements[0];
	uint32_t index;

	/* complexity of O(n) */
	for (i = 1; i < NUMBER_OF_VOLTAGE_MEASUREMENTS; i++) {
		if (max_voltage_mv <= buf.voltage_measurements[i]) {
			max_voltage_mv = buf.voltage_measurements[i];
			index = i;
		}
	}
	if (buf.head > index)
		return buf.head - index;
	else
		return NUMBER_OF_VOLTAGE_MEASUREMENTS + index - buf.head;
}

uint32_t
hm_srt_battery_buffer_put_item(voltage_mV_t voltage_mv)
{
	buf.voltage_measurements[(buf.head%NUMBER_OF_VOLTAGE_MEASUREMENTS)] = voltage_mv;
	/* buf.head represents the total number of added elements in the buffer */
	buf.head++;

	/* Increment the counter in the structure to reflect the number of elements*/
	if (buf.head >= NUMBER_OF_VOLTAGE_MEASUREMENTS)
		buf.full = true;

	return hm_srt_battery_buffer_get_size();
}

circular_buffer_t * getArrayPtr(void)
{
    return &buf;
}

#include "circularBuffer.h"
#include <stdio.h>

static
void printArray(void)
{
    circular_buffer_t *buf = getArrayPtr();
    int i;
    for(i=0;i<NUMBER_OF_VOLTAGE_MEASUREMENTS;i++)
    {
        printf("%d ",buf->voltage_measurements[i]);
    }
    printf("\nHead: %ld",buf->head);
    printf("\nFull: %d",buf->full);
    printf("\nSize: %d\n",hm_srt_battery_buffer_get_size());
}

int main(void)
{
    hm_srt_battery_buffer_clear();
    printArray();

    hm_srt_battery_buffer_put_item(3400);
    hm_srt_battery_buffer_put_item(3500);
    hm_srt_battery_buffer_put_item(3600);
    hm_srt_battery_buffer_put_item(3700);
    hm_srt_battery_buffer_put_item(3800);
    hm_srt_battery_buffer_put_item(3900);
    hm_srt_battery_buffer_put_item(4000);
    hm_srt_battery_buffer_put_item(4100);
    hm_srt_battery_buffer_put_item(4200);
    hm_srt_battery_buffer_put_item(4300);
    hm_srt_battery_buffer_put_item(4400);
    hm_srt_battery_buffer_put_item(4500);
    hm_srt_battery_buffer_put_item(4600);
    hm_srt_battery_buffer_put_item(4700);
    hm_srt_battery_buffer_put_item(4800);
    hm_srt_battery_buffer_put_item(4900);
    hm_srt_battery_buffer_put_item(5000);
    hm_srt_battery_buffer_put_item(5100);

    printArray();
    return 0;
}

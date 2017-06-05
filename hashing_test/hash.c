#include<stdio.h>
#include<string.h>
#include "hashlib.h"

#define INDEXMAX 45
#define NUMBER_OF_TRIES 19
// Helper function to construct the key for the hash function
static void construct_key( unsigned int vaddr, unsigned int pid , unsigned char* ptr )
{
    int i;
    for(i=0;i<8;i++)
    {
        if(i<4)
            ptr[i] = ( vaddr >> i*8 ) & 0xff;
        else
            ptr[i] = ( pid >> (i-4)*8 ) & 0xff;
    }
}

int main (int argc, char *argv[])
{
    unsigned int a = 0x11111000;
    unsigned int b = 0x99aaffff;
    unsigned char ptr[8];

    construct_key(a,b,ptr);
    int j=0;
    while(j<8)
    {
        printf("PTR[%d] is %d\n",j,(int) ptr[j]);
        j++;
    }
    j = 0;
    while(j<NUMBER_OF_TRIES)
    {
        construct_key(a,b,ptr);
        printf("%u %u index is %d\n",a,b,calculate_hash(ptr,8,INDEXMAX));
        j++;
        //a++;
        b++;
    }
    return 0;
}

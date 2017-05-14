#include<stdio.h>
#include<string.h>

int main (int argc, char *argv[])
{
    unsigned int a = 0xffffafff;
    unsigned int b = 0x0000ffff;
    printf("%u\n",a);
    printf("%u\n",b);
    unsigned int c[2];
    c[0] = a;
    c[1] = b;
    unsigned char ptr[4];
    ptr[0] = a & 0xff;
    printf("PTR is %d\n",(int) ptr[0]);
    return 0;
}

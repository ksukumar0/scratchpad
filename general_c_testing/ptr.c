#include<stdio.h>

int main (int argc, char *argv[])
{
    const int NOENTRIES = 100;
    int c[NOENTRIES];
    unsigned int (*arrptr)[10];
    arrptr = (unsigned int(*)[10]) c;

    for ( int i=0;i<NOENTRIES;i++)
        c[i] = i;

    for (int i=0;i<10;i++)
    {
        printf("Arrptr + %d points to %u\n",i,**(arrptr++));
    }
    return 0;
}

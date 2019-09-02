#include<stdio.h>

static int localVar = 0;

void print1(int a, int b, int c)
{
    localVar = 1;
    printf("In print1\n");
    printf("localVar is %d, a=%d, b=%d, c=%c\n", localVar,a,b,c);
}

void print2(int a, int b, int c, int d, int e)
{
    localVar = 2;
    printf("In print2\n");
    printf("localVar is %d, a=%d, b=%d, c=%d, d=%d, e=%d\n", localVar,a,b,c,d,e);
}

void print3(int a, int b, int c)
{
    localVar = 3;
    printf("In print3\n");
    printf("localVar is %d, a=%d, b=%d, c=%c\n", localVar,a,b,c);
}

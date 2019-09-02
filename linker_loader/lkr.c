#include<stdio.h>

void arraysVsPtrs(void)
{
    const int NOENTRIES = 100;
    int c[NOENTRIES];
    unsigned int (*arrptr)[10];
    unsigned int *(ap[NOENTRIES]);
    arrptr = (unsigned int(*)[10]) c;

    for ( int i=0;i<NOENTRIES;i++)
    {
        c[i] = i;
        ap[i] = c + i;
    }

    for (int i=0;i<10;i++)
    {
        printf("Arrptr + %d points to %u\n",i,**(arrptr++));
        printf("ap[%d] is %d\n",i+10,*ap[i+10]);
    }
    return;
}

void const_ptrs(void)
{
    const char c1 = 'a',c2 = 'b';
    char * const h = &c1;
    printf("c1=%c c2=%c &c1=%x &c2=%x *h=%c h=%x\n",c1,c2,&c1,&c2,*h,h);
    //h = &c2;
    *h = 'c';
    printf("c1=%c c2=%c &c1=%x &c2=%x *h=%c h=%x\n",c1,c2,&c1,&c2,*h,h);
    return;
}

int ans;

int* add(int a, int b)
{
    ans = a+b;
    return &ans;
}

int* mul(int a, int b)
{
    ans = a*b;
    return &ans;
}

void func_ptrs(void)
{
    int a = 10,b = 11;
    int* (*(f[2]))(int,int);
    f[1] = &add;
    printf("This is f=add and *f(a,b) is %d\n",*(f[1](a,b)));
    f[2] = &mul;
    printf("This is f=mul and *f(a,b) is %d\n",*(f[2](a,b)));
    return;
}

int main (int argc, char *argv[])
{
    //arraysVsPtrs();
    //const_ptrs();
    //func_ptrs();
    print2(3,43,5,6,7);
    return 0;
}

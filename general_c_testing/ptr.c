#include<stdio.h>

void arraysVsPtrs(void)
{
    const int NOENTRIES = 100;
    int c[NOENTRIES];
    unsigned int (*arrptr)[10];
    unsigned int *(ptrarr[10]);
    unsigned int *(ap[NOENTRIES]);
    arrptr = (unsigned int(*)[10]) c;
    
    int count = 0;

    for ( int i=0;i<NOENTRIES;i++)
    {
        c[i] = i;
        ap[i] = c + i;
        if(i%10 == 0)
            ptrarr[i/10] = &c[i/10];;
    }

    for (int i=0;i<10;i++)
    {
        printf("Arrptr + %d points to %u\n",i,*(arrptr[i]));
        printf("Ptrarr + %d points to %u\n",i,*(ptrarr[i]));
        printf("ap[%d] is %d\n",i+10,*ap[i+10]);
    }
    return;
}

void const_ptrs(void)
{
    const char c1 = 'a',c2 = 'b';
    char * const h = &c1;
    printf("c1=%c c2=%c &c1=%p &c2=%p *h=%c h=%p\n",c1,c2,&c1,&c2,*h,h);
    // Below causes error
    //h = &c2;
    *h = 'c';
    printf("c1=%c c2=%c &c1=%p &c2=%p *h=%c h=%p\n",c1,c2,&c1,&c2,*h,h);
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
    struct test
    {
        int* (*(finder[2]))(int,int);
        int a,b;
    }test_ptr;

    test_ptr.a = 10;
    test_ptr.b = 11;
    test_ptr.finder[0] = &add;
    printf("This is f=add and *f(a,b) is %d\n",*(test_ptr.finder[0](test_ptr.a,test_ptr.b)));
    test_ptr.finder[1] = &mul;
    printf("This is f=mul and *f(a,b) is %d\n",*(test_ptr.finder[1](test_ptr.a,test_ptr.b)));

    printf("Addresses of a and b are %p and %p\n",&test_ptr.a,&test_ptr.b);
    printf("The function address of finder[0] is %p\n",&test_ptr.finder[0]);
    printf("The function address of finder[1] is %p\n",&test_ptr.finder[1]);
    printf("The function address of finder[2] is %p\n",&test_ptr.finder[2]);
    printf("The function address of finder[3] is %p\n",&test_ptr.finder[3]);
    printf("Values of a and b are %d and %d\n",test_ptr.a,test_ptr.b);

    test_ptr.finder[2] = (int* (*) (int,int))0x0000001200000023;
    printf("Values of a and b are %d and %d\n",test_ptr.a,test_ptr.b);

    printf("The function address of finder[2] is %p\n",&test_ptr.finder[2]);
    printf("The function address of finder[3] is %p\n",&test_ptr.finder[3]);
    return;
}

int main (int argc, char *argv[])
{
    arraysVsPtrs();
    const_ptrs();
    func_ptrs();
    return 0;
}

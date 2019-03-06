#include<stdio.h>

int main(void)
{
    const int i = 5;
    printf("I value is %d\n",i);
    int *j = &i;
    *j = 7;
    printf("I value is %d\n",i);
    return 0;
}

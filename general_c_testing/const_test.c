#include<stdio.h>

#define M1 5
#define M2 7

int tryDoCase()
{
    int c=1;
    switch(c)
    {
        case 1:;
               do{ c++; printf("%d\n",c);
        case 5:;
               return 0;}while(0);
               printf("in 5\n");
    }

    return 0;
}

int function(void) {
    static int i, state = 0;
    switch (state) {
        case 0: goto LABEL0;
        case 1: goto LABEL1;
    }
    LABEL0: /* start of function */
    for (i = 0; i < 3; i++) {
        state = 1; /* so we will come back to LABEL1 */
        return i;
        LABEL1:; /* resume control straight after the return */
    }
}

int main(void)
{
    const int i = M1;
    printf("I value is %d\n",i);
    int *j = &i;
    *j = M2;
    printf("I value is %d\n",i);
    tryDoCase();

    printf("The i value is: %d\n",function());
    printf("The i value is: %d\n",function());
    printf("The i value is: %d\n",function());
    printf("The i value is: %d\n",function());
    printf("The i value is: %d\n",function());
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define INDEXMAX 45
#define NUMBER_OF_TRIES 19
typedef uint32_t TIMER_INT_t;
char elapsed_time[100] = {};
static char * convert_to_char( const TIMER_INT_t count )
{
    int i;
    TIMER_INT_t temp = count;
    for( i=0; temp!=0; i++ )
    {
        temp /= 10;
    }
    elapsed_time[i--] = '\0';
    temp = count;
    for( ; i>=0 ; i-- )
    {
        elapsed_time[i] = '0' + temp%10;
        temp /= 10;
    }
    return elapsed_time;
}

// Helper function to construct the key for the hash function
static void string_copy( char *dst, const char *src)
{
    int i;
    for ( i = 0; *src != '\0'; i++ )
        *dst++ = *src++;
}
int main (int argc, char *argv[])
{
    char str[] = "Hi there";

    struct s {
        uint32_t a;
        uint32_t b;
    };

    struct s example[] = {
        {0,1},
        {0,3},
        {0,15},
        {1,23},
    };

    int siz = sizeof(example)/sizeof(struct s);
    char *c = (char *)malloc(sizeof(1000));
    *c = '\0';
    char *b = c;

    strcat(c,str);

    printf("b = %s\nc = %s\nstr = %s\n",b,c,str);
    printf("size of struct is :%d",siz);

    free(b);

    char *memtest = (char *)malloc(4*(sizeof(char)));
    //Testing if access to mem out of bounds results in seg faults

    *(memtest+2) = 'a';
    *(memtest+124000) = '8';
    free(memtest);
    printf("\n%s\n", convert_to_char(54230)); 
    return 0;
}

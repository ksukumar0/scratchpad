#include <stdio.h>
#include <stdlib.h>
#define NUMELEM 11

int compare_ints(const void *lhs, const void *rhs) {
/*
    int x = *(const int *) lhs;
    int y = *(const int *) rhs;

    if(x < y)
        return -1;
    else if(x > y)
        return 1;
    else
        return 0;*/
   return *(int*)lhs - *(int*)rhs;
}

int get_lowest(int *values) {
    qsort(values, NUMELEM, sizeof(int), &compare_ints);
    return values[0];
}

static void printArray(int *values, char *textToPrintBefore)
{
    int i=0;
    printf("%s\n",textToPrintBefore);
    for(i=0;i<NUMELEM;i++)
    {
        printf("%d ",values[i]);
    }
    printf("\n");
}

int main() {
    int values[] = {1341,12341,362,841,79,11,434,29,152,178,1};
    printArray(values, "Before Sorting");
    printf("Lowest value is: %d\n", get_lowest(values));
    printArray(values, "After Sorting");
}

/* usertime.c - pure computation: mostly user time */
#include <stdio.h>

int main(void)
{
    volatile unsigned long long sum = 0;

    for (unsigned long long i = 0; i < 1000000000ULL; i++)
        sum += i;

    printf("sum = %llu\n", sum);
    return 0;
}

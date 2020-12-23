/*
 * power.c
 * power(a, n): a^n
 * number29
 * December 23, 2020
 */


#include <stdio.h>


int power(long a, long n)
{
    if (n == 0) {
        return 1;
    }
    long x = power(a, n/2);
    if (n % 2 == 0) {
        return x * x;
    }
    else {
        return a * x * x;
    }
}


int main()
{
    long a = 5, n = 10;
    long r = power(a, n);
    printf("%ld\n", r);
    return 0;
}

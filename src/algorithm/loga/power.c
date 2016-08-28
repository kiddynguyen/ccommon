/*
 * power.c
 *
 *  Created on: Mar 23, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

unsigned long power1(int a, int n) {
    unsigned long pow = 1;
    while (n-- > 0)
        pow = pow * a;

    return pow;
}

unsigned long power2(int a, int n) {
    if (n == 0)
        return 1;

    unsigned long p = power2(a, n/2);
    if (n % 2 == 0)
        return p*p;
    return a*p*p;
}

int a = 10;
int n = 20;
int main(int argc, char *argv[]) {
//    time_t start = time(NULL);
//    printf("start = %ld\n", start);
//
//    unsigned long p1 = power1(a, n);
//    printf("p1 = %lu\n", p1);
//
//    time_t end = time(NULL);
//    printf("end = %ld\n", end);
//
//    long elapsed = end - start;
//    printf("elapsed: %ld\n", elapsed);

    size_t size_of_long = sizeof(long);
    printf("size_of_long = %lu\n", size_of_long);
}

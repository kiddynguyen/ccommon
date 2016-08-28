/*
 * pass_by_value.c
 * c pass argument as value
 */

#include <stdio.h>
#include <stdlib.h>

void swap1(int a, int b);
void swap2(int *a, int *b);

void main(int argc, char *argv[]) {
    int x = atoi(*++argv);
    int y = atoi(*++argv);
    printf("x = %d, y = %d\n", x, y);

    swap1(x, y);
    printf("x = %d, y = %d\n", x, y);

    swap2(&x, &y);
    printf("x = %d, y = %d\n", x, y);
}

void swap1(int a, int b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

void swap2(int *a, int *b) {
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

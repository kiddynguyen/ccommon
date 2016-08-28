/*
 * string.c
 *
 *  Created on: Dec 18, 2015
 *      Author: tunm2
 */

#include <stdio.h>
#include <stdlib.h>

#include "strcpy.h"

void main() {
    char *dst = (char*) calloc(255, sizeof(char));
    char *src = "hello";
    strcpy4(dst, src);

    printf("dst = %s\n", dst);
}

/**
 * Assume that 'to' is big enough to hold all characters from 'from'
 */
void strcpy1(char *dst, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dst[i] = src[i];
        i++;
    }
}

void strcpy2(char *dst, char *src) {
    int i = 0;
    while ((dst[i] = src[i]) != '\0')
        i++;
}

/**
 * 'from'/'to' is just pointer to the first character of string.
 * so '*from'/'*to' is the value of the first character of string.
 * 'from ++'/'to ++' increases the memory address by one,
 * makes 'from'/'to' points to next character
 */
void strcpy3(char *dst, char *src) {
    while ((*dst = *src) != '\0') {
        src++;
        dst++;
    }
}

/**
 * The value of '*to++' is the character that 'to' pointed to before it was incremented
 */
void strcpy4(char *dst, char *src) {
    while ((*dst++ = *src++) != '\0');
}

void strcpy5(char *dst, char *src) {
    while (*dst++ = *src++); // ?? Why this true
}

void strcpy6(char dst[], char src[]) {
    int i = 0;
    while ((dst[i] = src[i]) != '\0')
        i++;
}

/**
 * In this case, from and to also are the pointers which point to first element of string
 */
void strcpy7(char dst[], char src[]) {
    // this not error but it doesn't work because C pass arguments as value,
    // and here, 'to' is a memory address (location),
    // we cannot change this location, we can only change the internal value stored inside it.
    dst = src;
}

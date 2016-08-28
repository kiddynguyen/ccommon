/*
 * common.c
 *
 *  Created on: Feb 27, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <ctype.h>
#include "common/common.h"

void uppercase(char *s) {
    while (*s != '\0') {
        *s = toupper(*s); // WHY *s = toupper(*s++) causes ERROR
        s++;
    }
}

void lowercase(char *s) {
    while (*s != '\0') {
        *s = tolower(*s);
        s++;
    }
}

void swap1(int a[], int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void printarr(int a[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", a[i]);

    printf("\n");
}

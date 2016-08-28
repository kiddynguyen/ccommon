/*
 * string_cat.c
 *
 *  Created on: Dec 26, 2015
 *      Author: konai
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strcat.h"

void main() {
    char *s = (char*) calloc(11, sizeof(char));
    char ct[] = "hello";
    int i = 0;
    for (i = 0; i < 5; i++) s[i] = 'a' + i;

    printf("size of s = %lu\n", strlen(s));
    printf("size of ct = %lu\n", strlen(ct));
    printf("s = %s\n", s);
    printf("ct = %s\n", ct);

    char *sresult = strcat3(s, ct);
    printf("sresult = %s\n", sresult);
    printf("s = %s\n", s);
}

/**
 * Assume 's' has enough space to contain 'ct'.
 * Modify 's' and return it
 */
char *strcat1(char *s, char *ct) {
    char *swalker = s;
//    while (*swalker++ != '\0');    // why this NOT work?? it just the same as bellow
    while (*swalker != '\0')
        swalker++;
    while ((*swalker = *ct) != '\0') {
        swalker++; ct++;
    }

    return s;
}

/**
 * Assume 's' has enough space to contain 'ct'.
 * Modify 's' and return it
 */
char *strcat2(char *s, char *ct) {
    int i = 0;
    while (s[i] != '\0') i++;
    while ((s[i] = *ct++) != '\0') i++;

    return s;
}

/**
 * Don't modify s (assume it has not enough space to contain 'ct')
 * Create new string and return it
 */
char *strcat3(char *s, char *ct) {
    size_t sizes = strlen(s);
    size_t sizect = strlen(ct);

    char *scat = (char*) calloc(sizes + sizect, sizeof(char));
    char *swalker = scat;

    while ((*swalker = *s) != '\0') {
        swalker++; s++;
    }
    while ((*swalker = *ct) != '\0') {
        swalker++; ct++;
    }

    return scat;
}

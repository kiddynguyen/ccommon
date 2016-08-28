/*
 * strstr.c
 *
 *  Created on: Jan 20, 2016
 *      Author: konai
 */

#include <stdio.h>
#include "strstr.h"

// use pointer
int strstr1(char *s, char *pattern) {
    if (s == pattern)
        return 0;

    int found = 0;
    char *ps, *pp;

    while (*s != '\0') {
        ps = s++, pp = pattern;
        while (*pp != '\0' && *pp++ == *ps++);
        if (*pp == '\0')
            return found;
        found++;
    }

    return -1;
}

// use index
int strstr2(char *s, char *pattern) {
    if (s == pattern)
        return 0;

    int i, j;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; pattern[j] == s[i+j] && pattern[j] != '\0'; j++);
        if (pattern[j] == '\0')
            return i;
    }

    return -1;
}

/*
 * getline.c
 *
 *  Created on: Jan 20, 2016
 *      Author: konai
 */

#include <stdio.h>
#include "fgets.h"

char *fgets1(char *s, int maxline, FILE *fp) {
    int c;
    while ((c = fgetc(fp)) != EOF && c != '\n' && maxline-- > 0)
        *s++ = c;

    if (c == EOF) // EOF is always a new separate line at the end
        return NULL;

    if (c == '\n')
        *s++ = c;

    *s = '\0';
    return s;
}

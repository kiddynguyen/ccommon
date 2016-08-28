/*
 * readlines.c
 *
 *  Created on: Mar 14, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readlines.h"

int readline(char *line, int maxline, FILE *fp) {
    int ch, count = 0;

    while ((ch = fgetc(fp)) != EOF && ch != '\n' && maxline-- > 0) {
        *line++ = ch;
        count++;
    }

    if (ch == EOF) // EOF is always on a new separate line
        return -1;

    if (ch == '\n') {
        *line++ = ch;
        count++;
    }

    *line = '\0';

    return count;
}

int readinput(char *lines[], int maxlines, FILE *fp) {
    char buf[MAXLINE]; // use this to save the memory
    int count, nlines = 0;

    while ((count = readline(buf, MAXLINE, fp)) > -1 && maxlines-- > 0) {
        *lines = (char*) malloc(count*sizeof(char));
        strcpy(*lines++, buf); // use this to save the memory
        nlines++;
    }

    return nlines;
}

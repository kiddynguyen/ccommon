/*
 * print_longest_input_line.c
 *
 *  Created on: Dec 18, 2015
 *      Author: konai
 */
#include <stdio.h>
#include <stdlib.h>
#include "get_longest_input_line.h"

void main() {
    get_longest_input_line();
}

void get_longest_input_line() {
    int len;                // current line length
    int max = 0;            // max length so far
    char line[MAXLINE];     // current input line, allocate statically
    char longest[MAXLINE];  // longest line so far, allocate statically

    while ((len = readline(line)) > 0) {
        if (len > max) {
            max = len;
            copystring(longest, line);
        }
    }

    if (max > 0) // there was a line
        printf("[longest] %s", longest);
}

/**
 * Copy 'src' into 'dst', assume dst is big enough
 */
void copystring(char dst[], char src[]) {
    int i = 0;
    while ((dst[i] = src[i]) != '\0')
        i++;
}

/**
 * Read a line into 'line', return length
 */
int readline(char line[]) { // what happen if pass char* ??? nothing, with a condition the pointer must allocated big enough
    int ch;
    int i = 0;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        line[i] = ch;
        i++;
    }

    if (ch == '\n') { // keep NEW_LINE character
        line[i] = ch;
        i++;
    }

    // put NULL character to mark the end of string (like C acts)
    line[i] = '\0'; // it still WORK without this line ???? WHY

    return i;
}

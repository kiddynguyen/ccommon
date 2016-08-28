/*
 * string_sort_input_lines.c
 *
 *  Created on: Jan 2, 2016
 *      Author: konai
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readlines.h"

#define MAXLINES    100 // max number of lines allowed
#define MAXLEN      255 // max length of line allowed

void sortlines(char *lines[], int size);
void writelines(char *lines[], int size);

void main() {
    char *lines[MAXLINES];
    int nlines = readinput(lines, MAXLINES, stdin);
    writelines(lines, nlines);
    sortlines(lines, nlines);
    writelines(lines, nlines);
}

void swap1(char *arr[], int i, int j) {
    char *tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void sortlines(char *lines[], int nlines) {
    int i, j;
    for (i = 0; i < nlines-1; i++) {
        for (j = i+1; j < nlines; j++)
            if (strcmp(lines[i], lines[j]) > 0)
                swap1(lines, i, j);
    }
}

void writelines(char *lines[], int nlines) {
    int i;
    printf("[output]\n");
    for (i = 0; i < nlines; i++)
        printf("%s", lines[i]);
}

/*
 * pointer_to_function.c
 * Short input lines with optional compare function
 *
 *  Created on: Mar 19, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE     255
#define MAXLINES    1000

void quitsort(void **lines, int left, int right, int (*comp)(void*, void*));
void printarr(char *lines[], int nlines);
int intcmp(char *a, char *b);

void main(int argc, char *argv[]) {
    char *fname = argv[1];
    FILE *fp = fopen(fname, "r");

    // read lines
    char *lines[MAXLINES];
    int nlines = readinput(lines, MAXLINES, fp);
    printf("++ before sort\n");
    printarr(lines, nlines);
    // sort
    quitsort((void**)lines, 0, nlines-1, (int(*)(void*, void*))strcmp);
    printf("++ after sort\n");
    printarr(lines, nlines);

    fclose(fp);
}

int readline(char *line, int maxline, FILE *stream) {
    int count = 0, ch;
    while ((ch = fgetc(stream)) != EOF && ch != '\n' && maxline-- > 0) {
        *line++ = ch;
        count++;
    }

    if (ch == EOF)
        return -1;

//    if (ch == '\n') {
//        *line++ = ch;
//        count++;
//    }

    *line = '\0';

    return count;
}

int readinput(char **lines, int maxlines, FILE *stream) {
    int nlines = 0, nchars;
    char line[MAXLINE];
    while ((nchars = readline(line, MAXLINE, stream)) != -1 && maxlines-- > 0) {
        *lines = (char*) malloc(nchars * sizeof(char));
        strcpy(*lines++, line);
        nlines++;
    }
    return nlines;
}

void swap(void *arr[], int i, int j) {
    void *tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int intcmp(char *a, char *b) {
    int ia = atoi(a), ib = atoi(b);
    if (ia > ib)
        return 1;
    if (ia < ib)
        return -1;
    return 0;
}

void quitsort(void **lines, int left, int right, int (*comp)(void*, void*)) {
    if (left >= right)
        return;

    int pivot = left, last = left+1, i;
    for (i = left+1; i <= right; i++) {
        if ((*comp)(lines[i], lines[pivot]) < 0)
            swap(lines, i, last++);
    }
    swap(lines, pivot, last-1);
    quitsort(lines, left, last-1, comp);
    quitsort(lines, last, right, comp);
}

void printarr(char *lines[], int nlines) {
    while (nlines-- > 0)
        printf("%s\n", *lines++);
}

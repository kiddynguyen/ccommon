/*
 * grep.c
 *
 * $ grep pattern filename
 *
 *  Created on: Jan 20, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../common/common.h"

#define MAXLINE 1000

/**
 * K&R, page 97
 */
int main(int argc, char *argv[]) { // argv is a pointer array ~ an array of arguments
    bool invert = false, linenum = false;
    int c;
    while (--argc > 0 && (*++argv)[0] == '-') { // *argv = first arg ~ program name; *++argv = second arg
        while ((c = *++argv[0]) != '\0') { // next character of current argument
            switch (c) {
            case 'n':
                linenum = true;
                break;
            case 'v':
                invert = true;
                break;
            default:
                printf("grep: illegal option %c\n", c);
                return EXIT_SUCCESS;
            }
        }
    }

    if (argc != 2) {
        printf("Usage: grep -n -v pattern file\n");
        return EXIT_SUCCESS;
    }

    char *pattern = *argv++, *filename = *argv;
    char line[MAXLINE];

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File %s not found\n", filename);
        return EXIT_SUCCESS;
    }

    int lineno = 0;
    while (fgets(line, MAXLINE, fp) != NULL) {
        lineno++;
        if ((strstr(line, pattern) != NULL) != invert) {
            if (linenum) printf("%d: ", lineno);
            printf("%s", line);
        }
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

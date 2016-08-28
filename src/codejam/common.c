/*
 * common.c
 *
 *  Created on: Mar 27, 2016
 *      Author: konai
 */

#include "common.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **readinput(FILE *fp, int *ncases) {
    // read number of cases first
    char line[MAXLINE];
    fgets(line, MAXLINE, fp);
    *ncases = atoi(line);

    // read lines
    char **lines = malloc((*ncases)*sizeof(char*));
    int i = 0, len;
    while (fgets(line, MAXLINE, fp) != NULL) {
        len = strlen(line);
        line[len-1] = '\0'; // remove newline
        lines[i] = malloc((len-1)*sizeof(char));
        strcpy(lines[i], line);
        i++;
    }

    return lines;
}

int strtoks(char *str, char *delim, char *words[]) {
    int i = 0;
    words[0] = strtok(str, delim);
    if (words[0] != NULL)
        while ((words[++i] = strtok(NULL, delim)) != NULL);

    return i;
}

int main(int argc, char *argv[]) {
    char *str = "hello world";
    char *delim = " ";
    char *words[2];
    strtoks(str, delim, words);
    printf("words[0] = %s\n", words[0]);
    printf("words[1] = %s\n", words[1]);
    return 0;
}

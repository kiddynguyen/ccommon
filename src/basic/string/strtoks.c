/*
 * strtoks.c
 *
 *  Created on: Mar 12, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strtoks.h"

int main(int argc, char *argv[]) {
    char *str = argv[1];
    char *delim = argv[2];

    char **words = (char**) malloc(1000*sizeof(char*));
    int nwords = strtoks(str, delim, words);
    while (nwords-- > 0) {
        printf("%s\n", *words);
        words++;
    }

    return 0;
}

int strtoks(char *str, char *delim, char **words) {
    int i = 0;
    words[0] = strtok(str, delim);
    if (words[0] != NULL)
        while ((words[++i] = strtok(NULL, delim)) != NULL);

    return i;
}

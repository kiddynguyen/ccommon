/*
 * cat.c
 *
 *  Created on: Oct 16, 2015
 *      Author: tunm2
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define CHARS_BUF 255

void filecopy_char_by_char(char *from_file, char *to_file) {
    FILE *ifp = fopen(from_file, "r");
    FILE *ofp = fopen(to_file, "w");

    if (ifp == NULL) {
        perror("File not found\n");
        return;
    }

    char ch;

    while ((ch = getc(ifp)) != EOF) {
        putc(ch, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

void filecopy_line_by_line(char *from_file, char *to_file) {
    FILE *ifp = fopen(from_file, "r");
    FILE *ofp = fopen(to_file, "w");

    if (from_file == NULL) {
        perror("File not found\n");
        return;
    }

    char *line = (char*) calloc(CHARS_BUF, sizeof(char));
//    char line[chars_count];

    while (fgets(line, CHARS_BUF, ifp) != NULL) {
        fputs(line, ofp);
    }

    fclose(ifp);
    fclose(ofp);
}

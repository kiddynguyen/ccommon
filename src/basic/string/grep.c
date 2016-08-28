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
#include "fgets.h"
#include "strstr.h"

#define MAXLINE 1000

int main(int argc, char *argv[]) {
    // parse arg pattern and filename
    char *filename = argv[--argc];
    char *pattern = argv[--argc];

    // parse arg option: n, v
    bool invert = false, linenum = false, ignorecase = false;
    while (argc-- > 2) {
        char *arg = argv[argc];
        if (*arg != '-') {
            printf("invalid argument %s\n", arg);
            return EXIT_FAILURE;
        }

        int ch;
        while ((ch = *++arg) != '\0') {
            switch (ch) {
            case 'n':
                linenum = true;
                break;
            case 'v':
                invert = true;
                break;
            case 'i':
                ignorecase = true;
                break;
            }
        }
    }

    FILE *file = fopen(filename, "r");
    char line[MAXLINE], line1[MAXLINE];
    int nline = 0;
    while (fgets(line, MAXLINE, file) != NULL) {
        nline++;
        strcpy(line1, line);
        if (ignorecase) {
            uppercase(pattern);
            uppercase(line1);
        }

        if ((strstr(line1, pattern) != NULL) == !invert) { // check if line contains pattern
            if (linenum) printf("%d ", nline);
            printf("%s", line);
        }
    }

    fclose(file);
    return EXIT_SUCCESS;
}

//int main(int argc, char *argv[]) { // *argv[] is a pointer array
//    if (argc < 3) {
//        printf("missing parameter");
//        return EXIT_FAILURE;
//    }
//
//    char *filename = argv[--argc];
//    char *pattern = argv[--argc];
//
//    bool except = false, printno = false;
//    char *ops;
//    while (--argc > 0) {
//        ops = argv[argc];
//        if (ops[0] == '-') {
//            if (strchr(ops, 'x') != NULL)
//                except = true;
//            if (strchr(ops, 'n') != NULL)
//                printno = true;
//        }
//    }
//
//    FILE *file = fopen(filename, "r");
//    char *line = (char*) malloc(MAXLINE * sizeof(char));
//    int lineno = 0, found = -1;
//
//    while(fgets1(line, MAXLINE, file) != NULL) {
//        found = strstr2(pattern, line);
//        if ((!except && found > -1) || (except && found == -1)) {
//            if (printno)
//                printf("%d: %s", lineno, line);
//            else
//                printf("%s", line);
//        }
//        lineno++;
//    }
//
//    free(line);
//    fclose(file);
//
//    return EXIT_SUCCESS;
//}

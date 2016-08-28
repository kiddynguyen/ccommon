/*
 * standard_io_operations.c
 *
 *  Created on: Dec 25, 2015
 *      Author: konai
 */
#include <stdio.h>

void demo_standard_io_ops() {
    FILE *stream = stdin;

    // getc() is the same as fgetc()
    int ch1 = getc(stream);     // defined as macro
    int ch2 = fgetc(stream);    // defined as a function
    int ch3 = getchar(); // ~ getc(stdin)
//    char *line = gets(line)
//    fgets(char *s, int count, FILE *stream)

}

/*
 * read_input_by_chars.c
 *
 *  Created on: Dec 17, 2015
 *      Author: konai
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "read_input_char_by_char.h"

/**
 * Read characters from standard input char by char
 * and convert it to uppercase then display on standard output.
 *
 * Function getchar() will poll standard input to request character
 */
void read_input_char_by_char() {
    char c;
    while ((c = getchar()) != EOF) {
        char C = uppercase(c);
        putchar(C);
    }
}

/*
 * echo.c
 *
 *  Created on: Jan 10, 2016
 *      Author: konai
 */

#include <stdio.h>

int main(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s%s", *++argv, argc > 1 ? " " : "");

    printf("\n");

    return 0;
}

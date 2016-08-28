/*
 * multiplication.c
 *
 *  Created on: Mar 22, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @a first matrix
 * @b second matrix
 * @x number of rows of a
 * @y number of columns of a and also is number of row of b
 * @z number of columns of b
 */
int **maxtrix_multiply(int **a, int **b, int x, int y, int z) {
    int **p = malloc(x * sizeof(int*));
    int i, j, k;
    for (i = 0; i < x; i++) {
        p[i] = malloc(z * sizeof(int));
        for (j = 0; j < z; j++) {
            p[i] = 0;
            for (k = 0; k < y; k++)
                p[i] += a[i][k] * b[k][j];
        }
    }

    return p;
}

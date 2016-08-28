/*
 * insertionsort.c
 *
 *  Created on: Mar 22, 2016
 *      Author: konai
 */

#include <stdio.h>
#include "common/common.h"

void insertion_sort(int data[], int size) {
    int i, j;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && data[j] < data[j-1])
            swap(data, j, --j);
    }
}

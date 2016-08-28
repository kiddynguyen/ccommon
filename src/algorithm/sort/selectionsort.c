/*
 * selectionsort.c
 *
 *  Created on: Feb 17, 2016
 *      Author: konai
 */

#include <stdio.h>
#include "common/common.h"
#include "algorithm/sort/selectionsort.h"

void selectionsort(int a[], int size) {
    int i, j, min;
    for (i = 0; i < size-1; i++) {
        min = i;
        for (j = i+1; j < size; j++) {
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap1(a, i, min);
    }
}

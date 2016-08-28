/*
 * quicksort.c
 *
 *  Created on: Feb 9, 2016
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>
#include "common/common.h"
#include "algorithm/sort/quicksort.h"

void quicksort(int a[], int left, int right) {
    if (left >= right)
        return;

    int pivot = left, i;
    for (i = left+1; i <= right; i++) {
        if (a[i] < a[left])
            swap1(a, ++pivot, i);
    }
    swap1(a, left, pivot);

    quicksort(a, left, pivot);
    quicksort(a, pivot+1, right);
}

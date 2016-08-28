/*
 * app.c
 *
 *  Created on: Aug 28, 2016
 *      Author: kiddy
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "common/common.h"
#include "basic/time/timeutils.h"
#include "algorithm/sort/mergesort.h"

#define SORT_SIZE 10

int main(int argc, char *argv[]) {
    int list[SORT_SIZE], i;

    for (i = 0; i < SORT_SIZE; i++)
        list[i] = rand() % 100;

    printf("Before sort:\n");
    printarr(list, SORT_SIZE);

    long start = current_time_in_milisecs();
    merge(list, 0, SORT_SIZE/2, SORT_SIZE-1);
    long end = current_time_in_milisecs();

    printf("After sort:\n");
    printarr(list, SORT_SIZE);

    printf("Duration: %ld\n", end - start);

    return EXIT_SUCCESS;
}

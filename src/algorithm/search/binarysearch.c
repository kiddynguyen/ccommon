/*
 * binarysearch.c
 *
 *  Created on: Nov 10, 2015
 *      Author: konai
 */

#include <stdio.h>

int bsearch(int, int[]);

int main(int argc, char *argv[]) {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int x = -9;

    bsearch(7, arr);
    printf("result: %d \n", x);

    return 0;
}

int bsearch(int el, int data[]) {
    int len = sizeof(data) / sizeof(data[0]);
    int from = 0;
    int to = len - 1;

    while (from < to) {
        int mid = (to + from) / 2;
        if (data[mid] == el)
            return mid;

        if (el < data[mid])
            to = mid - 1;
        else
            from = mid;
    }

    return -1;
}

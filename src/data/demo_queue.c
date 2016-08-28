/*
 * demo_queue.c
 *
 *  Created on: Apr 9, 2016
 *      Author: kiddy
 */

#include <stdio.h>
#include "queue.h"

int main(int argc, char *argv[]) {
    int list[] = { 2, 6, 5, 7, 9, 10, 8, 11, 12 };
    int size = sizeof(list)/sizeof(int);
    struct queue *q = queue_init(1);

    int i;
    for (i = 0; i < size; i++)
        queue_add(q, &list[i]);

    while (!queue_is_empty(q)) {
        int *el = queue_remove(q);
        printf("%d ", *el);
    }
    printf("\n");
}

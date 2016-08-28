/*
 * list_demo.c
 *
 *  Created on: Mar 20, 2016
 *      Author: konai
 */
#include <stdio.h>
#include "../data/list.h"

int main(int argc, char *argv[]) {
    struct list *l = list_init();
    list_print(l);
    list_insert_first(5, l);
    list_print(l);
    list_insert_last(100, l);
    list_print(l);
    list_insert_at(99, 1, l);
    list_print(l);
    list_insert_at(1, 0, l);
    list_print(l);
    list_remove_at(1, l);
    list_print(l);
//    list_remove_at(0, l);
}

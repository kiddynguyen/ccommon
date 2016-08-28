/*
 * list.h
 * an implementation of linked list
 *
 *  Created on: Feb 18, 2016
 *      Author: konai
 */

#ifndef LIST_H_
#define LIST_H_

#include <stddef.h>
#include "common/common.h"

struct element {
    int data;
    struct element *next; // use pointer here to check null
};

struct list {
    struct element *head; // use pointer here to check null and memory allocation/free
    int size;
};

struct element *elem_init(int data);

struct list *list_init();
bool list_is_empty(struct list *l);
size_t list_size(struct list *l);
void list_clear(struct list *l);
void list_print(struct list *l);
void list_reverse_print(struct list *l);

struct element *list_get_first(struct list *l);
struct element *list_get_last(struct list *l);
struct element *list_get_at(int pos, struct list *l);

bool list_insert_first(int data, struct list *l);
bool list_insert_last(int data, struct list *l);
bool list_insert_at(int data, int pos, struct list *l);

/**
 * Return pointer to the element removed
 */
struct element *list_remove_first(struct list *l);
struct element *list_remove_last(struct list *l);
struct element *list_remove_at(int pos, struct list *l);

struct list *list_sublist(struct list *l, int from, int to);
struct list *list_append(struct list* l1, struct list *l2);

#endif /* LIST_H_ */

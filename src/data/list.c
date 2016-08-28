/*
 * list.c
 *
 *  Created on: Feb 18, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <stdlib.h>
#include "data/list.h"

struct element *elem_init(int data) {
    struct element *el = malloc(sizeof(struct element));
    if (el == NULL) // allocate failed
        return NULL;

    el->data = data;
    el->next = NULL;
    return el;
}

struct list *list_init() {
    struct list *l = malloc(sizeof(struct list));
    if (l == NULL) // allocate failed
        return NULL;

    l->head = NULL;
    l->size = 0;
    return l;
}

bool list_is_empty(struct list *l) {
    return l->size == 0;
}

size_t list_size(struct list *l) {
    return l->size;
}

void list_clear(struct list *l) {
    if (list_is_empty(l))
        return;

    struct element *tmp;
    while (l->head != NULL) {
        tmp = l->head;
        l->head = l->head->next;
        free(tmp);
    }
}

void list_print(struct list *l) {
    if (list_is_empty(l)) {
        printf("list is empty\n");
        return;
    }

    struct element *tmp = l->head;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

/** print a list in reverse order */
void _list_reverse_print(struct element *el) {
    if (el == NULL)
        return;

    _list_reverse_print(el->next);
    printf("%d ", el->data);
}
void list_reverse_print(struct list *l) {
    _list_reverse_print(l->head);
}

bool list_insert_first(int data, struct list *l) {
    struct element *el = elem_init(data);
    if (el == NULL)
        return false;

    el->next = l->head;
    l->head = el;
    l->size++;

    return true;
}

bool list_insert_last(int data, struct list *l) {
    struct element *el = elem_init(data);
    if (el == NULL)
        return false;

    if (list_is_empty(l)) {
        l->head = el;
    } else {
        struct element *tmp = l->head;
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = el;
        tmp = NULL;
    }

    l->size++;
    return true;
}

bool list_insert_at(int data, int pos, struct list *l) {
    if (l == NULL || pos < 0 || pos > l->size)
        return false;

    struct element *el = elem_init(data);
    if (el == NULL) return false; // allocate failed
    if (pos == 0) {
        el->next = l->head;
        l->head = el;
        l->size++;
        return true;
    }

    struct element *tmp = l->head;
    int index = 1;
    while (index < pos) {
        tmp = tmp->next;
        index++;
    }

    el->next = tmp->next;
    tmp->next = el;
    tmp = NULL;

    l->size++;
    return true;
}

struct element *list_get_first(struct list *l) {
    if (l == NULL || list_is_empty(l))
        return NULL;

    return l->head;
}

struct element *list_get_last(struct list *l) {
    if (l == NULL || list_is_empty(l))
        return NULL;

    struct element *el = l->head;
    while (el->next != NULL)
        el = el->next;
    return el;
}

struct element *list_get_at(int pos, struct list *l) {
    if (l == NULL || list_is_empty(l) || pos < 0 || pos > l->size-1)
        return NULL;

    int index = 0;
    struct element *el = l->head;
    while (el->next != NULL && index < pos) {
        el = el->next;
        index++;
    }

    return el;
}

struct element *list_remove_first(struct list *l) {
    if (l == NULL || list_is_empty(l))
        return NULL;

    struct element *el = l->head;
    l->head = l->head->next;
    l->size--;

    return el;
}

struct element *list_remove_last(struct list *l) {
    if (l == NULL || list_is_empty(l))
        return NULL;

    struct element *el = l->head;
    if (l->size == 1) {
        l->head = NULL;
        l->size--;
        return el;
    }

    struct element *prev = NULL;
    while (el->next != NULL) {
        prev = el;
        el = el->next;
    }

    prev->next = NULL;
    l->size--;

    return el;
}

struct element *list_remove_at(int pos, struct list *l) {
    if (l == NULL || list_is_empty(l) || pos < 0 || pos > l->size-1)
        return NULL;

    struct element *el = l->head;
    if (pos == 0) {
        l->head = l->head->next;
        l->size--;
        return el;
    }

    int index = 0;
    struct element *prev = NULL;
    while (index < pos) {
        prev = el;
        el = el->next;
        index++;
    }

    prev->next = el->next;
    l->size--;

    return el;
}

struct list *list_sublist(struct list *l, int from, int to) {
    struct list *slist = list_init();
    if (from < 0 || to >= l->size || l->size == 0)
        return NULL;

    int i = 0;
    struct element *el = l->head;
    while (i < to) {
        if (i >= from)
            list_insert_last(el->data, slist);

        el = el->next;
        i++;
    }
    return slist;
}

struct list *list_append(struct list* l1, struct list *l2) {
    struct element *el = l1->head;
    while (el->next != NULL)
        el = el->next;
    el->next = l2->head;
    l1->size += l2->size;

    return l1;
}

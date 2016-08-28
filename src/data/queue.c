/*
 * queue.c
 *
 *  Created on: Apr 9, 2016
 *      Author: kiddy
 */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct queue *queue_init(int capacity) {
    struct queue *q = malloc(sizeof(struct queue));
    q->elements = malloc(capacity * sizeof(void*));
    q->capacity = capacity;
    q->front = 0;
    q->rear = -1;
    q->size = 0;

    return q;
}

bool queue_is_empty(struct queue *q) {
    return q->size == 0;
}

bool _ensure_capacity(struct queue *q) {
    if (q->size < q->capacity)
        return true;

    void **old_els = q->elements; // keep track of pointer to elements
    int old_capacity = q->capacity;
    q->capacity += q->capacity / 2;
    q->elements = malloc(q->capacity * sizeof(void*));
    if (q->elements == NULL)
        return false;

    // copy old elements to q->elements
    int i;
    if (q->front <= q->rear) {
        for (i = q->front; i <= q->rear; i++)
            q->elements[i] = old_els[i];
    } else {
        for (i = 0; i <= q->rear; i++)
            q->elements[i] = old_els[i];
        for (i = q->front; i < old_capacity; i++)
            q->elements[i] = old_els[i];
    }

    return true;
}

/**
 * Calculate new rear position when add new element.
 * Assume that the queue is not full
 */
int _calc_new_rear(struct queue *q) {
    return q->rear < q->capacity-1 ? q->rear+1 : 0;
}
/**
 * Calculate new front position when remove an element
 */
int _calc_new_front(struct queue *q) {
    return q->front < q->capacity-1 ? q->front+1 : 0;
}

bool queue_add(struct queue *q, void *el) {
    if (!_ensure_capacity(q))
        return false;

    q->rear = _calc_new_rear(q);
    q->elements[q->rear] = el;
    q->size++;
    return true;
}

void *queue_remove(struct queue *q) {
    if (q == NULL || queue_is_empty(q))
        return NULL;

    void *el = q->elements[q->front];
    q->elements[q->front] = NULL;
    q->front = _calc_new_front(q);
    q->size--;
    return el;
}

void *queue_peek(struct queue *q) {
    if (q == NULL || queue_is_empty(q))
        return NULL;
    return q->elements[q->front];
}

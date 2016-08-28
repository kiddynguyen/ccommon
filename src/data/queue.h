/*
 * queue.h
 *
 *  Created on: Apr 9, 2016
 *      Author: kiddy
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "../common/common.h"

struct queue {
    void **elements;    // array of elements, void* to abstract data type
    int front;          // position of the front element
    int rear;           // position of the rear element
    int size;           // current size
    int capacity;       // max size
};

struct queue *queue_init(int capacity);
int queue_size(struct queue *q);
bool queue_is_empty(struct queue *q);

bool queue_add(struct queue *q, void *el);
void *queue_remove(struct queue *q);
void *queue_peek(struct queue *q);

#endif /* QUEUE_H_ */

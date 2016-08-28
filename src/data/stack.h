/*
 * stack.h
 *
 *  Created on: Mar 20, 2016
 *      Author: konai
 */

#ifndef STACK_H_
#define STACK_H_

#include "../common/common.h"

struct stack {
    void **elements;    // pointer to elements, use void* to abstract data type
    int top;            // position of top element
    int size;           // current size
    int capacity;       // max size
};

struct stack *stack_init(int size);
void stack_free(struct stack *s);
int stack_size(struct stack s);
bool stack_is_empty(struct stack s);

bool stack_push(struct stack *s, void *el);
void *stack_pop(struct stack *s);
void *stack_top(struct stack s);

#endif /* STACK_H_ */

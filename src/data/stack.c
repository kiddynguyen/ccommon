/*
 * stack.c
 *
 *  Created on: Mar 20, 2016
 *      Author: konai
 */

#include "../data/stack.h"

#include <stdio.h>
#include <stdlib.h>

struct stack *stack_init(int capacity) {
    struct stack *s = malloc(sizeof(struct stack));
    s->elements = malloc(capacity*sizeof(void*));
    s->top = -1;
    s->size = 0;
    s->capacity = capacity;
    return s;
}

void stack_free(struct stack *s) {
    while(!stack_is_empty(*s)) {
        void *el = stack_pop(s);
        free(el);
    }
}

/**
 * Make sure the stack has enough capacity to push new element.
 * If the stack is full, increase its size by half
 */
bool _ensure_capacity(struct stack *s) {
    if (s->size < s->capacity)
        return true;

    s->capacity += s->capacity / 2;
    s->elements = realloc(s->elements, s->capacity); // content will be copied automatically
    if (s->elements == NULL)
        return false;
    return true;
}

int stack_size(struct stack s) {
    return s.size;
}

bool stack_is_empty(struct stack s) {
    return s.size == 0;
}

bool stack_push(struct stack *s, void *elem) {
    if (!_ensure_capacity(s))
        return false;

    s->elements[++s->top] = elem;
    s->size++;
    return true;
}

void *stack_pop(struct stack *s) {
    if (stack_is_empty(*s))
        return NULL;

    s->size--;
    void *el = s->elements[s->top];
    s->elements[s->top--] = NULL;
    return el;
}

void *stack_top(struct stack s) {
    if (stack_is_empty(s))
        return NULL;

    return s.elements[s.top];
}

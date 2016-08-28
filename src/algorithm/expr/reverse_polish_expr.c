/*
 * reverse_polish_expr.cpp
 *
 *  Created on: Mar 19, 2016
 *      Author: konai
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../common/common.h"
#include "../../data/stack.h"

#define ADD '+'
#define SUB '-'
#define MUL '*'
#define DIV '/'

bool is_operator(char *op);
int eval(int a, int b, char op);

int main(int argc, char *argv[]) {
//    char *ops[] = { "4", "2", "5", "*", "+", "1", "3", "2", "*", "+", "/" };
    const char *ops[] = { "2", "5", "*", "4", "+", "3", "2", "*", "1", "+", "/" };
    int nops = sizeof(ops) / sizeof(char*);
    printf("size = %d\n", nops);
    struct stack *ops_stack = stack_init(2);
    int i;
    for (i = 0; i < nops; i++) {
        char *opr = (char*) ops[i];
        if (!is_operator(opr)) {
            stack_push(ops_stack, opr);
        } else {
            int opr2 = atoi(stack_pop(ops_stack));
            int opr1 = atoi(stack_pop(ops_stack));
            int val = eval(opr1, opr2, *opr);
            char *sval = (char*) malloc(255*sizeof(char));
            sprintf(sval, "%d", val);
            stack_push(ops_stack, sval);
        }
    }

    printf("result: %s\n", (char*)stack_pop(ops_stack));
}

bool is_operator(char *op) {
    if (strlen(op) != 1)
        return false;
    char op_c = *op;
    return op_c == ADD || op_c == SUB || op_c == MUL || op_c == DIV;
}

int eval(int a, int b, char op) {
    if (op == ADD)
        return a + b;
    if (op == SUB)
        return a - b;
    if (op == MUL)
        return a * b;
    if (op == DIV)
        return a / b;
    return -1;
}

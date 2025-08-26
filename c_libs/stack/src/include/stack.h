#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct stack
{
    size_t capacity;
    size_t size;
    int *p;
} stack;

stack make_stack(size_t capacity);

stack copy_stack(stack *other);

void delete_stack(stack* stk);

int stack_top(stack* stk);

void stack_push(stack* stk, int value);

int stack_pop(stack* stk);

#endif
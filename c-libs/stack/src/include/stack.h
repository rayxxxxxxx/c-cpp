#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Stack
{
    size_t capacity;
    size_t size;
    int *p;
} Stack;

Stack make_stack(size_t capacity);
Stack copy_stack(Stack *other);
void delete_stack(Stack *stack);

int stack_top(Stack *stack);

void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);

#endif
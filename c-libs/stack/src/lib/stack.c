#include <error.h>
#include <errno.h>
#include <stdlib.h>

#include "stack.h"

Stack make_stack(size_t capacity)
{
    Stack stack;

    stack.capacity = capacity;
    stack.size = 0;
    stack.p = (int *)malloc(capacity * sizeof(int));

    return stack;
}

Stack copy_stack(Stack *other)
{
    Stack stack;

    stack.capacity = other->capacity;
    stack.size = other->size;
    stack.p = (int *)malloc(other->capacity * sizeof(int));

    for (size_t i = 0; i < other->size; i++)
    {
        stack.p[i] = other->p[i];
    }

    return stack;
}

void delete_stack(Stack *stack)
{
    free(stack->p);
}

int stack_top(Stack *stack)
{
    return stack->p[stack->size - 1];
}

void stack_push(Stack *stack, int value)
{
    if (stack->size == stack->capacity)
    {
        int newCapacity = stack->capacity * 2;
        int *newptr = (int *)malloc(newCapacity * sizeof(int));

        for (size_t i = 0; i < stack->size; i++)
        {
            newptr[i] = stack->p[i];
        }

        free(stack->p);

        stack->capacity = newCapacity;
        stack->p = newptr;
    }
    stack->p[stack->size] = value;
    stack->size++;
}

int stack_pop(Stack *stack)
{
    if (stack->size == 0)
    {
        perror("stack is empty");
        exit(1);
    }

    if (stack->size <= stack->capacity / 4)
    {
        int newCapacity = stack->capacity / 2;
        int *newptr = (int *)malloc(newCapacity * sizeof(int));

        for (size_t i = 0; i < stack->size; i++)
        {
            newptr[i] = stack->p[i];
        }

        free(stack->p);

        stack->capacity = newCapacity;
        stack->p = newptr;
    }

    int topVal = stack->p[stack->size - 1];
    stack->size--;

    return topVal;
}

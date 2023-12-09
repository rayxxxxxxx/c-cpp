#include <stdlib.h>
#include <errno.h>

#include "stack.h"

stack make_stack(size_t capacity)
{
    stack stk;

    stk.capacity = capacity;
    stk.size = 0;
    stk.p = (int *)malloc(capacity * sizeof(int));

    return stk;
}

stack copy_stack(stack *other)
{
    stack stk;

    stk.capacity = other->capacity;
    stk.size = other->size;
    stk.p = (int *)malloc(other->capacity * sizeof(int));

    for (size_t i = 0; i < other->size; i++)
    {
        stk.p[i] = other->p[i];
    }

    return stk;
}

void delete_stack(stack *stk)
{
    free(stk->p);
}

int stack_top(stack *stk)
{
    return stk->p[stk->size - 1];
}

void stack_push(stack *stk, int value)
{
    if (stk->size == stk->capacity)
    {
        int newCapacity = stk->capacity * 2;
        int *newptr = (int *)malloc(newCapacity * sizeof(int));

        for (size_t i = 0; i < stk->size; i++)
        {
            newptr[i] = stk->p[i];
        }

        free(stk->p);

        stk->capacity = newCapacity;
        stk->p = newptr;
    }
    stk->p[stk->size] = value;
    stk->size++;
}

int stack_pop(stack *stk)
{
    if (stk->size == 0)
    {
        exit(EFAULT);
    }

    if (stk->size <= stk->capacity / 4)
    {
        int newCapacity = stk->capacity / 2;
        int *newptr = (int *)malloc(newCapacity * sizeof(int));

        for (size_t i = 0; i < stk->size; i++)
        {
            newptr[i] = stk->p[i];
        }

        free(stk->p);

        stk->capacity = newCapacity;
        stk->p = newptr;
    }

    int topVal = stk->p[stk->size - 1];
    stk->size--;

    return topVal;
}
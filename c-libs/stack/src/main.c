#include <stddef.h>
#include <stdio.h>

#include "stack.h"

void printStack(stack *stk);

int main(int argc, char *argv[])
{
    const size_t SIZE = 4;

    stack stk1 = make_stack(SIZE);

    stack_push(&stk1, 1);
    stack_push(&stk1, 2);
    stack_push(&stk1, 3);
    stack_push(&stk1, 4);
    stack_push(&stk1, 5);

    stack stk2 = copy_stack(&stk1);

    printf("%d\n", stack_pop(&stk1));
    printf("%d\n", stack_pop(&stk1));
    printf("%d\n", stack_pop(&stk1));
    printf("%d\n", stack_pop(&stk1));

    printf("size: %ld, capacity: %ld; ", stk1.size, stk1.capacity);
    printStack(&stk1);

    printf("size: %ld, capacity: %ld; ", stk2.size, stk2.capacity);
    printStack(&stk2);

    delete_stack(&stk1);
    delete_stack(&stk2);

    return 0;
}

void printStack(stack *stk)
{
    for (size_t i = 0; i < stk->size; i++)
    {
        printf("%d ", stk->p[i]);
    }
    printf("\n");
}

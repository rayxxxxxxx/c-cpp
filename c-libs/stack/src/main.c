#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include "stack.h"

void printStack(Stack *stack);

int main(int argc, char *argv[])
{
    const size_t SIZE = 4;

    Stack stack1 = make_stack(SIZE);

    stack_push(&stack1, 1);
    stack_push(&stack1, 2);
    stack_push(&stack1, 3);
    stack_push(&stack1, 4);
    stack_push(&stack1, 5);

    Stack stack2 = copy_stack(&stack1);

    printf("%d\n", stack_pop(&stack1));
    printf("%d\n", stack_pop(&stack1));
    printf("%d\n", stack_pop(&stack1));
    printf("%d\n", stack_pop(&stack1));

    printf("size: %ld, capacity: %ld; ", stack1.size, stack1.capacity);
    printStack(&stack1);

    printf("size: %ld, capacity: %ld; ", stack2.size, stack2.capacity);
    printStack(&stack2);

    delete_stack(&stack1);
    delete_stack(&stack2);

    return 0;
}

void printStack(Stack *stack)
{
    for (size_t i = 0; i < stack->size; i++)
    {
        printf("%d ", stack->p[i]);
    }
    printf("\n");
}

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include "queue.h"

void printQueue(Queue *queue);

int main(int argc, char *argv[])
{
    const size_t SIZE = 4;

    Queue queue1 = make_queue(SIZE);

    queue_push(&queue1, 1);
    queue_push(&queue1, 2);
    queue_push(&queue1, 3);
    queue_push(&queue1, 4);
    queue_push(&queue1, 5);

    Queue queue2 = copy_queue(&queue1);

    printf("%d\n", queue_pop(&queue1));
    printf("%d\n", queue_pop(&queue1));
    printf("%d\n", queue_pop(&queue1));
    printf("%d\n", queue_pop(&queue1));

    printf("tail: %ld, capacity: %ld; ", queue1.tail, queue1.capacity);
    printQueue(&queue1);

    printf("tail: %ld, capacity: %ld; ", queue2.tail, queue2.capacity);
    printQueue(&queue2);

    delete_queue(&queue1);
    delete_queue(&queue2);

    return 0;
}

void printQueue(Queue *queue)
{
    for (size_t i = 0; i < queue->tail; i++)
    {
        printf("%d ", queue->p[i]);
    }
    printf("\n");
}
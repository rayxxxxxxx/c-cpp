#include <error.h>
#include <errno.h>
#include <stdlib.h>

#include "queue.h"

Queue make_queue(size_t capacity)
{
    Queue queue;

    queue.capacity = capacity;
    queue.tail = 0;
    queue.p = (int *)malloc(capacity * sizeof(int));

    return queue;
}

Queue copy_queue(Queue *other)
{
    Queue queue;

    queue.capacity = other->capacity;
    queue.tail = other->tail;

    queue.p = (int *)malloc(other->capacity * sizeof(int));
    for (size_t i = 0; i < other->tail; i++)
    {
        queue.p[i] = other->p[i];
    }

    return queue;
}

void delete_queue(Queue *queue)
{
    free(queue->p);
}

int qtail(Queue *queue)
{
    return queue->p[queue->tail];
}

void queue_push(Queue *queue, int value)
{
    if (queue->tail == queue->capacity)
    {
        int newCapacity = queue->capacity * 2;
        int *newptr = (int *)malloc(newCapacity * sizeof(int));

        for (size_t i = 0; i < queue->tail; i++)
        {

            newptr[i] = queue->p[i];
        }
        free(queue->p);

        queue->capacity = newCapacity;
        queue->p = newptr;
    }

    queue->p[queue->tail] = value;
    queue->tail++;
}

int queue_pop(Queue *queue)
{
    if (queue->tail == 0)
    {
        error(1, 1, "queue is empty");
    }

    int headValue = queue->p[0];

    if (queue->tail <= queue->capacity / 4)
    {
        int newCapacity = queue->capacity * 2;
        int *newptr = (int *)malloc(newCapacity * sizeof(int));

        for (size_t i = 1; i < queue->tail; i++)
        {
            newptr[i - 1] = queue->p[i];
        }

        free(queue->p);

        queue->capacity = newCapacity;
        queue->p = newptr;
    }
    else
    {
        for (size_t i = 0; i < queue->tail - 1; i++)
        {
            queue->p[i] = queue->p[i + 1];
        }
    }

    queue->tail--;

    return headValue;
}

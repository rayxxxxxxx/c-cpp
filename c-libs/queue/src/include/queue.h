#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

typedef struct Queue
{
    size_t capacity;
    size_t tail;
    int *p;
} Queue;

Queue make_queue(size_t capacity);
Queue copy_queue(Queue *other);
void delete_queue(Queue *queue);

int queue_top(Queue *queue);

void queue_push(Queue *queue, int value);
int queue_pop(Queue *queue);

#endif
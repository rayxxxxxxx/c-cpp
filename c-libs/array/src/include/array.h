#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

typedef struct array
{
    size_t size;
    int *p;
} array;

array make_array(size_t size);

array copy_array(array *other);

void delete_array(array *arr);

#endif
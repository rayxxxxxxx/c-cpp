#include <stdlib.h>

#include "array.h"

array make_array(size_t size)
{
    array arr;

    arr.size = size;
    arr.p = (int *)calloc(sizeof(int), size);

    return arr;
}

array copy_array(array *other)
{
    array arr;

    arr.size = other->size;
    arr.p = (int *)calloc(sizeof(int), other->size);

    for (size_t i = 0; i < other->size; i++)
    {
        arr.p[i] = other->p[i];
    }

    return arr;
}

void delete_array(array *arr)
{
    free(arr->p);
}

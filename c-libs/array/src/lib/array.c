#include <stdlib.h>
#include <error.h>
#include <errno.h>

#include "array.h"

array make_array(size_t size)
{
    array arr;

    arr.size = size;
    arr.p = (int *)malloc(size * sizeof(int));

    for (size_t i = 0; i < size; i++)
    {
        arr.p[i] = 0;
    }

    return arr;
}

array array_from(int *ptr, size_t size)
{
    array arr;

    arr.size = size;
    arr.p = (int *)malloc(size * sizeof(int));

    for (size_t i = 0; i < size; i++)
    {
        arr.p[i] = ptr[i];
    }

    return arr;
}

array copy_array(array *other)
{
    array arr;

    arr.size = other->size;
    arr.p = (int *)malloc(other->size * sizeof(int));

    for (size_t i = 0; i < other->size; i++)
    {
        arr.p[i] = other->p[i];
    }

    return arr;
}

array slice_array(array *arr, size_t begin, size_t end)
{
    if (begin >= arr->size || end >= arr->size)
    {
        perror("invalid index");
        exit(1);
    }

    size_t sliceSize = end - begin;

    array slice;

    slice.size = sliceSize;
    slice.p = (int *)malloc(sliceSize * sizeof(int));

    for (size_t i = 0; i < sliceSize; i++)
    {
        slice.p[i] = arr->p[begin + i];
    }

    return slice;
}

void delete_array(array *arr)
{
    free(arr->p);
}

void fill_array(array *arr, int value)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        arr->p[i] = value;
    }
}

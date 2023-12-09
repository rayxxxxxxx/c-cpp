#include <stdlib.h>

#include "arrayUtil.h"

array array_from(int *ptr, size_t size)
{
    array arr;

    arr.size = size;
    arr.p = (int *)calloc(sizeof(int), size);

    for (size_t i = 0; i < size; i++)
    {
        arr.p[i] = ptr[i];
    }

    return arr;
}

array array_slice(array *arr, size_t begin, size_t end)
{
    size_t sliceSize = end - begin;

    array slice;

    slice.size = sliceSize;
    slice.p = (int *)calloc(sizeof(int), sliceSize);

    for (size_t i = 0; i < sliceSize; i++)
    {
        slice.p[i] = arr->p[begin + i];
    }

    return slice;
}

array array_reverse(array *arr)
{
    array rarr;

    rarr.size = arr->size;
    rarr.p = (int *)calloc(sizeof(int), arr->size);

    for (size_t i = 0; i < arr->size; i++)
    {
        rarr.p[i] = arr->p[arr->size - i - 1];
    }

    return rarr;
}

int array_min(array *arr)
{
    int min = arr->p[0];

    for (size_t i = 1; i < arr->size; i++)
    {
        if (arr->p[i] < min)
        {
            min = arr->p[i];
        }
    }

    return min;
}

int array_max(array *arr)
{
    int max = arr->p[0];

    for (size_t i = 1; i < arr->size; i++)
    {
        if (arr->p[i] > max)
        {
            max = arr->p[i];
        }
    }

    return max;
}

size_t array_min_idx(array *arr)
{
    size_t minIdx = 0;
    int min = arr->p[0];

    for (size_t i = 1; i < arr->size; i++)
    {
        if (arr->p[i] < min)
        {
            minIdx = i;
            min = arr->p[i];
        }
    }

    return minIdx;
}

size_t array_max_idx(array *arr)
{
    size_t maxIdx = 0;
    int max = arr->p[0];

    for (size_t i = 1; i < arr->size; i++)
    {
        if (arr->p[i] > max)
        {
            maxIdx = i;
            max = arr->p[i];
        }
    }

    return maxIdx;
}

int array_find(array *arr, int value)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        if (arr->p[i] == value)
        {
            return i;
        }
    }

    return -1;
}

int array_find_last(array *arr, int value)
{
    for (size_t i = arr->size - 1; i >= 0; i--)
    {
        if (arr->p[i] == value)
        {
            return i;
        }
    }

    return -1;
}

size_t array_count(array *arr, int value)
{
    size_t c = 0;

    for (size_t i = 0; i < arr->size; i++)
    {
        if (arr->p[i] == value)
        {
            c++;
        }
    }

    return c;
}
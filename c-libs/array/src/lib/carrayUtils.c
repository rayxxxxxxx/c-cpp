#include <stdlib.h>

#include "carrayUtils.h"

void array_swap(array *arr, int i, int j)
{
    int tmp = arr->p[i];
    arr->p[i] = arr->p[j];
    arr->p[j] = tmp;
}

void resize_array(array *arr, int newsize)
{
    arr->p = (int *)realloc(arr->p, newsize * sizeof(int));
    for (int i = arr->size; i < newsize; i++)
        arr->p[i] = 0;
    arr->size = newsize;
}

array concat_arrays(array *arr1, array *arr2)
{
    int ptr = 0;
    array newarr = make_array(arr1->size + arr2->size);

    for (int i = 0; i < arr1->size; i++, ptr++)
        newarr.p[ptr] = arr1->p[i];

    for (int i = 0; i < arr2->size; i++, ptr++)
        newarr.p[ptr] = arr2->p[i];

    return newarr;
}

void extend_array(array *dest, array *src)
{
    resize_array(dest, dest->size + src->size);
    for (int i = dest->size - src->size, j = 0; i < dest->size; i++, j++)
        dest->p[i] = src->p[j];
}

void reverse_array(array *arr)
{
    for (int i = 0; i < arr->size / 2; i++)
        array_swap(arr, i, arr->size - i - 1);
}

array slice_array(array *arr, int begin, int end)
{
    array newarr = make_array(end - begin);
    for (int i = 0; i < newarr.size; i++)
        newarr.p[i] = arr->p[begin + i];
    return newarr;
}

int array_min(array *arr)
{
    int minValue = arr->p[0];
    for (int i = 0; i < arr->size; i++)
        if (arr->p[i] < minValue)
            minValue = arr->p[i];
    return minValue;
}

int array_max(array *arr)
{
    int maxValue = arr->p[0];
    for (int i = 0; i < arr->size; i++)
        if (arr->p[i] > maxValue)
            maxValue = arr->p[i];
    return maxValue;
}

int array_min_idx(array *arr)
{
    int minIdx = 0;
    for (int i = 0; i < arr->size; i++)
        if (arr->p[i] < arr->p[minIdx])
            minIdx = i;
    return minIdx;
}

int array_max_idx(array *arr)
{
    int maxIdx = 0;
    for (int i = 0; i < arr->size; i++)
        if (arr->p[i] > arr->p[maxIdx])
            maxIdx = i;
    return maxIdx;
}

int array_find(array *arr, int value)
{
    for (int i = 0; i < arr->size; i++)
        if (arr->p[i] == value)
            return i;
    return -1;
}

int array_find_last(array *arr, int value)
{
    for (int i = arr->size - 1; i > -1; i--)
        if (arr->p[i] == value)
            return i;
    return -1;
}

int array_count(array *arr, int value)
{
    int c = 0;
    for (int i = 0; i < arr->size; i++)
        if (arr->p[i] == value)
            c++;
    return c;
}
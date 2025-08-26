#include <stdlib.h>
#include <stdarg.h>

#include "carray.h"

array make_array(int size)
{
    array arr;
    arr.size = size;
    arr.p = (int *)calloc(size, sizeof(int));
    return arr;
}

array array_from(int size, ...)
{
    va_list arglist;
    array arr = make_array(size);

    va_start(arglist, size);

    for (int i = 0; i < size; i++)
        arr.p[i] = va_arg(arglist, int);

    va_end(arglist);

    return arr;
}

array copy_array(array *arr)
{
    array arrcp = make_array(arr->size);
    for (int i = 0; i < arr->size; i++)
        arrcp.p[i] = arr->p[i];
    return arrcp;
}

void delete_array(array *arr)
{
    free(arr->p);
    arr->size = 0;
}
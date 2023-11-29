#ifndef ARRAY_H
#define ARRAY_H

typedef struct array
{
    size_t size;
    int *p;
} array;

array make_array(size_t size);
array array_from(int *ptr, size_t size);

array copy_array(array *other);
array slice_array(array *arr, size_t begin, size_t end);

void delete_array(array *arr);

void fill_array(array *arr, int value);

#endif
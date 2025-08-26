#ifndef CARRAY_H
#define CARRAY_H

typedef struct _array
{
    int size;
    int *p;
} array;

array make_array(int size);
array array_from(int size, ...);
array copy_array(array *arr);
void delete_array(array *arr);

#endif
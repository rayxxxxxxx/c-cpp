#ifndef CARRAY_UTILS_H
#define CARRAY_UTILS_H

#include "carray.h"

void array_swap(array *arr, int i, int j);

int array_min(array *arr);
int array_max(array *arr);

int array_min_idx(array *arr);
int array_max_idx(array *arr);

int array_find(array *arr, int value);
int array_find_last(array *arr, int value);

int array_count(array *arr, int value);

void resize_array(array *arr, int newsize);
array slice_array(array *arr, int begin, int end);
void extend_array(array *dest, array *src);
array concat_arrays(array *arr1, array *arr2);
void reverse_array(array *arr);

#endif
#ifndef ARRAY_UTIL_H
#define ARRAY_UTIL_H

#include "array.h"

void array_resize(array *arr, size_t newSize);

array array_from(int *ptr, size_t size);

array array_slice(array *arr, size_t begin, size_t end);

array array_reverse(array *arr);

int array_min(array *arr);

int array_max(array *arr);

size_t array_min_idx(array *arr);

size_t array_max_idx(array *arr);

int array_find(array *arr, int value);

int array_find_last(array *arr, int value);

size_t array_count(array *arr, int value);

array array_unique(array *arr);

#endif
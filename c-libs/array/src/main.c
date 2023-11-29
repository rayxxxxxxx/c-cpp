#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array.h"

void printArray(array *arr)
{
    for (size_t i = 0; i < arr->size; i++)
    {
        printf("%d ", arr->p[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    const size_t SIZE = 5;

    int nums[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    array arr1 = make_array(SIZE);
    array arr2 = array_from((int *)nums, 10);
    array arr3 = copy_array(&arr2);
    array arr4 = slice_array(&arr3, 2, 5);

    printArray(&arr1);
    printArray(&arr2);
    printArray(&arr3);
    printArray(&arr4);

    fill_array(&arr1, 123);
    printArray(&arr1);

    delete_array(&arr1);
    delete_array(&arr2);
    delete_array(&arr3);
    delete_array(&arr4);

    return 0;
}
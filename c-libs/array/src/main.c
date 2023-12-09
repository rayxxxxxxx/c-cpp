#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#include "array.h"
#include "arrayUtil.h"

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

    int nums[14] = {0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    array arr1 = make_array(SIZE);
    array arr2 = array_from((int *)nums, 14);
    array arr3 = copy_array(&arr2);
    array arr4 = array_slice(&arr2, 5, 10);
    array arr5 = array_reverse(&arr2);

    printArray(&arr1);
    printArray(&arr2);
    printArray(&arr3);
    printArray(&arr4);
    printArray(&arr5);

    printf("%d\n", array_min(&arr2));
    printf("%ld\n", array_min_idx(&arr2));

    printf("%d\n", array_max(&arr2));
    printf("%ld\n", array_max_idx(&arr2));

    printf("%d\n", array_find(&arr2, 1));
    printf("%d\n", array_find(&arr2, 100));

    printf("%d\n", array_find(&arr2, 0));
    printf("%d\n", array_find_last(&arr2, 0));

    printf("%ld\n", array_count(&arr2, 0));

    delete_array(&arr1);
    delete_array(&arr2);
    delete_array(&arr3);
    delete_array(&arr4);
    delete_array(&arr5);

    return 0;
}
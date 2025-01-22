#include <stdio.h>

#include "carray.h"
#include "carrayUtils.h"

void print_array(array *arr);

int main(int argc, char **argv)
{
    const int SIZE = 11;

    array arr1 = make_array(SIZE);
    array arr2 = array_from(5, 0, 1, 2, 3, 4);
    array arr3 = array_from(6, 5, 6, 7, 8, 9, 0);
    array arr4 = concat_arrays(&arr2, &arr3);

    print_array(&arr1);
    print_array(&arr2);
    print_array(&arr3);
    print_array(&arr4);

    reverse_array(&arr4);
    print_array(&arr4);

    arr1 = copy_array(&arr4);
    print_array(&arr1);

    delete_array(&arr2);
    delete_array(&arr3);
    delete_array(&arr4);

    printf("%d\n", array_min(&arr1));
    printf("%d\n", array_max(&arr1));
    printf("%d\n", array_min_idx(&arr1));
    printf("%d\n", array_max_idx(&arr1));
    printf("%d\n", array_find(&arr1, 0));
    printf("%d\n", array_find_last(&arr1, 0));
    printf("%d\n", array_count(&arr1, 0));

    resize_array(&arr1, 15);
    print_array(&arr1);

    resize_array(&arr1, 5);
    print_array(&arr1);

    delete_array(&arr1);

    return 0;
}

void print_array(array *arr)
{
    for (int i = 0; i < arr->size; i++)
        printf("%d ", arr->p[i]);
    printf("\n");
}
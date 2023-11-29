#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#include "hashSet.h"

void printHashSet(hset *set);

int main(int argc, char *argv[])
{
    hset set1 = make_hset();

    printHashSet(&set1);

    hset_add(&set1, 111);

    printHashSet(&set1);

    hset_add(&set1, 222);
    hset_add(&set1, 333);
    hset_add(&set1, 444);
    hset_add(&set1, 555);

    printHashSet(&set1);

    hset set2 = copy_hset(&set1);

    printHashSet(&set2);

    printf("%d\n", hset_has(&set2, 555));
    printf("%d\n", hset_has(&set2, 888));

    hset_add(&set1, 666);
    hset_add(&set1, 777);
    hset_add(&set1, 888);

    printHashSet(&set1);

    hset_remove(&set1, 222);
    hset_remove(&set1, 444);
    hset_remove(&set1, 666);
    hset_remove(&set1, 888);

    printHashSet(&set1);
    printHashSet(&set2);

    delete_hset(&set1);
    delete_hset(&set2);

    return 0;
}

void printHashSet(hset *set)
{
    for (size_t i = 0; i < set->size; i++)
    {
        if (set->p[i] == INT_MIN)
        {
            printf("* ");
        }
        else
        {
            printf("%d ", set->p[i]);
        }
    }
    printf("\n");
}
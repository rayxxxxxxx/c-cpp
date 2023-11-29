#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

#include "hashSet.h"

unsigned long gjb2_hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}

size_t prob(size_t i)
{
    return i;
}

hset make_hset()
{
    hset set;

    set.size = 8;
    set.used = 0;

    set.p = (int *)calloc(8, sizeof(int));
    for (size_t i = 0; i < set.size; i++)
    {
        set.p[i] = INT_MIN;
    }

    return set;
}

hset copy_hset(hset *other)
{
    hset set;

    set.size = other->size;
    set.used = other->used;

    set.p = (int *)calloc(other->size, sizeof(int));

    for (size_t i = 0; i < other->size; i++)
    {
        set.p[i] = other->p[i];
    }

    return set;
}

void delete_hset(hset *set)
{
    free(set->p);
}

bool hset_has(hset *set, int value)
{
    char valueStr[10];
    sprintf(valueStr, "%d", value);

    int bucketIdx = gjb2_hash(valueStr) % set->size;

    size_t i = 1;
    while (i <= set->size)
    {
        if (set->p[bucketIdx] == value)
        {
            return true;
        }
        bucketIdx = (bucketIdx + prob(i)) % set->size;
        i++;
    }

    return false;
}

void hset_add(hset *set, int value)
{
    if ((float)set->used / set->size >= 0.75)
    {
        int newSize = set->size * 2;
        int *newp = (int *)calloc(newSize, sizeof(int));
        for (size_t i = 0; i < newSize; i++)
        {
            newp[i] = INT_MIN;
        }

        size_t j;
        size_t bucketIdx;
        char valueStr[10];

        for (size_t i = 0; i < set->size; i++)
        {
            if (set->p[i] != INT_MIN)
            {
                sprintf(valueStr, "%d", set->p[i]);
                bucketIdx = gjb2_hash(valueStr) % newSize;

                j = 1;
                while (newp[bucketIdx] != INT_MIN)
                {
                    bucketIdx = (bucketIdx + prob(j)) % newSize;
                    j++;
                }

                newp[bucketIdx] = set->p[i];
            }
        }

        set->size = newSize;
        free(set->p);
        set->p = newp;
    }

    char valueStr[10];
    sprintf(valueStr, "%d", value);

    int bucketIdx = gjb2_hash(valueStr) % set->size;

    size_t i = 1;
    while (set->p[bucketIdx] != INT_MIN)
    {
        bucketIdx = (bucketIdx + prob(i)) % set->size;
        i++;
    }

    set->p[bucketIdx] = value;
    set->used++;
}

void hset_remove(hset *set, int value)
{
    if (set->used == 0)
    {
        return;
    }

    char valueStr[10];
    sprintf(valueStr, "%d", value);

    int bucketIdx = gjb2_hash(valueStr) % set->size;

    size_t i = 1;
    while (set->p[bucketIdx] != value)
    {
        if (i > set->size)
        {
            return;
        }
        bucketIdx = (bucketIdx + prob(i)) % set->size;
        i++;
    }

    set->p[bucketIdx] = INT_MIN;
    set->used--;
}

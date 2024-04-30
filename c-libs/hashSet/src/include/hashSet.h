#ifndef HASH_SET_H
#define HASH_SET_H

#include <stddef.h>

typedef struct hset
{
    size_t size;
    size_t used;
    int *p;
} hset;

size_t gjb2_hash(char *str);

size_t prob(size_t i);

hset make_hset();
hset copy_hset(hset *other);
void delete_hset(hset *set);
void _rehash_hset(hset *set, int newsize);

bool hset_has(hset *set, int value);

void hset_add(hset *set, int value);
void hset_remove(hset *set, int value);

#endif
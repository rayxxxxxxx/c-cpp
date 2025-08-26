#ifndef MSTRING_H
#define MSTRING_H

#include <stddef.h>
#include <stdlib.h>

typedef struct _string
{
    size_t size;
    char *p;
} string;

size_t mstrlen(char *s);
string make_empty_string(size_t size);
string make_string(char literal[]);
string copy_string(string *s);
void delete_string(string *s);
void resize_string(string *s, size_t newsize);

#endif
#include "mstring.h"

size_t mstrlen(char *s)
{
    size_t count = 0;
    while (s[count] != '\0')
        count++;
    return count;
}

string make_empty_string(size_t size)
{
    string s;
    s.size = size;
    s.p = (char *)calloc(s.size, sizeof(char));
    return s;
}

string make_string(char literal[])
{
    string s = make_empty_string(mstrlen(literal));
    for (size_t i = 0; literal[i] != '\0'; i++)
        s.p[i] = literal[i];
    return s;
}

string copy_string(string *s)
{
    string s_cp = make_empty_string(s->size);
    for (size_t i = 0; i < s->size; i++)
        s_cp.p[i] = s->p[i];
    return s_cp;
}

void delete_string(string *s)
{
    free(s->p);
}

void resize_string(string *s, size_t newsize)
{
    s->p = (char *)realloc(s->p, newsize * sizeof(char));
}
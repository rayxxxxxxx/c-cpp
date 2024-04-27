#include <stdlib.h>

#include "cstring.h"

int _strLiteralSize(char slit[])
{
    int l = 0;
    while (slit[l] != '\0')
        l++;
    return l;
}

Str mkstr(char slit[])
{
    Str s;
    int l = _strLiteralSize(slit);

    s.size = l;
    s.p = (char *)calloc(l + 1, sizeof(char));

    for (int i = 0; i < l + 1; i++)
        s.p[i] = slit[i];

    return s;
}

Str cpstr(Str *s)
{
    Str scp;

    scp.size = s->size;
    scp.p = (char *)calloc(scp.size + 1, sizeof(char));

    for (int i = 0; i < scp.size + 1; i++)
        scp.p[i] = s->p[i];

    return scp;
}

void delstr(Str *s)
{
    free(s->p);
}

Str slicestr(Str *s, int begin, int end)
{
    Str slice;

    slice.size = end - begin;
    slice.p = (char *)calloc(slice.size + 1, sizeof(char));

    for (int i = 0, j = begin; j < end; i++, j++)
        slice.p[i] = s->p[j];
    slice.p[slice.size] = '\0';

    return slice;
}

Str scncts(Str *s1, Str *s2)
{
    Str newstr;
    int i = 0, j = 0;

    newstr.size = s1->size + s2->size;
    newstr.p = (char *)calloc(newstr.size + 1, sizeof(char));

    for (int j = 0; s1->p[j] != '\0'; j++, i++)
        newstr.p[i] = s1->p[j];

    for (int j = 0; s2->p[j] != '\0'; j++, i++)
        newstr.p[i] = s2->p[j];

    newstr.p[newstr.size] = '\0';

    return newstr;
}

Str scnctc(Str *s, char slit[])
{
    Str newstr;
    int i = 0;

    newstr.size = s->size + _strLiteralSize(slit);
    newstr.p = (char *)calloc(newstr.size + 1, sizeof(char));

    for (int j = 0; s->p[j] != '\0'; j++, i++)
        newstr.p[i] = s->p[j];

    for (int j = 0; slit[j] != '\0'; j++, i++)
        newstr.p[i] = slit[j];

    newstr.p[newstr.size] = '\0';

    return newstr;
}

Str ccncts(char slit[], Str *s)
{
    Str newstr;
    int i = 0;

    newstr.size = s->size + _strLiteralSize(slit);
    newstr.p = (char *)calloc(newstr.size + 1, sizeof(char));

    for (int j = 0; slit[j] != '\0'; j++, i++)
        newstr.p[i] = slit[j];

    for (int j = 0; s->p[j] != '\0'; j++, i++)
        newstr.p[i] = s->p[j];

    newstr.p[newstr.size] = '\0';

    return newstr;
}
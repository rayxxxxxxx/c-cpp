#ifndef CSTRING_H
#define CSTRING_H

typedef struct
{
    int size;
    char *p;
} Str;

int _strLiteralSize(char slit[]);

Str mkstr(char slit[]);
Str cpstr(Str *s);
void delstr(Str *s);

Str slicestr(Str *s, int begin, int end);
Str scncts(Str *s1, Str *s2);
Str scnctc(Str *s, char slit[]);
Str ccncts(char slit[], Str *s);

#endif
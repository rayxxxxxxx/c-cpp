#include <stdio.h>

#include "cstring.h"

void printStr(Str *s);

int main(int argc, char *argv[])
{
    Str s1 = mkstr("hello_");
    Str s2 = mkstr("world");
    Str s3 = scncts(&s1, &s2);
    Str s4 = scnctc(&s1, "world");
    Str s5 = ccncts("hello_", &s2);
    Str s6 = cpstr(&s3);
    Str s7 = slicestr(&s4, 3, 8);

    printStr(&s1);
    printStr(&s2);
    printStr(&s3);
    printStr(&s4);
    printStr(&s5);
    printStr(&s6);
    printStr(&s7);

    delstr(&s1);
    delstr(&s2);
    delstr(&s3);
    delstr(&s4);
    delstr(&s5);
    delstr(&s6);
    delstr(&s7);

    return 0;
}

void printStr(Str *s)
{
    int i = 0;
    while (s->p[i] != '\0')
        printf("%c", s->p[i++]);
    printf("\n");
}
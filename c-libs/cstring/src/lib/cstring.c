#include <stdlib.h>
#include <stdarg.h>

#include <cstring.h>

size_t strlen(char *strlit)
{
    size_t c = 0;
    while (strlit[c] != '\0')
        c++;
    return c;
}

char *mkstr(size_t size)
{
    char *str = (char *)calloc(size + 1, sizeof(char));
    for (size_t i = 0; i < size + 1; i++)
        str[i] = '\0';
    return str;
}

char *fromstrlit(char strlit[])
{
    size_t slen = strlen(strlit);
    char *str = (char *)calloc(slen + 1, sizeof(char));
    for (size_t i = 0; i < slen + 1; i++)
        str[i] = strlit[i];
    return str;
}

char *cpstr(char *str)
{
    size_t slen = strlen(str);
    char *newstr = mkstr(slen);
    for (size_t i = 0; i < slen; i++)
        newstr[i] = str[i];
    return newstr;
}

void delstr(char *str)
{
    free(str);
}
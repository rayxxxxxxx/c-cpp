#include "cstringUtils.h"

bool streq(char *lstr, char *rstr)
{
    for (size_t i = 0; i < lstr[i] != '\0'; i++)
        if (lstr[i] != rstr[i])
            return false;
    return true;
}

bool strlt(char *lstr, char *rstr)
{
    size_t i;

    for (i = 0; lstr[i] != '\0' && rstr[i] != '\0'; i++)
        if (lstr[i] != rstr[i])
            return lstr[i] < rstr[i];

    if (lstr[i] == '\0' && rstr[i] != '\0')
        return true;

    return false;
}

bool strgt(char *lstr, char *rstr)
{
    size_t i;

    for (i = 0; lstr[i] != '\0' && rstr[i] != '\0'; i++)
        if (lstr[i] != rstr[i])
            return lstr[i] > rstr[i];

    if (lstr[i] == '\0' && rstr[i] != '\0')
        return false;

    return true;
}

void swapc(char *str, size_t i, size_t j)
{
    char tmp = str[i];
    str[i] = str[j];
    str[j] = tmp;
}

void swaps(char *lstr, char *rstr)
{
    char *tmp = lstr;
    lstr = rstr;
    rstr = tmp;
}

size_t countc(char *str, char ch, size_t skip)
{
    size_t count = 0;
    for (size_t i = skip; i < strlen(str); i++)
        if (str[i] == ch)
            count++;
    return count;
}

char *reverse(char *str)
{
    size_t slen = strlen(str);
    for (size_t i = 0; i < (slen - 1) / 2; i++)
        swapc(str, i, slen - i - 1);
    return str;
}

char *slice(char *str, size_t begin, size_t end)
{
    char *substr = mkstr(end - begin + 1);
    for (size_t i = begin, j = 0; i < end; i++, j++)
        substr[j] = str[i];
    return substr;
}

char *concat(char *lstr, char *rstr)
{
    size_t lstrlen = strlen(lstr);
    size_t rstrlen = strlen(rstr);
    size_t size = lstrlen + rstrlen + 1;
    char *s = cpstr(lstr);

    for (size_t i = lstrlen, j = 0; i < size; i++, j++)
        s[i] = rstr[j];

    return s;
}

char *extend(char *lstr, char *rstr)
{
    size_t lstrlen = strlen(lstr);
    size_t rstrlen = strlen(rstr);
    size_t size = lstrlen + rstrlen + 1;

    lstr = (char *)realloc(lstr, (lstrlen + rstrlen + 1) * sizeof(char));
    for (size_t i = lstrlen, j = 0; i < size; i++, j++)
        lstr[i] = rstr[j];

    return lstr;
}

char *join(char **strs, size_t nstrs, char ch)
{
    size_t k = 0;
    size_t totallen = 0;
    char *newstr = NULL;

    for (size_t i = 0; i < nstrs; i++)
        totallen += strlen(strs[i]);

    newstr = (char *)calloc(totallen + 1, sizeof(char));
    for (size_t i = 0; i < nstrs; i++)
        for (size_t j = 0; j < strlen(strs[i]); j++)
            newstr[k++] = strs[i][j];
    newstr[totallen] = '\0';

    return newstr;
}

char **split(char *str, char ch)
{
    size_t p = 0, q = 0;
    size_t nstrs = 1 + countc(str, ch, 0);
    char **strs = (char **)calloc(nstrs, sizeof(char *));

    for (size_t i = 0; i < nstrs - 1; i++)
    {
        q = findc(str, ch, i);
        strs[i] = slice(str, p, q);
        p = q + 1;
    }
    strs[nstrs - 1] = slice(str, p, strlen(str));

    return strs;
}

long findc(char *str, char ch, size_t skip)
{
    for (size_t i = skip; i < strlen(str) - 1; i++)
        if (str[i] == ch)
            return i;
    return -1;
}

long rfindc(char *str, char ch, size_t skip)
{
    for (size_t i = strlen(str) - 1 - skip; i >= 0; i--)
        if (str[i] == ch)
            return i;
    return -1;
}

long finds(char *str, char *substr)
{
    for (size_t i = 0, j = 0; i < strlen(str); i++)
    {
        if (substr[j] == '\0')
            return i - j;
        j = str[i] == substr[j] ? j + 1 : 0;
    }
    return -1;
}

long rfinds(char *str, char *substr)
{
    size_t slen = strlen(str);
    size_t subslen = strlen(substr);

    for (long i = slen - 1, j = subslen - 1; i > -1; i--)
    {
        if (j == -1)
            return i - j;
        j = str[i] == substr[j] ? j - 1 : subslen - 1;
    }

    return -1;
}
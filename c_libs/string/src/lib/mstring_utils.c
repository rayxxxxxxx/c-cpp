#include "mstring_utils.h"

size_t min(size_t a, size_t b)
{
    return a < b ? a : b;
}

size_t max(size_t a, size_t b)
{
    return a > b ? a : b;
}

void swapc(string *s, size_t i, size_t j)
{
    char c = s->p[i];
    s->p[i] = s->p[j];
    s->p[j] = c;
}

size_t findc(string *s, char c, size_t skip)
{
    for (size_t i = skip; i < s->size; i++)
        if (s->p[i] == c)
            return i;
    return ULLONG_MAX;
}

size_t countc(string *s, char c, size_t skip)
{
    size_t count = 0;
    for (size_t i = skip; i < s->size; i++)
        if (s->p[i] == c)
            count++;
    return count;
}

string reverse(string *s)
{
    string newstr = copy_string(s);
    for (size_t i = 0; i < newstr.size / 2; i++)
        swapc(&newstr, i, newstr.size - i - 1);
    return newstr;
}

string slice(string *s, size_t begin, size_t end)
{
    string substr = make_empty_string(end - begin);
    for (size_t i = 0; i < substr.size; i++)
        substr.p[i] = s->p[begin + i];
    return substr;
}

string concat(string *s1, string *s2)
{
    string newstr = make_empty_string(s1->size + s2->size);
    for (size_t i = 0; i < s1->size; i++)
        newstr.p[i] = s1->p[i];
    for (size_t i = 0; i < s2->size; i++)
        newstr.p[s1->size + i] = s2->p[i];
    return newstr;
}

string *splitc(string *s, char c)
{
    size_t j = 0, k = 0;
    size_t n_strs = countc(s, c, 0) + 1;
    string *strs = (string *)calloc(n_strs, sizeof(string *));

    for (size_t i = 0; i < n_strs; i++)
    {
        k = min(findc(s, c, j), s->size);
        strs[i] = slice(s, j, k);
        j = k + 1;
    }

    return strs;
}

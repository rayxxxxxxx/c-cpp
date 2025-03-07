#include <limits.h>
#include "mstring.h"

size_t min(size_t a, size_t b);
size_t max(size_t a, size_t b);

size_t findc(string *s, char c, size_t skip);
size_t rfindc(string *s, char c, size_t skip);

size_t findl(string *s, char substr[], size_t skip);
size_t rfindl(string *s, char substr[], size_t skip);

size_t finds(string *s, string *substr, size_t skip);
size_t rfinds(string *s, string *substr, size_t skip);

size_t countc(string *s, char c, size_t skip);
size_t countl(string *s, char substr[], size_t skip);
size_t counts(string *s, string *substr, size_t skip);

void swapc(string *s, size_t i, size_t j);
string reverse(string *s);
string slice(string *s, size_t begin, size_t end);
string concat(string *s1, string *s2);

string *splitc(string *s, char c);
string *splitl(string *s, char substr[]);
string *splits(string *s, string *substr);

string *joinc(string *s, char c);
string *joinl(string *s, char substr[]);
string *joins(string *s, string *substr);

string *replacec(string *s, char c, size_t n);
string *replacel(string *s, char substr[], size_t n);
string *replaces(string *s, string *substr, size_t n);

string *insertc(string *s, char c, size_t i);
string *insertl(string *s, char substr[], size_t i);
string *inserts(string *s, string *substr, size_t i);

string *placec(string *s, char c, size_t i);
string *placel(string *s, char substr[], size_t i);
string *places(string *s, string *substr, size_t i);
#ifndef CSTRING_UTILS_H
#define CSTRING_UTILS_H

#include <stdlib.h>
#include <stdbool.h>

#include "cstring.h"

bool streq(char *lstr, char *rstr);
bool strlt(char *lstr, char *rstr);
bool strgt(char *lstr, char *rstr);

void swapc(char *str, size_t i, size_t j);
void swaps(char *lstr, char *rstr);
char *reverse(char *str);

char *slice(char *str, size_t begin, size_t end);

char *concat(char *lstr, char *rstr);
char *extend(char *lstr, char *rstr);
char *join(char **strs, size_t nstrs, char ch);
char **split(char *str, char ch);

long findc(char *str, char ch, size_t skip);
long rfindc(char *str, char ch, size_t skip);

long finds(char *str, char *substr);
long rfinds(char *str, char *substr);

size_t countc(char *str, char ch, size_t skip);
size_t counts(char *str, char *substr, size_t skip);

#endif

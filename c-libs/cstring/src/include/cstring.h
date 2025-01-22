#ifndef CSTRING_H
#define CSTRING_H

size_t strlen(char *strlit);

char *mkstr(size_t size);
char *fromstrlit(char strlit[]);
char *cpstr(char *str);

void delstr(char *str);

#endif
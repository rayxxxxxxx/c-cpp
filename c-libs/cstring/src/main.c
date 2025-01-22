#include <stdio.h>

#include "cstring.h"
#include "cstringUtils.h"

void printstr(char *str);

int main(int argc, char **args)
{
    char *s1 = fromstrlit("Hello");
    char *s2 = fromstrlit("!dlroW ");

    printstr(s1);
    printstr(s2);

    char *s3 = cpstr(s2);
    printstr(s3);

    reverse(s3);
    printstr(s3);

    char *s4 = concat(s1, s3);
    printstr(s4);

    char **strs = (char **)calloc(2, sizeof(char *));
    strs[0] = s1;
    strs[1] = s3;

    char *s5 = join(strs, 2, ' ');
    printstr(s5);

    s1 = extend(s1, s3);
    printstr(s1);

    char *s6 = slice(s4, 3, 8);
    printstr(s6);

    char **words = split(s4, ' ');
    for (size_t i = 0; i < countc(s4, ' ', 0) + 1; i++)
        printstr(words[i]);

    printf("%d\n", streq(s1, s4));
    printf("%d\n", streq(s2, s3));
    printf("%d\n", strlt(s2, s3));
    printf("%d\n", strgt(s2, s3));

    printf("%d\n", findc(s4, 'l', 0));
    printf("%d\n", rfindc(s4, 'l', 0));

    printf("%d\n", finds(s4, "ell"));
    printf("%d\n", rfinds(s4, "ell"));

    printf("%d\n", countc(s4, 'l', 0));

    delstr(s1);
    delstr(s2);
    delstr(s3);
    delstr(s4);
    delstr(s5);
    delstr(s6);
    free(strs);
    free(words);

    return 0;
}

void printstr(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        printf("%c", str[i]);
    printf("\n");
}

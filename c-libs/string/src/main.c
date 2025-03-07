#include <stdio.h>
#include "mstring.h"
#include "mstring_utils.h"

void print_string(string *s);

int main(int argc, char *args[])
{
    string s1 = make_string("Hello");
    string s2 = make_string(" World!");
    string s3 = concat(&s1, &s2);
    string s4 = copy_string(&s3);
    string s5 = slice(&s3, 3, 8);
    string *strs = splitc(&s3, ' ');

    s4 = reverse(&s4);

    print_string(&s1);
    print_string(&s2);
    print_string(&s3);
    print_string(&s4);
    print_string(&s5);

    for (size_t i = 0; i < 2; i++)
        print_string(&strs[i]);

    delete_string(&s1);
    delete_string(&s2);
    delete_string(&s3);
    delete_string(&s4);
    delete_string(&s5);

    return 0;
}

void print_string(string *s)
{
    for (size_t i = 0; i < s->size; i++)
        printf("%c", s->p[i]);
    printf("\n");
}
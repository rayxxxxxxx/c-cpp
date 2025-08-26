#include <stdio.h>

#include "complexnum.h"

void printComplex(cmplx *c);

int main(int argc, char **argv)
{
    cmplx c, m;

    c = cmplxzero();
    printComplex(&c);

    c = cmplxone();
    printComplex(&c);

    c = reone();
    printComplex(&c);

    c = imone();
    printComplex(&c);

    c = makecmplx(2, 3);
    printComplex(&c);

    c = cmplxone();
    printf("%.3f\n", cmplxmag(&c));
    printf("%.3f\n", cmplxarg(&c));

    m = cmplxmult(&c, &c);
    printComplex(&m);

    m = cmplxsquare(&c);
    printComplex(&m);

    m = cmplxdiv(&c, &c);
    printComplex(&m);

    c = cmplxzero();
    printf("%.3f\n", cmplxarg(&c));

    m = cmplxdiv(&c, &c);

    return 0;
}

void printComplex(cmplx *c)
{
    printf("%.2f + %.2f*i\n", c->re, c->im);
}

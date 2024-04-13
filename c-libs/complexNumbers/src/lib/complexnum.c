#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#include "complexnum.h"

cmplx cmplxzero()
{
    cmplx c = {.re = 0, .im = 0};
    return c;
}

cmplx cmplxone()
{
    cmplx c = {.re = 1, .im = 1};
    return c;
}

cmplx reone()
{
    cmplx c = {.re = 1, .im = 0};
    return c;
}

cmplx imone()
{
    cmplx c = {.re = 0, .im = 1};
    return c;
}

cmplx makecmplx(float re, float im)
{
    cmplx c = {.re = re, .im = im};
    return c;
}

cmplx cmplxadd(cmplx *c1, cmplx *c2)
{
    cmplx c;

    c.re = c1->re + c2->re;
    c.im = c1->im + c2->re;

    return c;
}

cmplx cmplxsub(cmplx *c1, cmplx *c2)
{
    cmplx c;

    c.re = c1->re - c2->re;
    c.im = c1->im - c2->re;

    return c;
}

cmplx cmplxmult(cmplx *c1, cmplx *c2)
{
    cmplx c;

    float re = c1->re * c2->re - c1->im * c2->im;
    float im = c1->re * c2->im + c2->re * c1->im;

    c.re = re;
    c.im = im;

    return c;
}

cmplx cmplxdiv(cmplx *c1, cmplx *c2)
{
    if (c2->re == 0 && c2->im == 0)
    {
        perror("division by zero\n");
        exit(ERANGE);
    }

    cmplx c;

    float denominator = c2->re * c2->re + c2->im * c2->im;

    float re = (c1->re * c2->re + c1->im * c2->im) / denominator;
    float im = (c1->im * c2->re - c1->re * c2->im) / denominator;

    c.re = re;
    c.im = im;

    return c;
}

cmplx cmplxsquare(cmplx *c)
{
    cmplx q;

    q.re = c->re * c->re - c->im * c->im;
    q.im = 2 * c->re * c->im;

    return q;
}

float cmplxmag(cmplx *c)
{
    return sqrt(c->re * c->re + c->im * c->im);
}

float cmplxarg(cmplx *c)
{
    if (c->re == 0 && c->im == 0)
    {
        perror("zero complex number\n");
        exit(ERANGE);
    }

    if (c->re == 0.0)
        return (c->im > 0) ? M_PI_2 : 3 * M_PI_2;

    return atan(c->im / c->re);
}

bool cmplxequal(cmplx *c1, cmplx *c2)
{
    return c1->re == c2->re && c1->im == c2->im;
}

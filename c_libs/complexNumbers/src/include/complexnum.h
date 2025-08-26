#ifndef COMPLEXNUM
#define COMPLEXNUM

#include <stdbool.h>

typedef struct
{
    float re;
    float im;
} cmplx;

cmplx cmplxzero();
cmplx cmplxone();
cmplx reone();
cmplx imone();
cmplx makecmplx(float re, float im);

cmplx cmplxadd(cmplx *c1, cmplx *c2);
cmplx cmplxsub(cmplx *c1, cmplx *c2);
cmplx cmplxmult(cmplx *c1, cmplx *c2);
cmplx cmplxdiv(cmplx *c1, cmplx *c2);

cmplx cmplxsquare(cmplx *c);

float cmplxmag(cmplx *c);
float cmplxarg(cmplx *c);

bool cmplxequal(cmplx *c1, cmplx *c2);

#endif

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <math.h>

typedef struct vector
{
    size_t size;
    double *p;
} vector;

vector make_vector(size_t size);
vector copy_vector(vector *other);
void delete_vector(vector *vct);

vector vfrom(double *ptr, size_t size);
vector vzeros(size_t size);
vector vones(size_t size);
vector vfull(size_t size, double value);

vector vaddn(vector *vct, double x);
vector vsubn(vector *vct, double x);
vector vmuln(vector *vct, double x);
vector vdivn(vector *vct, double x);

vector vaddv(vector *lvct, vector *rvct);
vector vsubv(vector *lvct, vector *rvct);
vector vmulv(vector *lvct, vector *rvct);
vector vdivv(vector *lvct, vector *rvct);

double vdot(vector *lvct, vector *rvct);

double vlen(vector *vct);
double vlensqr(vector *vct);

double cosim(vector *lvct, vector *rvct);

double vsum(vector *vct);
double vprod(vector *vct);

vector vnegate(vector *vct);
vector vnorm(vector *vct);
vector vreciprocal(vector *vct);
vector vsquare(vector *vct);
vector vsqrt(vector *vct);
vector vpow(vector *vct, double n);
vector vexp(vector *vct);
vector vsin(vector *vct); // TODO
vector vcos(vector *vct); // TODO
vector vtan(vector *vct); // TODO

#endif
#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <float.h>

typedef struct vector
{
    size_t size;
    float *p;
} vector;

vector make_vector(size_t size);
vector copy_vector(vector *other);
void delete_vector(vector *v);

vector vfrom(float *ptr, size_t size);
vector vzeros(size_t size);
vector vones(size_t size);
vector vfull(size_t size, float value);

vector vaddn(vector *v, float x);
vector vsubn(vector *v, float x);
vector vmuln(vector *v, float x);
vector vdivn(vector *v, float x);

vector vaddv(vector *v1, vector *v2);
vector vsubv(vector *v1, vector *v2);
vector vmulv(vector *v1, vector *v2);
vector vdivv(vector *v1, vector *v2);

float vlen(vector *v);
float vsum(vector *v);
float vprod(vector *v);

float vdot(vector *v1, vector *v2);

vector vnegate(vector *v);
vector vnorm(vector *v);
vector vreciprocal(vector *v);
vector vsquare(vector *v);
vector vsqrt(vector *v);
vector vpow(vector *v, float n);
vector vexp(vector *v);
vector vsin(vector *v);
vector vcos(vector *v);
vector vtan(vector *v);

#endif
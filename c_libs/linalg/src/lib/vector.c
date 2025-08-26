#include <stdlib.h>

#include "vector.h"

vector make_vector(size_t size)
{
    vector newvct;

    newvct.size = size;
    newvct.p = (double *)malloc(size * sizeof(double));

    for (size_t i = 0; i < size; i++)
        newvct.p[i] = 0;

    return newvct;
}

vector copy_vector(vector *other)
{
    vector newvct;

    newvct.size = other->size;
    newvct.p = (double *)malloc(other->size * sizeof(double));

    for (size_t i = 0; i < other->size; i++)
        newvct.p[i] = other->p[i];

    return newvct;
}

void delete_vector(vector *vct)
{
    free(vct->p);
}

vector vector_from(double *ptr, size_t size)
{
    vector newvct;

    newvct.size = size;
    newvct.p = (double *)malloc(size * sizeof(double));

    for (size_t i = 0; i < size; i++)
        newvct.p[i] = ptr[i];

    return newvct;
}

vector vzeros(size_t size)
{
    vector newvct = make_vector(size);

    for (size_t i = 0; i < size; i++)
        newvct.p[i] = 0.0;

    return newvct;
}

vector vones(size_t size)
{
    vector newvct = make_vector(size);

    for (size_t i = 0; i < size; i++)
        newvct.p[i] = 1.0;

    return newvct;
}

vector vfull(size_t size, double value)
{
    vector newvct = make_vector(size);

    for (size_t i = 0; i < size; i++)
        newvct.p[i] = value;

    return newvct;
}

vector vaddn(vector *vct, double x)
{
    vector res = copy_vector(vct);

    for (size_t i = 0; i < vct->size; i++)
        res.p[i] += x;

    return res;
}

vector vsubn(vector *vct, double x)
{
    vector res = copy_vector(vct);

    for (size_t i = 0; i < vct->size; i++)
        res.p[i] -= x;

    return res;
}

vector vmuln(vector *vct, double x)
{
    vector res = copy_vector(vct);

    for (size_t i = 0; i < vct->size; i++)
        res.p[i] *= x;

    return res;
}

vector vdivn(vector *vct, double x)
{
    vector res = copy_vector(vct);

    for (size_t i = 0; i < vct->size; i++)
        res.p[i] /= x;

    return res;
}

vector vaddv(vector *lvct, vector *rvct)
{
    vector res = make_vector(lvct->size);

    for (size_t i = 0; i < lvct->size; i++)
        res.p[i] = lvct->p[i] + rvct->p[i];

    return res;
}

vector vsubv(vector *lvct, vector *rvct)
{
    vector res = make_vector(lvct->size);

    for (size_t i = 0; i < lvct->size; i++)
        res.p[i] = lvct->p[i] - rvct->p[i];

    return res;
}

vector vmulv(vector *lvct, vector *rvct)
{
    vector res = make_vector(lvct->size);

    for (size_t i = 0; i < lvct->size; i++)
        res.p[i] = lvct->p[i] * rvct->p[i];

    return res;
}

vector vdivv(vector *lvct, vector *rvct)
{
    vector res = make_vector(lvct->size);

    for (size_t i = 0; i < lvct->size; i++)
        res.p[i] = lvct->p[i] / rvct->p[i];

    return res;
}

double vdot(vector *lvct, vector *rvct)
{
    double res = 0.0;

    for (size_t i = 0; i < lvct->size; i++)
        res += lvct->p[i] * rvct->p[i];

    return res;
}

double vlen(vector *vct)
{
    return sqrt(vdot(vct, vct));
}

double vlensqr(vector *vct)
{
    return vdot(vct, vct);
}

double cosim(vector *lvct, vector *rvct)
{
    return vdot(lvct, rvct) / (vlen(lvct) * vlen(rvct));
}

double vsum(vector *vct)
{
    double res = 0.0;

    for (size_t i = 0; i < vct->size; i++)
        res += vct->p[i];

    return res;
}

double vprod(vector *vct)
{
    double res = 1.0;

    for (size_t i = 0; i < vct->size; i++)
        res *= vct->p[i];

    return res;
}

vector vnegate(vector *vct)
{
    vector newvct = copy_vector(vct);

    for (size_t i = 0; i < vct->size; i++)
        newvct.p[i] *= -1;

    return newvct;
}

vector vnorm(vector *vct)
{
    vector newvct = copy_vector(vct);

    double l = vlen(vct);

    for (size_t i = 0; i < vct->size; i++)
        newvct.p[i] /= l;

    return newvct;
}

vector vreciprocal(vector *vct)
{
    vector newvct = make_vector(vct->size);

    for (size_t i = 0; i < vct->size; i++)
        newvct.p[i] = 1.0 / vct->p[i];

    return newvct;
}

vector vsquare(vector *vct)
{
    vector newvct = make_vector(vct->size);

    for (size_t i = 0; i < vct->size; i++)
        newvct.p[i] = vct->p[i] * vct->p[i];

    return newvct;
}

vector vsqrt(vector *vct)
{
    vector newvct = make_vector(vct->size);

    for (size_t i = 0; i < vct->size; i++)
        newvct.p[i] = sqrt(vct->p[i]);

    return newvct;
}

vector vpow(vector *vct, double n)
{
    vector newvct = make_vector(vct->size);

    for (size_t i = 0; i < vct->size; i++)
        newvct.p[i] = powf(vct->p[i], n);

    return newvct;
}

vector vexp(vector *vct)
{
    vector newvct = make_vector(vct->size);

    for (size_t i = 0; i < vct->size; i++)
        newvct.p[i] = exp(vct->p[i]);

    return newvct;
}

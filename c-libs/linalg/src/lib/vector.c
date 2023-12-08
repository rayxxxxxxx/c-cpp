#include <stdlib.h>

#include "vector.h"

vector make_vector(size_t size)
{
    vector vct;

    vct.size = size;
    vct.p = (float *)malloc(size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        vct.p[i] = 0;
    }

    return vct;
}

vector vector_from(float *ptr, size_t size)
{
    vector vct;

    vct.size = size;
    vct.p = (float *)malloc(size * sizeof(float));

    for (size_t i = 0; i < size; i++)
    {
        vct.p[i] = ptr[i];
    }

    return vct;
}

vector copy_vector(vector *other)
{
    vector vct;

    vct.size = other->size;
    vct.p = (float *)malloc(other->size * sizeof(float));

    for (size_t i = 0; i < other->size; i++)
    {
        vct.p[i] = other->p[i];
    }

    return vct;
}

void delete_vector(vector *v)
{
    free(v->p);
}
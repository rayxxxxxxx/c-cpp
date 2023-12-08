#include <stdlib.h>

#include "matrix.h"

matrix make_matrix(size_t n, size_t m)
{
    matrix mtrx;

    mtrx.n = n;
    mtrx.m = m;
    mtrx.p = (float **)calloc(sizeof(float *), n);

    for (size_t i = 0; i < n; i++)
    {
        mtrx.p[i] = (float *)calloc(sizeof(float), m);
    }

    return mtrx;
}

matrix matrix_from(float **ptr, size_t n, size_t m)
{
    matrix mtrx;

    mtrx.n = n;
    mtrx.m = m;
    mtrx.p = (float **)calloc(sizeof(float *), n);

    for (size_t i = 0; i < n; i++)
    {
        mtrx.p[i] = (float *)calloc(sizeof(float), m);

        for (size_t j = 0; j < m; j++)
        {
            mtrx.p[i][j] = ptr[i][j];
        }
    }

    return mtrx;
}

matrix copy_matrix(matrix *other)
{
    matrix mtrx;

    mtrx.n = other->n;
    mtrx.m = other->m;
    mtrx.p = (float **)calloc(sizeof(float *), other->n);

    for (size_t i = 0; i < other->n; i++)
    {
        mtrx.p[i] = (float *)calloc(sizeof(float), other->m);

        for (size_t j = 0; j < other->m; j++)
        {
            mtrx.p[i][j] = other->p[i][j];
        }
    }

    return mtrx;
}

void delete_matrix(matrix *mtrx)
{
    for (size_t i = 0; i < mtrx->n; i++)
    {
        free(mtrx->p[i]);
    }

    free(mtrx->p);
}
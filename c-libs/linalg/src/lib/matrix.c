#include <stdlib.h>

#include "matrix.h"

matrix make_matrix(size_t nrow, size_t ncol)
{
    matrix mtrx;

    mtrx.nrow = nrow;
    mtrx.ncol = ncol;
    mtrx.p = (double **)calloc(sizeof(double *), nrow);

    for (size_t i = 0; i < nrow; i++)
        mtrx.p[i] = (double *)calloc(sizeof(double), ncol);

    return mtrx;
}

matrix matrix_from(double **ptr, size_t nrow, size_t ncol)
{
    matrix mtrx;

    mtrx.nrow = nrow;
    mtrx.ncol = ncol;
    mtrx.p = (double **)calloc(sizeof(double *), nrow);

    for (size_t i = 0; i < nrow; i++)
    {
        mtrx.p[i] = (double *)calloc(sizeof(double), ncol);

        for (size_t j = 0; j < ncol; j++)
            mtrx.p[i][j] = ptr[i][j];
    }

    return mtrx;
}

matrix copy_matrix(matrix *other)
{
    matrix mtrx;

    mtrx.nrow = other->nrow;
    mtrx.ncol = other->ncol;
    mtrx.p = (double **)calloc(sizeof(double *), other->nrow);

    for (size_t i = 0; i < other->nrow; i++)
    {
        mtrx.p[i] = (double *)calloc(sizeof(double), other->ncol);

        for (size_t j = 0; j < other->ncol; j++)
            mtrx.p[i][j] = other->p[i][j];
    }

    return mtrx;
}

void delete_matrix(matrix *mtrx)
{
    for (size_t i = 0; i < mtrx->nrow; i++)
        free(mtrx->p[i]);
    free(mtrx->p);
}

matrix mzeros(size_t nrow, size_t ncol)
{
    matrix mtrx = make_matrix(nrow, ncol);

    for (size_t i = 0; i < nrow; i++)
        for (size_t j = 0; j < ncol; j++)
            mtrx.p[i][j] = 0.0;

    return mtrx;
}

matrix mones(size_t nrow, size_t ncol)
{
    matrix mtrx = make_matrix(nrow, ncol);

    for (size_t i = 0; i < nrow; i++)
        for (size_t j = 0; j < ncol; j++)
            mtrx.p[i][j] = 1.0;

    return mtrx;
}

matrix mfull(size_t nrow, size_t ncol, double value)
{
    matrix mtrx = make_matrix(nrow, ncol);

    for (size_t i = 0; i < nrow; i++)
        for (size_t j = 0; j < ncol; j++)
            mtrx.p[i][j] = value;

    return mtrx;
}

matrix mdiag(size_t nrow, double value)
{
    matrix mtrx = make_matrix(nrow, nrow);

    for (size_t i = 0; i < nrow; i++)
        mtrx.p[i][i] = value;

    return mtrx;
}

matrix maddn(matrix *mtrx, double x)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] += x;

    return newmtrx;
}

matrix msubn(matrix *mtrx, double x)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] -= x;

    return newmtrx;
}

matrix mmuln(matrix *mtrx, double x)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] *= x;

    return newmtrx;
}

matrix mdivn(matrix *mtrx, double x)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] /= x;

    return newmtrx;
}

matrix maddm(matrix *lmtrx, matrix *rmtrx)
{
    matrix newmtrx = copy_matrix(lmtrx);

    for (size_t i = 0; i < lmtrx->nrow; i++)
        for (size_t j = 0; j < rmtrx->ncol; j++)
            newmtrx.p[i][j] += rmtrx->p[i][j];

    return newmtrx;
}

matrix msubm(matrix *lmtrx, matrix *rmtrx)
{
    matrix newmtrx = copy_matrix(lmtrx);

    for (size_t i = 0; i < lmtrx->nrow; i++)
        for (size_t j = 0; j < rmtrx->ncol; j++)
            newmtrx.p[i][j] -= rmtrx->p[i][j];

    return newmtrx;
}

matrix mmulm(matrix *lmtrx, matrix *rmtrx)
{
    matrix newmtrx = copy_matrix(lmtrx);

    for (size_t i = 0; i < lmtrx->nrow; i++)
        for (size_t j = 0; j < rmtrx->ncol; j++)
            newmtrx.p[i][j] *= rmtrx->p[i][j];

    return newmtrx;
}

matrix mdivm(matrix *lmtrx, matrix *rmtrx)
{
    matrix newmtrx = copy_matrix(lmtrx);

    for (size_t i = 0; i < lmtrx->nrow; i++)
        for (size_t j = 0; j < rmtrx->ncol; j++)
            newmtrx.p[i][j] /= rmtrx->p[i][j];

    return newmtrx;
}

double msum(matrix *mtrx)
{
    double result = 0.0;

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            result += mtrx->p[i][j];

    return result;
}

double mprod(matrix *mtrx)
{
    double result = 1.0;

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            result *= mtrx->p[i][j];

    return result;
}

matrix mnegate(matrix *mtrx)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] *= -1.0;

    return newmtrx;
}

matrix mreciprocal(matrix *mtrx)
{
    matrix newmtrx = make_matrix(mtrx->nrow, mtrx->ncol);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] = 1.0 / mtrx->p[i][j];

    return newmtrx;
}

matrix msquare(matrix *mtrx)
{
    matrix newmtrx = make_matrix(mtrx->nrow, mtrx->ncol);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] = mtrx->p[i][j] * mtrx->p[i][j];

    return newmtrx;
}

matrix msqrt(matrix *mtrx)
{
    matrix newmtrx = make_matrix(mtrx->nrow, mtrx->ncol);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] = sqrt(mtrx->p[i][j]);

    return newmtrx;
}

matrix mpow(matrix *mtrx, double nrow)
{
    matrix newmtrx = make_matrix(mtrx->nrow, mtrx->ncol);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] = powf(mtrx->p[i][j], nrow);

    return newmtrx;
}

matrix mexp(matrix *mtrx)
{
    matrix newmtrx = make_matrix(mtrx->nrow, mtrx->ncol);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] = exp(mtrx->p[i][j]);

    return newmtrx;
}

#include <stdlib.h>

#include "linalg.h"

vector msumcol(matrix *mtrx)
{
    vector vct = make_vector(mtrx->nrow);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            vct.p[i] += mtrx->p[i][j];

    return vct;
}

vector msumrow(matrix *mtrx)
{
    vector vct = make_vector(mtrx->ncol);

    for (size_t j = 0; j < mtrx->ncol; j++)
        for (size_t i = 0; i < mtrx->nrow; i++)
            vct.p[j] += mtrx->p[i][j];

    return vct;
}

vector mprodcol(matrix *mtrx)
{
    vector vct = vones(mtrx->nrow);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            vct.p[i] *= mtrx->p[i][j];

    return vct;
}

vector mprodrow(matrix *mtrx)
{
    vector vct = vones(mtrx->ncol);

    for (size_t j = 0; j < mtrx->ncol; j++)
        for (size_t i = 0; i < mtrx->nrow; i++)
            vct.p[j] *= mtrx->p[i][j];

    return vct;
}

matrix maddvcol(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t j = 0; j < mtrx->ncol; j++)
        for (size_t i = 0; i < mtrx->nrow; i++)
            newmtrx.p[i][j] += vct->p[i];

    return newmtrx;
}

matrix maddvrow(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] += vct->p[j];

    return newmtrx;
}

matrix msubvcol(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t j = 0; j < mtrx->ncol; j++)
        for (size_t i = 0; i < mtrx->nrow; i++)
            newmtrx.p[i][j] -= vct->p[i];

    return newmtrx;
}

matrix msubvrow(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] -= vct->p[j];

    return newmtrx;
}

matrix mmulvcol(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t j = 0; j < mtrx->ncol; j++)
        for (size_t i = 0; i < mtrx->nrow; i++)
            newmtrx.p[i][j] *= vct->p[i];

    return newmtrx;
}

matrix mmulvrow(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] *= vct->p[j];

    return newmtrx;
}

matrix mdivvcol(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t j = 0; j < mtrx->ncol; j++)
        for (size_t i = 0; i < mtrx->nrow; i++)
            newmtrx.p[i][j] /= vct->p[i];

    return newmtrx;
}

matrix mdivvrow(matrix *mtrx, vector *vct)
{
    matrix newmtrx = copy_matrix(mtrx);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newmtrx.p[i][j] /= vct->p[j];

    return newmtrx;
}

matrix mtranspose(matrix *mtrx)
{
    matrix newmtrx = make_matrix(mtrx->ncol, mtrx->nrow);

    for (size_t i = 0; i < newmtrx.nrow; i++)
        for (size_t j = 0; j < newmtrx.ncol; j++)
            newmtrx.p[i][j] = exp(mtrx->p[j][i]);

    return newmtrx;
}

vector mdotv(matrix *mtrx, vector *vct)
{
    vector newvct = make_vector(mtrx->nrow);

    for (size_t i = 0; i < mtrx->nrow; i++)
        for (size_t j = 0; j < mtrx->ncol; j++)
            newvct.p[i] += mtrx->p[i][j] * vct->p[j];

    return newvct;
}

matrix mdotm(matrix *lmtrx, matrix *rmtrx)
{
    matrix newmtrx = make_matrix(lmtrx->nrow, rmtrx->ncol);

    for (size_t i = 0; i < lmtrx->nrow; i++)
        for (size_t j = 0; j < rmtrx->ncol; j++)
        {
            double q = 0.0;
            for (size_t k = 0; k < lmtrx->ncol; k++)
                q += lmtrx->p[i][k] * rmtrx->p[k][j];
            newmtrx.p[i][j] = q;
        }

    return newmtrx;
}

matrix outer(vector *lvct, vector *rvct)
{
    matrix newmtrx = make_matrix(lvct->size, rvct->size);

    for (size_t i = 0; i < lvct->size; i++)
        for (size_t j = 0; j < rvct->size; j++)
            newmtrx.p[i][j] = lvct->p[i] * rvct->p[j];

    return newmtrx;
}

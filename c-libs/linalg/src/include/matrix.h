#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <math.h>

typedef struct matrix
{
    size_t nrow;
    size_t ncol;
    double **p;
} matrix;

matrix make_matrix(size_t nrow, size_t ncol);
matrix copy_matrix(matrix *other);
void delete_matrix(matrix *mtrx);

matrix mzeros(size_t nrow, size_t ncol);
matrix mones(size_t nrow, size_t ncol);
matrix mfull(size_t nrow, size_t ncol, double value);
matrix mdiag(size_t nrow, double value);

matrix maddn(matrix *mtrx, double x);
matrix msubn(matrix *mtrx, double x);
matrix mmuln(matrix *mtrx, double x);
matrix mdivn(matrix *mtrx, double x);

matrix maddm(matrix *lmtrx, matrix *rmtrx);
matrix msubm(matrix *lmtrx, matrix *rmtrx);
matrix mmulm(matrix *lmtrx, matrix *rmtrx);
matrix mdivm(matrix *lmtrx, matrix *rmtrx);

double msum(matrix *mtrx);
double mprod(matrix *mtrx);

matrix mnegate(matrix *mtrx);
matrix mreciprocal(matrix *mtrx);
matrix msquare(matrix *mtrx);
matrix msqrt(matrix *mtrx);
matrix mpow(matrix *mtrx, double nrow);
matrix mexp(matrix *mtrx);
matrix msin(matrix *mtrx); // TODO
matrix mcos(matrix *mtrx); // TODO
matrix mtan(matrix *mtrx); // TODO

#endif
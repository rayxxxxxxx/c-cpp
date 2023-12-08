#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>
#include <float.h>

typedef struct matrix
{
    size_t n;
    size_t m;
    float **p;
} matrix;

matrix make_matrix(size_t n, size_t m);
matrix copy_matrix(matrix *other);
void delete_matrix(matrix *mtrx);

matrix mzeros(size_t n, size_t m);
matrix mones(size_t n, size_t m);
matrix mfull(size_t n, size_t m, float value);
matrix mdiag(size_t n, float value);

matrix maddn(matrix *m, float x);
matrix msubn(matrix *m, float x);
matrix mmuln(matrix *m, float x);
matrix mdivn(matrix *m, float x);

matrix maddm(matrix *m1, matrix *m2);
matrix msubm(matrix *m1, matrix *m2);
matrix mmulm(matrix *m1, matrix *m2);
matrix mdivm(matrix *m1, matrix *m2);

float msum(matrix *m);
float mprod(matrix *m);

matrix mnegate(matrix *m);
matrix mreciprocal(matrix *m);
matrix msquare(matrix *m);
matrix msqrt(matrix *m);
matrix mpow(matrix *m, float n);
matrix mexp(matrix *m);
matrix msin(matrix *m);
matrix mcos(matrix *m);
matrix mtan(matrix *m);

#endif
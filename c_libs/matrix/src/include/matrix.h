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

matrix matrix_from(float **ptr, size_t n, size_t m);
matrix copy_matrix(matrix *other);

void delete_matrix(matrix *mtrx);

#endif
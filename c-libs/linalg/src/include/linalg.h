#ifndef LINALG_H
#define LINALG_H

#include "vector.h"
#include "matrix.h"

matrix mdotv(matrix *m, vector *v);
matrix mdotm(matrix *m1, matrix *m2);

#endif
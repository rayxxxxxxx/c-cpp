#ifndef LINALG_H
#define LINALG_H

#include "vector.h"
#include "matrix.h"

vector msumcol(matrix *mtrx);
vector msumrow(matrix *mtrx);

vector mprodcol(matrix *mtrx);
vector mprodrow(matrix *mtrx);

matrix maddvcol(matrix *mtrx, vector *vct);
matrix maddvrow(matrix *mtrx, vector *vct);

matrix msubvcol(matrix *mtrx, vector *vct);
matrix msubvrow(matrix *mtrx, vector *vct);

matrix mmulvcol(matrix *mtrx, vector *vct);
matrix mmulvrow(matrix *mtrx, vector *vct);

matrix mdivvcol(matrix *mtrx, vector *vct);
matrix mdivvrow(matrix *mtrx, vector *vct);

matrix mtranspose(matrix *mtrx);

vector mdotv(matrix *mtrx, vector *vct);
matrix mdotm(matrix *lmtrx, matrix *rmtrx);
matrix outer(vector *lvct, vector *rvct);

#endif
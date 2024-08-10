#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "linalg.h"

void printVector(vector *vct);
void printMatrix(matrix *mtrx);

int main(int argc, char *argv[])
{
    const size_t SIZE = 3;
    const size_t NROW = 2;
    const size_t NCOL = 3;

    matrix m1 = mfull(NROW, NCOL, 1.0);
    matrix m2 = mfull(NCOL, NROW, 1.0);
    matrix m3 = mdotm(&m1, &m2);

    printMatrix(&m3);

    delete_matrix(&m1);
    delete_matrix(&m2);
    delete_matrix(&m3);

    return 0;
}

void printVector(vector *vct)
{
    for (size_t i = 0; i < vct->size; i++)
        printf("%.3f ", vct->p[i]);
    printf("\n");
}

void printMatrix(matrix *mtrx)
{
    for (size_t i = 0; i < mtrx->nrow; i++)
    {
        for (size_t j = 0; j < mtrx->ncol; j++)
            printf("%.3f ", mtrx->p[i][j]);
        printf("\n");
    }
    printf("\n");
}
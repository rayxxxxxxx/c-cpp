#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void printMatrix(matrix *mtrx)
{
    for (size_t i = 0; i < mtrx->n; i++)
    {
        for (size_t j = 0; j < mtrx->m; j++)
        {
            printf("%.2f ", mtrx->p[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    const size_t SIZE_N = 3;
    const size_t SIZE_M = 3;

    float nums[2][2] = {{1, 2}, {3, 4}};

    matrix mtrx1 = make_matrix(SIZE_N, SIZE_M);
    // matrix mtrx2 = matrix_from((float **)(nums[0][0]), 2, 2);

    for (size_t i = 0; i < mtrx1.n; i++)
    {
        for (size_t j = 0; j < mtrx1.m; j++)
        {
            mtrx1.p[i][j] = mtrx1.m * i + j + 1;
        }
        printf("\n");
    }

    matrix mtrx3 = copy_matrix(&mtrx1);

    printMatrix(&mtrx1);
    // printMatrix(&mtrx2);
    printMatrix(&mtrx3);

    delete_matrix(&mtrx1);
    // delete_matrix(&mtrx2);
    delete_matrix(&mtrx3);

    return 0;
}
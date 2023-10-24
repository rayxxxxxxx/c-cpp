#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace mtrx
{
    double *Row(double **m, int k, int r, int c);
    double *Col(double **m, int k, int r, int c);

    double **Zeros(int r, int c);
    double **Ones(int r, int c);
    double **Full(int r, int c, double x);
    double **Diag(int n, double x);
    double **Random(int r, int c, int a, int b);
    double **Copy(double **m, int r, int c);

    double **Transpose(double **m, int r, int c);

    double **Add(double **m, double x, int r, int c);
    double **Scale(double **m, double x, int r, int c);

    double **Add(double **m1, double **m2, int r, int c);
    double **Sub(double **m1, double **m2, int r, int c);
}

#endif
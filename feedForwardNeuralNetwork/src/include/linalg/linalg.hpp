#ifndef LINALG_HPP
#define LINALG_HPP

namespace linalg
{
    double Min(double *v, int n);
    double Max(double *v, int n);
    double Mean(double *v, int n);
    double Sum(double *v, int n);
    double Prod(double *v, int n);

    double *Square(double *v, int n);
    double *Pow(double *v, double x, int n);
    double *Sqrt(double *v, int n);
    double *Exp(double *v, int n);
    double *Apply(double (*fnc)(double), double *v, int n);

    double *Abs(double *v, int n);
    double *Clip(double *v, double a, double b, int n);

    double Dot(double *v1, double *v2, int n);

    double Min(double **m, int r, int c);
    double Max(double **m, int r, int c);
    double Mean(double **m, int r, int c);
    double Sum(double **m, int r, int c);
    double Prod(double **m, int r, int c);

    double **Square(double **m, int r, int c);
    double **Pow(double **m, double x, int r, int c);
    double **Sqrt(double **m, int r, int c);
    double **Exp(double **m, int r, int c);
    double **Apply(double (*fnc)(double), double **m, int r, int c);

    double **Abs(double **m, int r, int c);
    double **Clip(double **m, double a, double b, int r, int c);

    double **Mult(double *v1, double *v2, int n1, int n2);
    double **Mult(double **m1, double **m2, int r1, int c1, int r2, int c2);

    double *Dot(double **m, double *v, int r, int c);
}

#endif
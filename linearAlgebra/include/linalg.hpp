#ifndef LINALG_HPP
#define LINALG_HPP

#include "../include/vector.hpp"
#include "../include/matrix.hpp"

namespace linalg
{
    double *Square(double *v, int n);
    double *Pow(double *v, double x, int n);
    double *Sqrt(double *v, int n);
    double *Exp(double *v, int n);

    double **Square(double **m, int r, int c);
    double **Pow(double **m, double x, int r, int c);
    double **Sqrt(double **m, int r, int c);
    double **Exp(double **m, int r, int c);

    double *Dot(double **m, double *v, int r, int c);
    double **Mult(double **m1, double **m2, int r1, int c1, int r2, int c2);
    double *Solve(double **A, double *B, int r, int c);

    vct Square(const vct &v);
    vct Pow(const vct &v, double x);
    vct Sqrt(const vct &v);
    vct Exp(const vct &v);

    mtrx Square(const mtrx &m);
    mtrx Pow(const mtrx &m, double x);
    mtrx Sqrt(const mtrx &m);
    mtrx Exp(const mtrx &m);

    vct Dot(const mtrx &m, const vct &v);
    mtrx Mult(const mtrx &m1, const mtrx &m2);
    vct Solve(const mtrx &A, const vct &B);
}

#endif
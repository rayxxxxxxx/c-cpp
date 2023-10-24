#ifndef LINALG_HPP
#define LINALG_HPP

#include "vector.hpp"
#include "matrix.hpp"

namespace linalg
{
    double Min(double *v, int n);
    double Max(double *v, int n);
    double Mean(double *v, int n);
    double Sum(double *v, int n);
    double Prod(double *v, int n);

    double *Abs(double *v, int n);
    double *Clip(double *v, double a, double b, int n);
    double *Lerp(double *v1, double *v2, double t, int n);

    double *Square(double *v, int n);
    double *Pow(double *v, double x, int n);
    double *Sqrt(double *v, int n);
    double *Exp(double *v, int n);
    double *Apply(double (*fnc)(double), double *v, int n);

    double Min(double **m, int r, int c);
    double Max(double **m, int r, int c);
    double Mean(double **m, int r, int c);
    double Sum(double **m, int r, int c);
    double Prod(double **m, int r, int c);

    double **Abs(double **m, int r, int c);
    double **Clip(double **m, double a, double b, int r, int c);
    double **Lerp(double **m1, double **m2, int r, int c, double t);

    double **Square(double **m, int r, int c);
    double **Pow(double **m, double x, int r, int c);
    double **Sqrt(double **m, int r, int c);
    double **Exp(double **m, int r, int c);
    double **Apply(double (*fnc)(double), double **m, int r, int c);

    double Dot(double *v1, double *v2, int n);
    double *Dot(double **m, double *v, int r, int c);
    double **Mult(double *v1, double *v2, int n1, int n2);
    double **Mult(double **m1, double **m2, int r1, int c1, int r2, int c2);
    double *Solve(double **A, double *B, int r, int c);

    double Min(const vct &v);
    double Max(const vct &v);
    double Mean(const vct &v);
    double Sum(const vct &v);
    double Prod(const vct &v);

    vct Abs(const vct &v);
    vct Clip(const vct &v, double a, double b);
    vct Lerp(const vct &v1, const vct &v2, double t);

    vct Square(const vct &v);
    vct Pow(const vct &v, double x);
    vct Sqrt(const vct &v);
    vct Exp(const vct &v);
    vct Apply(double (*fnc)(double), const vct &v);

    double Min(const mtrx &m);
    double Max(const mtrx &m);
    double Mean(const mtrx &m);
    double Sum(const mtrx &m);
    double Prod(const mtrx &m);

    mtrx Abs(const mtrx &m);
    mtrx Clip(const mtrx &m, double a, double b);
    mtrx Lerp(const mtrx &m1, const mtrx &m2, double t);

    mtrx Square(const mtrx &m);
    mtrx Pow(const mtrx &m, double x);
    mtrx Sqrt(const mtrx &m);
    mtrx Exp(const mtrx &m);
    mtrx Apply(double (*fnc)(double), const mtrx &m);

    double Dot(const vct &v1, const vct &v2);
    vct Dot(const mtrx &m, const vct &v);
    mtrx Mult(const vct &v1, const vct &v2);
    mtrx Mult(const mtrx &m1, const mtrx &m2);
    vct Solve(const mtrx &A, const vct &B);
}

#endif
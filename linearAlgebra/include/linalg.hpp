#ifndef LINALG_HPP
#define LINALG_HPP

#include "vector.hpp"
#include "matrix.hpp"

namespace linalg
{
    double min(double *v, size_t n);
    double max(double *v, size_t n);
    double mean(double *v, size_t n);
    double sum(double *v, size_t n);
    double prod(double *v, size_t n);

    double *abs(double *v, size_t n);
    double *clip(double *v, double a, double b, size_t n);
    double *lerp(double *v1, double *v2, double t, size_t n);

    double *square(double *v, size_t n);
    double *pow(double *v, double x, size_t n);
    double *sqrt(double *v, size_t n);
    double *exp(double *v, size_t n);
    double *map(double (*fnc)(double), double *v, size_t n);

    double min(double **m, size_t r, size_t c);
    double max(double **m, size_t r, size_t c);
    double mean(double **m, size_t r, size_t c);
    double sum(double **m, size_t r, size_t c);
    double prod(double **m, size_t r, size_t c);

    double **abs(double **m, size_t r, size_t c);
    double **clip(double **m, double a, double b, size_t r, size_t c);
    double **lerp(double **m1, double **m2, size_t r, size_t c, double t);

    double **square(double **m, size_t r, size_t c);
    double **pow(double **m, double x, size_t r, size_t c);
    double **sqrt(double **m, size_t r, size_t c);
    double **exp(double **m, size_t r, size_t c);
    double **map(double (*fnc)(double), double **m, size_t r, size_t c);

    double dot(double *v1, double *v2, size_t n);
    double *dot(double **m, double *v, size_t r, size_t c);
    double **mul(double *v1, double *v2, size_t n1, size_t n2);
    double **mul(double **m1, double **m2, size_t r1, size_t c1, size_t r2, size_t c2);
    double *solve(double **A, double *B, size_t r, size_t c);

    double min(const vct &v);
    double max(const vct &v);
    double mean(const vct &v);
    double sum(const vct &v);
    double prod(const vct &v);

    vct abs(const vct &v);
    vct clip(const vct &v, double a, double b);
    vct lerp(const vct &v1, const vct &v2, double t);

    vct square(const vct &v);
    vct pow(const vct &v, double x);
    vct sqrt(const vct &v);
    vct exp(const vct &v);
    vct map(double (*fnc)(double), const vct &v);

    double min(const mtrx &m);
    double max(const mtrx &m);
    double mean(const mtrx &m);
    double sum(const mtrx &m);
    double prod(const mtrx &m);

    mtrx abs(const mtrx &m);
    mtrx clip(const mtrx &m, double a, double b);
    mtrx lerp(const mtrx &m1, const mtrx &m2, double t);

    mtrx square(const mtrx &m);
    mtrx pow(const mtrx &m, double x);
    mtrx sqrt(const mtrx &m);
    mtrx exp(const mtrx &m);
    mtrx map(double (*fnc)(double), const mtrx &m);

    double dot(const vct &v1, const vct &v2);
    vct dot(const mtrx &m, const vct &v);
    mtrx mul(const vct &v1, const vct &v2);
    mtrx mul(const mtrx &m1, const mtrx &m2);
    vct solve(const mtrx &A, const vct &B);
}

#endif
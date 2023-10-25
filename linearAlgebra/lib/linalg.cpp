#include <stdlib.h>
#include <stdexcept>
#include <math.h>

#include "linalg/linalg.hpp"

double linalg::min(double *v, size_t n)
{
    double res = v[0];
    for (size_t i = 1; i < n; i++)
    {
        if (v[i] < res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::max(double *v, size_t n)
{
    double res = v[0];
    for (size_t i = 1; i < n; i++)
    {
        if (v[i] > res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::mean(double *v, size_t n)
{
    double res = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        res += v[i];
    }
    return res / n;
}

double linalg::sum(double *v, size_t n)
{
    double res = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        res += v[i];
    }
    return res;
}

double linalg::prod(double *v, size_t n)
{
    double res = 1.0;
    for (size_t i = 0; i < n; i++)
    {
        res *= v[i];
    }
    return res;
}

double *linalg::abs(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::fabs(v[i]);
    }
    return newvct;
}

double *linalg::clip(double *v, double a, double b, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::max(a, std::min(v[i], b));
    }
    return newvct;
}

double *linalg::lerp(double *v1, double *v2, double t, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = (1 - t) * v1[i] + t * v2[i];
    }
    return newvct;
}

double *linalg::square(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = v[i] * v[i];
    }
    return newvct;
}

double *linalg::pow(double *v, double x, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = powf(v[i], x);
    }
    return newvct;
}

double *linalg::sqrt(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::sqrt(v[i]);
    }
    return newvct;
}

double *linalg::exp(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::exp(v[i]);
    }
    return newvct;
}

double *linalg::map(double (*fnc)(double), double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = fnc(v[i]);
    }
    return newvct;
}

double linalg::min(double **m, size_t r, size_t c)
{
    double res = m[0][0];
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            if (m[i][j] < res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::max(double **m, size_t r, size_t c)
{
    double res = m[0][0];
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            if (m[i][j] > res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::mean(double **m, size_t r, size_t c)
{
    double res = 0.0;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            res += m[i][j];
        }
    }
    return res / (r * c);
}

double linalg::sum(double **m, size_t r, size_t c)
{
    double res = 0.0;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            res += m[i][j];
        }
    }
    return res;
}

double linalg::prod(double **m, size_t r, size_t c)
{
    double res = 1.0;
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            res *= m[i][j];
        }
    }
    return res;
}

double **linalg::abs(double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = std::fabs(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::clip(double **m, double a, double b, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = std::max(a, std::min(m[i][j], b));
        }
    }
    return newmtrx;
}

double **lerp(double **m1, double **m2, size_t r, size_t c, double t)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = (1 - t) * m1[i][j] + t * m2[i][j];
        }
    }
    return newmtrx;
}

double **linalg::square(double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = m[i][j] * m[i][j];
        }
    }
    return newmtrx;
}

double **linalg::pow(double **m, double x, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = powf(m[i][j], x);
        }
    }
    return newmtrx;
}

double **linalg::sqrt(double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = std::sqrt(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::exp(double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = std::exp(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::map(double (*fnc)(double), double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = fnc(m[i][j]);
        }
    }
    return newmtrx;
}

double linalg::dot(double *v1, double *v2, size_t n)
{
    double res = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        res += v1[i] * v2[i];
    }
    return res;
}

double *linalg::dot(double **m, double *v, size_t r, size_t c)
{
    double *newvct = new double[r];
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newvct[i] += m[i][j] * v[j];
        }
    }
    return newvct;
}

double **linalg::mul(double *v1, double *v2, size_t n1, size_t n2)
{
    double **newmtrx = new double *[n1];
    for (size_t i = 0; i < n1; i++)
    {
        newmtrx[i] = new double[n2];
    }
    for (size_t i = 0; i < n1; i++)
    {
        for (size_t j = 0; j < n2; j++)
        {
            newmtrx[i][j] = v1[i] * v2[j];
        }
    }
    return newmtrx;
}

double **linalg::mul(double **m1, double **m2, size_t r1, size_t c1, size_t r2, size_t c2)
{
    double **newmtrx = new double *[r1];
    for (size_t i = 0; i < r1; i++)
    {
        newmtrx[i] = new double[c2];
    }
    for (size_t i = 0; i < r1; i++)
    {
        for (size_t j = 0; j < c2; j++)
        {
            double q = 0.0;
            for (size_t k = 0; k < c1; k++)
            {
                q += m1[i][k] * m2[k][j];
            }
            newmtrx[i][j] = q;
        }
    }
    return newmtrx;
}

double *linalg::solve(double **A, double *B, size_t r, size_t c)
{
    double **copyA = matrix::copy(A, r, c);
    double *copyB = vector::copy(B, c);
    double *X = new double[c];

    for (size_t j = c - 1; j > 0; j--)
    {
        for (size_t i = j - 1; i >= 0; i--)
        {
            copyB[i] = -copyA[i][j] / copyA[j][j] * copyB[j] + copyB[i];
            copyA[i] = vector::add(vector::scale(copyA[j], -copyA[i][j] / copyA[j][j], c), copyA[i], c);
        }
    }

    X[0] = copyB[0] / copyA[0][0];
    for (size_t i = 1; i < r; i++)
    {
        double q = copyB[i];
        for (size_t j = 0; j < i; j++)
        {
            q -= copyA[i][j] * X[j];
        }
        X[i] = q / copyA[i][i];
    }

    return X;
}

double linalg::min(const vct &v)
{
    double res = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] < res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::max(const vct &v)
{
    double res = v[0];
    for (size_t i = 1; i < v.size(); i++)
    {
        if (v[i] > res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::mean(const vct &v)
{
    double res = 0.0;
    for (size_t i = 0; i < v.size(); i++)
    {
        res += v[i];
    }
    return res / v.size();
}

double linalg::sum(const vct &v)
{
    double res = 0.0;
    for (size_t i = 0; i < v.size(); i++)
    {
        res += v[i];
    }
    return res;
}

double linalg::prod(const vct &v)
{
    double res = 1.0;
    for (size_t i = 0; i < v.size(); i++)
    {
        res *= v[i];
    }
    return res;
}

vct linalg::abs(const vct &v)
{
    return vct(linalg::abs(v.ptr(), v.size()), v.size());
}

vct linalg::clip(const vct &v, double a, double b)
{
    return vct(linalg::clip(v.ptr(), a, b, v.size()), v.size());
}

vct linalg::lerp(const vct &v1, const vct &v2, double t)
{
    return vct(linalg::lerp(v1.ptr(), v2.ptr(), t, v1.size()), v1.size());
}

vct linalg::square(const vct &v)
{
    return vct(linalg::square(v.ptr(), v.size()), v.size());
}

vct linalg::pow(const vct &v, double x)
{
    return vct(linalg::pow(v.ptr(), x, v.size()), v.size());
}

vct linalg::sqrt(const vct &v)
{
    return vct(linalg::sqrt(v.ptr(), v.size()), v.size());
}

vct linalg::exp(const vct &v)
{
    return vct(linalg::exp(v.ptr(), v.size()), v.size());
}

vct linalg::map(double (*fnc)(double), const vct &v)
{
    return vct(linalg::map(fnc, v.ptr(), v.size()), v.size());
}

double linalg::min(const mtrx &m)
{
    double res = m[0][0];
    for (size_t i = 0; i < m.nrow(); i++)
    {
        for (size_t j = 0; j < m.ncol(); j++)
        {
            if (m[i][j] < res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::max(const mtrx &m)
{
    double res = m[0][0];
    for (size_t i = 0; i < m.nrow(); i++)
    {
        for (size_t j = 0; j < m.ncol(); j++)
        {
            if (m[i][j] > res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::mean(const mtrx &m)
{
    double res = 0.0;
    for (size_t i = 0; i < m.nrow(); i++)
    {
        for (size_t j = 0; j < m.ncol(); j++)
        {
            res += m[i][j];
        }
    }
    return res / (m.nrow() * m.ncol());
}

double linalg::sum(const mtrx &m)
{
    double res = 0.0;
    for (size_t i = 0; i < m.nrow(); i++)
    {
        for (size_t j = 0; j < m.ncol(); j++)
        {
            res += m[i][j];
        }
    }
    return res;
}

double linalg::prod(const mtrx &m)
{
    double res = 1.0;
    for (size_t i = 0; i < m.nrow(); i++)
    {
        for (size_t j = 0; j < m.ncol(); j++)
        {
            res *= m[i][j];
        }
    }
    return res;
}

mtrx linalg::abs(const mtrx &m)
{
    return mtrx(linalg::abs(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::clip(const mtrx &m, double a, double b)
{
    return mtrx(linalg::clip(m.ptr(), a, b, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx lerp(const mtrx &m1, const mtrx &m2, double t) {}

mtrx linalg::square(const mtrx &m)
{
    return mtrx(linalg::square(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::pow(const mtrx &m, double x)
{
    return mtrx(linalg::pow(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::sqrt(const mtrx &m)
{
    return mtrx(linalg::sqrt(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::exp(const mtrx &m)
{
    return mtrx(linalg::exp(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::map(double (*fnc)(double), const mtrx &m)
{
    return mtrx(linalg::map(fnc, m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

double linalg::dot(const vct &v1, const vct &v2)
{
    return linalg::dot(v1.ptr(), v2.ptr(), v1.size());
}

vct linalg::dot(const mtrx &m, const vct &v)
{
    return vct(linalg::dot(m.ptr(), v.ptr(), m.nrow(), m.ncol()), m.nrow());
}

mtrx linalg::mul(const vct &v1, const vct &v2)
{
    return mtrx(linalg::mul(v1.ptr(), v2.ptr(), v1.size(), v2.size()), v1.size(), v2.size());
}

mtrx linalg::mul(const mtrx &m1, const mtrx &m2)
{
    return mtrx(linalg::mul(m1.ptr(), m2.ptr(), m1.nrow(), m1.ncol(), m2.nrow(), m2.ncol()), m1.nrow(), m2.ncol());
}

vct linalg::solve(const mtrx &A, const vct &B)
{
    return vct(linalg::solve(A.ptr(), B.ptr(), A.nrow(), B.size()), B.size());
}

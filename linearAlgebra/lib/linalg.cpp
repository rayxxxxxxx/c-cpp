#include <stdlib.h>
#include <stdexcept>
#include <math.h>

#include "linalg.hpp"

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

double *linalg::sin(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::sin(v[i]);
    }
    return newvct;
}

double *linalg::cos(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::cos(v[i]);
    }
    return newvct;
}

double *linalg::tan(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::tan(v[i]);
    }
    return newvct;
}

double *linalg::sinh(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::sinh(v[i]);
    }
    return newvct;
}

double *linalg::cosh(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::cosh(v[i]);
    }
    return newvct;
}

double *linalg::tanh(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = std::tanh(v[i]);
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

double **linalg::lerp(double **m1, double **m2, double t, size_t r, size_t c)
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

double **linalg::sin(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = std::sin(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::cos(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = std::cos(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::tan(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = std::tan(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::sinh(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = std::sinh(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::cosh(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = std::cosh(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::tanh(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = std::tanh(m[i][j]);
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

double **linalg::mapRow(double (*fnc)(double), double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = linalg::map(fnc, m[i], c);
    }
    return newmtrx;
}

double **linalg::mapCol(double (*fnc)(double), double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[c];
    for (size_t i = 0; i < c; i++)
    {
        double *col = matrix::col(m, i, r, c);
        newmtrx[i] = linalg::map(fnc, col, r);
        delete[] col;
    }
    double **newmtrxT = matrix::transpose(newmtrx, c, r);
    matrix::Delete(newmtrx, c);
    return newmtrxT;
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
    double *newvct = vector::zeros(r);
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newvct[i] += m[i][j] * v[j];
        }
    }
    return newvct;
}

double *linalg::dot(double *v, double **m, size_t r, size_t c)
{
    double *newvct = vector::zeros(c);
    for (size_t i = 0; i < c; i++)
    {
        for (size_t j = 0; j < r; j++)
        {
            newvct[i] += m[j][i] * v[j];
        }
    }
    return newvct;
}

double **linalg::mul(double *v1, double *v2, size_t n1, size_t n2)
{
    double **newmtrx = matrix::zeros(n1, n2);
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
    double **newmtrx = matrix::zeros(r1, c2);
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
    double **cpA = matrix::copy(A, r, c);
    double *cpB = vector::copy(B, r);
    double *X = new double[c];

    for (size_t j = c - 1; j > 0; j--)
    {
        for (size_t i = j - 1; i >= 0; i--)
        {
            cpB[i] = -cpA[i][j] / cpA[j][j] * cpB[j] + cpB[i];
            cpA[i] = vector::add(vector::mul(cpA[j], -cpA[i][j] / cpA[j][j], c), cpA[i], c);
        }
    }

    X[0] = cpB[0] / cpA[0][0];
    for (size_t i = 1; i < r; i++)
    {
        double q = cpB[i];
        for (size_t j = 0; j < i; j++)
        {
            q -= cpA[i][j] * X[j];
        }
        X[i] = q / cpA[i][i];
    }

    matrix::Delete(cpA, r);
    delete[] cpB;

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

vct linalg::sin(const vct &v)
{
    return vct(linalg::sin(v.ptr(), v.size()), v.size());
}

vct linalg::cos(const vct &v)
{
    return vct(linalg::cos(v.ptr(), v.size()), v.size());
}

vct linalg::tan(const vct &v)
{
    return vct(linalg::tan(v.ptr(), v.size()), v.size());
}

vct linalg::sinh(const vct &v)
{
    return vct(linalg::sinh(v.ptr(), v.size()), v.size());
}

vct linalg::cosh(const vct &v)
{
    return vct(linalg::cosh(v.ptr(), v.size()), v.size());
}

vct linalg::tanh(const vct &v)
{
    return vct(linalg::tanh(v.ptr(), v.size()), v.size());
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

mtrx linalg::lerp(const mtrx &m1, const mtrx &m2, double t)
{
    return mtrx(linalg::lerp(m1.ptr(), m2.ptr(), t, m1.nrow(), m1.ncol()), m1.nrow(), m1.ncol());
}

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

mtrx linalg::sin(const mtrx &m)
{
    return mtrx(linalg::sin(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::cos(const mtrx &m)
{
    return mtrx(linalg::cos(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::tan(const mtrx &m)
{
    return mtrx(linalg::tan(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::sinh(const mtrx &m)
{
    return mtrx(linalg::sinh(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::cosh(const mtrx &m)
{
    return mtrx(linalg::cosh(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::tanh(const mtrx &m)
{
    return mtrx(linalg::tanh(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::map(double (*fnc)(double), const mtrx &m)
{
    return mtrx(linalg::map(fnc, m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::mapRow(double (*fnc)(double), const mtrx &m)
{
    return mtrx(linalg::mapRow(fnc, m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::mapCol(double (*fnc)(double), const mtrx &m)
{
    return mtrx(linalg::mapCol(fnc, m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

double linalg::dot(const vct &v1, const vct &v2)
{
    return linalg::dot(v1.ptr(), v2.ptr(), v1.size());
}

vct linalg::dot(const mtrx &m, const vct &v)
{
    return vct(linalg::dot(m.ptr(), v.ptr(), m.nrow(), m.ncol()), m.nrow());
}

vct linalg::dot(const vct &v, const mtrx &m)
{
    return vct(linalg::dot(v.ptr(), m.ptr(), m.nrow(), m.ncol()), m.ncol());
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

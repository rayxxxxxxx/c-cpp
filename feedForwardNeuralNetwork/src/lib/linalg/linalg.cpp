#include <stdlib.h>
#include <stdexcept>
#include <math.h>

#include "linalg/linalg.hpp"

double linalg::Min(double *v, int n)
{
    double res = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] < res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::Max(double *v, int n)
{
    double res = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::Mean(double *v, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    return res / n;
}

double linalg::Sum(double *v, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    return res;
}

double linalg::Prod(double *v, int n)
{
    double res = 1.0;
    for (int i = 0; i < n; i++)
    {
        res *= v[i];
    }
    return res;
}

double *linalg::Abs(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = fabs(v[i]);
    }
    return newvct;
}

double *linalg::Clip(double *v, double a, double b, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = std::max(a, std::min(v[i], b));
    }
    return newvct;
}

double *linalg::Lerp(double *v1, double *v2, double t, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = (1 - t) * v1[i] + t * v2[i];
    }
    return newvct;
}

double *linalg::Square(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v[i] * v[i];
    }
    return newvct;
}

double *linalg::Pow(double *v, double x, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = powf(v[i], x);
    }
    return newvct;
}

double *linalg::Sqrt(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = sqrt(v[i]);
    }
    return newvct;
}

double *linalg::Exp(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = exp(v[i]);
    }
    return newvct;
}

double *linalg::Apply(double (*fnc)(double), double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = fnc(v[i]);
    }
    return newvct;
}

double linalg::Min(double **m, int r, int c)
{
    double res = m[0][0];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (m[i][j] < res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::Max(double **m, int r, int c)
{
    double res = m[0][0];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (m[i][j] > res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::Mean(double **m, int r, int c)
{
    double res = 0.0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res += m[i][j];
        }
    }
    return res / (r * c);
}

double linalg::Sum(double **m, int r, int c)
{
    double res = 0.0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res += m[i][j];
        }
    }
    return res;
}

double linalg::Prod(double **m, int r, int c)
{
    double res = 1.0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            res *= m[i][j];
        }
    }
    return res;
}

double **linalg::Abs(double **m, int r, int c)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = fabs(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::Clip(double **m, double a, double b, int r, int c)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = std::max(a, std::min(m[i][j], b));
        }
    }
    return newmtrx;
}

double **Lerp(double **m1, double **m2, int r, int c, double t)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = (1 - t) * m1[i][j] + t * m2[i][j];
        }
    }
    return newmtrx;
}

double **linalg::Square(double **m, int r, int c)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = m[i][j] * m[i][j];
        }
    }
    return newmtrx;
}

double **linalg::Pow(double **m, double x, int r, int c)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = powf(m[i][j], x);
        }
    }
    return newmtrx;
}

double **linalg::Sqrt(double **m, int r, int c)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = sqrt(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::Exp(double **m, int r, int c)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = exp(m[i][j]);
        }
    }
    return newmtrx;
}

double **linalg::Apply(double (*fnc)(double), double **m, int r, int c)
{
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = fnc(m[i][j]);
        }
    }
    return newmtrx;
}

double linalg::Dot(double *v1, double *v2, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v1[i] * v2[i];
    }
    return res;
}

double *linalg::Dot(double **m, double *v, int r, int c)
{
    double *newvct = new double[r];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newvct[i] += m[i][j] * v[j];
        }
    }
    return newvct;
}

double **linalg::Mult(double *v1, double *v2, int n1, int n2)
{
    double **newmtrx = new double *[n1];
    for (int i = 0; i < n1; i++)
    {
        newmtrx[i] = new double[n2];
    }
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            newmtrx[i][j] = v1[i] * v2[j];
        }
    }
    return newmtrx;
}

double **linalg::Mult(double **m1, double **m2, int r1, int c1, int r2, int c2)
{
    double **newmtrx = new double *[r1];
    for (int i = 0; i < r1; i++)
    {
        newmtrx[i] = new double[c2];
    }
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            double q = 0.0;
            for (int k = 0; k < c1; k++)
            {
                q += m1[i][k] * m2[k][j];
            }
            newmtrx[i][j] = q;
        }
    }
    return newmtrx;
}

double *linalg::Solve(double **A, double *B, int r, int c)
{
    double **copyA = matrix::Copy(A, r, c);
    double *copyB = vector::Copy(B, c);
    double *X = new double[c];

    for (int j = c - 1; j > 0; j--)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            copyB[i] = -copyA[i][j] / copyA[j][j] * copyB[j] + copyB[i];
            copyA[i] = vector::Add(vector::Scale(copyA[j], -copyA[i][j] / copyA[j][j], c), copyA[i], c);
        }
    }

    X[0] = copyB[0] / copyA[0][0];
    for (int i = 1; i < r; i++)
    {
        double q = copyB[i];
        for (int j = 0; j < i; j++)
        {
            q -= copyA[i][j] * X[j];
        }
        X[i] = q / copyA[i][i];
    }

    return X;
}

double linalg::Min(const vct &v)
{
    double res = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::Max(const vct &v)
{
    double res = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > res)
        {
            res = v[i];
        }
    }
    return res;
}

double linalg::Mean(const vct &v)
{
    double res = 0.0;
    for (int i = 0; i < v.size(); i++)
    {
        res += v[i];
    }
    return res / v.size();
}

double linalg::Sum(const vct &v)
{
    double res = 0.0;
    for (int i = 0; i < v.size(); i++)
    {
        res += v[i];
    }
    return res;
}

double linalg::Prod(const vct &v)
{
    double res = 1.0;
    for (int i = 0; i < v.size(); i++)
    {
        res *= v[i];
    }
    return res;
}

vct linalg::Abs(const vct &v)
{
    return vct(linalg::Abs(v.ptr(), v.size()), v.size());
}

vct linalg::Clip(const vct &v, double a, double b)
{
    return vct(linalg::Clip(v.ptr(), a, b, v.size()), v.size());
}

vct linalg::Lerp(const vct &v1, const vct &v2, double t)
{
    return vct(linalg::Lerp(v1.ptr(), v2.ptr(), t, v1.size()), v1.size());
}

vct linalg::Square(const vct &v)
{
    return vct(linalg::Square(v.ptr(), v.size()), v.size());
}

vct linalg::Pow(const vct &v, double x)
{
    return vct(linalg::Pow(v.ptr(), x, v.size()), v.size());
}

vct linalg::Sqrt(const vct &v)
{
    return vct(linalg::Sqrt(v.ptr(), v.size()), v.size());
}

vct linalg::Exp(const vct &v)
{
    return vct(linalg::Exp(v.ptr(), v.size()), v.size());
}

vct linalg::Apply(double (*fnc)(double), const vct &v)
{
    return vct(linalg::Apply(fnc, v.ptr(), v.size()), v.size());
}

double linalg::Min(const mtrx &m)
{
    double res = m[0][0];
    for (int i = 0; i < m.nrow(); i++)
    {
        for (int j = 0; j < m.ncol(); j++)
        {
            if (m[i][j] < res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::Max(const mtrx &m)
{
    double res = m[0][0];
    for (int i = 0; i < m.nrow(); i++)
    {
        for (int j = 0; j < m.ncol(); j++)
        {
            if (m[i][j] > res)
            {
                res = m[i][j];
            }
        }
    }
    return res;
}

double linalg::Mean(const mtrx &m)
{
    double res = 0.0;
    for (int i = 0; i < m.nrow(); i++)
    {
        for (int j = 0; j < m.ncol(); j++)
        {
            res += m[i][j];
        }
    }
    return res / (m.nrow() * m.ncol());
}

double linalg::Sum(const mtrx &m)
{
    double res = 0.0;
    for (int i = 0; i < m.nrow(); i++)
    {
        for (int j = 0; j < m.ncol(); j++)
        {
            res += m[i][j];
        }
    }
    return res;
}

double linalg::Prod(const mtrx &m)
{
    double res = 1.0;
    for (int i = 0; i < m.nrow(); i++)
    {
        for (int j = 0; j < m.ncol(); j++)
        {
            res *= m[i][j];
        }
    }
    return res;
}

mtrx linalg::Abs(const mtrx &m)
{
    return mtrx(linalg::Abs(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Clip(const mtrx &m, double a, double b)
{
    return mtrx(linalg::Clip(m.ptr(), a, b, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx Lerp(const mtrx &m1, const mtrx &m2, double t) {}

mtrx linalg::Square(const mtrx &m)
{
    return mtrx(linalg::Square(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Pow(const mtrx &m, double x)
{
    return mtrx(linalg::Pow(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Sqrt(const mtrx &m)
{
    return mtrx(linalg::Sqrt(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Exp(const mtrx &m)
{
    return mtrx(linalg::Exp(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Apply(double (*fnc)(double), const mtrx &m)
{
    return mtrx(linalg::Apply(fnc, m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

double linalg::Dot(const vct &v1, const vct &v2)
{
    return linalg::Dot(v1.ptr(), v2.ptr(), v1.size());
}

vct linalg::Dot(const mtrx &m, const vct &v)
{
    return vct(linalg::Dot(m.ptr(), v.ptr(), m.nrow(), m.ncol()), m.nrow());
}

mtrx linalg::Mult(const vct &v1, const vct &v2)
{
    return mtrx(linalg::Mult(v1.ptr(), v2.ptr(), v1.size(), v2.size()), v1.size(), v2.size());
}

mtrx linalg::Mult(const mtrx &m1, const mtrx &m2)
{
    return mtrx(linalg::Mult(m1.ptr(), m2.ptr(), m1.nrow(), m1.ncol(), m2.nrow(), m2.ncol()), m1.nrow(), m2.ncol());
}

vct linalg::Solve(const mtrx &A, const vct &B)
{
    return vct(linalg::Solve(A.ptr(), B.ptr(), A.nrow(), B.size()), B.size());
}

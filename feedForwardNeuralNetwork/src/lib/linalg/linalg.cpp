
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

double *linalg::Apply(double (*fnc)(double), double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = fnc(v[i]);
    }
    return newvct;
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

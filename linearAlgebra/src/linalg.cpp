#include <stdlib.h>
#include <stdexcept>
#include <math.h>

#include "../include/linalg.hpp"

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

vct linalg::Square(const vct &v)
{
    return vct(linalg::Square(v.getP(), v.size()), v.size());
}

vct linalg::Pow(const vct &v, double x)
{
    return vct(linalg::Pow(v.getP(), x, v.size()), v.size());
}

vct linalg::Sqrt(const vct &v)
{
    return vct(linalg::Sqrt(v.getP(), v.size()), v.size());
}

vct linalg::Exp(const vct &v)
{
    return vct(linalg::Exp(v.getP(), v.size()), v.size());
}

mtrx linalg::Square(const mtrx &m)
{
    return mtrx(linalg::Square(m.getM(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Pow(const mtrx &m, double x)
{
    return mtrx(linalg::Pow(m.getM(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Sqrt(const mtrx &m)
{
    return mtrx(linalg::Sqrt(m.getM(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx linalg::Exp(const mtrx &m)
{
    return mtrx(linalg::Exp(m.getM(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

vct linalg::Dot(const mtrx &m, const vct &v)
{
    return vct(linalg::Dot(m.getM(), v.getP(), m.nrow(), m.ncol()), m.nrow());
}

mtrx linalg::Mult(const mtrx &m1, const mtrx &m2)
{
    return mtrx(linalg::Mult(m1.getM(), m2.getM(), m1.nrow(), m1.ncol(), m2.nrow(), m2.ncol()), m1.nrow(), m2.ncol());
}

vct linalg::Solve(const mtrx &A, const vct &B)
{
    return vct(linalg::Solve(A.getM(), B.getP(), A.nrow(), B.size()), B.size());
}

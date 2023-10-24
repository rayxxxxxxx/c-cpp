#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdexcept>

#include "linalg/mtrx.hpp"

double *mtrx::Row(double **m, int k, int r, int c)
{
    double *rw = new double[c];
    for (int j = 0; j < c; j++)
    {
        rw[j] = m[k][j];
    }
    return rw;
}

double *mtrx::Col(double **m, int k, int r, int c)
{
    double *cl = new double[r];
    for (int i = 0; i < r; i++)
    {
        cl[i] = m[i][k];
    }
    return cl;
}

double **mtrx::Zeros(int r, int c)
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
            newmtrx[i][j] = 0.0;
        }
    }
    return newmtrx;
}

double **mtrx::Ones(int r, int c)
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
            newmtrx[i][j] = 1.0;
        }
    }
    return newmtrx;
}

double **mtrx::Full(int r, int c, double x)
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
            newmtrx[i][j] = x;
        }
    }
    return newmtrx;
}

double **mtrx::Diag(int n, double x)
{
    double **newmtrx = new double *[n];
    for (int i = 0; i < n; i++)
    {
        newmtrx[i] = new double[n];
    }
    for (int i = 0; i < n; i++)
    {
        newmtrx[i][i] = x;
    }
    return newmtrx;
}

double **mtrx::Random(int r, int c, int a, int b)
{
    srand(time(NULL));
    double **newmtrx = new double *[r];
    for (int i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[i][j] = a + std::rand() % (b - a);
        }
    }
    return newmtrx;
}

double **mtrx::Copy(double **m, int r, int c)
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
            newmtrx[i][j] = m[i][j];
        }
    }
    return newmtrx;
}

void mtrx::Delete(double **m, int r, int c)
{
    for (size_t i = 0; i < r; i++)
    {
        delete[] m[i];
    }
    delete m;
}

double **mtrx::Transpose(double **m, int r, int c)
{
    double **newmtrx = new double *[c];
    for (int i = 0; i < c; i++)
    {
        newmtrx[i] = new double[r];
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            newmtrx[j][i] = m[i][j];
        }
    }
    return newmtrx;
}

double **mtrx::Add(double **m, double x, int r, int c)
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
            newmtrx[i][j] = m[i][j] + x;
        }
    }
    return newmtrx;
}

double **mtrx::Scale(double **m, double x, int r, int c)
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
            newmtrx[i][j] = x * m[i][j];
        }
    }
    return newmtrx;
}

double **mtrx::Add(double **m1, double **m2, int r, int c)
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
            newmtrx[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return newmtrx;
}

double **mtrx::Sub(double **m1, double **m2, int r, int c)
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
            newmtrx[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return newmtrx;
}

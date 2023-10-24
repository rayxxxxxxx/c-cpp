#include <stdlib.h>
#include <math.h>

#include "linalg/vct.hpp"

double *vct::Zeros(int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = 0.0;
    }
    return newvct;
}

double *vct::Ones(int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = 1.0;
    }
    return newvct;
}

double *vct::Full(int n, double x)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = x;
    }
    return newvct;
}

double vct::Len(double *v, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v[i] * v[i];
    }
    return sqrt(res);
}

double vct::Dist(double *v1, double *v2, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    return sqrt(res);
}

double *vct::Add(double *v, double x, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v[i] + x;
    }
    return newvct;
}

double *vct::Scale(double *v, double x, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = x * v[i];
    }
    return newvct;
}

double *vct::Copy(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v[i];
    }
    return newvct;
}

double *vct::Add(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] + v2[i];
    }
    return newvct;
}

double *vct::Sub(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] - v2[i];
    }
    return newvct;
}

double *vct::Mult(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] * v2[i];
    }
    return newvct;
}

double *vct::Div(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] / v2[i];
    }
    return newvct;
}
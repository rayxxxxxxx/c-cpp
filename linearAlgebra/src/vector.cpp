#include <stdlib.h>
#include <math.h>

#include "../include/vector.hpp"

double *vector::Zeros(int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = 0.0;
    }
    return newvct;
}

double *vector::Ones(int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = 1.0;
    }
    return newvct;
}

double *vector::Full(int n, double x)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = x;
    }
    return newvct;
}

double vector::Min(double *v, int n)
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

double vector::Max(double *v, int n)
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

double vector::Mean(double *v, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    return res / n;
}

double vector::Sum(double *v, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v[i];
    }
    return res;
}

double vector::Prod(double *v, int n)
{
    double res = 1.0;
    for (int i = 0; i < n; i++)
    {
        res *= v[i];
    }
    return res;
}

double vector::Len(double *v, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v[i] * v[i];
    }
    return sqrt(res);
}

double vector::Dist(double *v1, double *v2, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    return sqrt(res);
}

double vector::Dot(double *v1, double *v2, int n)
{
    double res = 0.0;
    for (int i = 0; i < n; i++)
    {
        res += v1[i] * v2[i];
    }
    return res;
}

double *vector::Abs(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = fabs(v[i]);
    }
    return newvct;
}

double *vector::Clip(double *v, double a, double b, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = std::max(a, std::min(v[i], b));
    }
    return newvct;
}

double *vector::Reverse(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v[n - i - 1];
    }
    return newvct;
}

double *vector::Slice(double *v, int ii, int jj)
{
    double *newvct = new double[jj - ii];
    for (int i = 0; i < jj - ii; i++)
    {
        newvct[i] = v[ii + i];
    }
    return newvct;
}

double *vector::Add(double *v, double x, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v[i] + x;
    }
    return newvct;
}

double *vector::Scale(double *v, double x, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = x * v[i];
    }
    return newvct;
}

double *vector::Copy(double *v, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v[i];
    }
    return newvct;
}

double *vector::Add(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] + v2[i];
    }
    return newvct;
}

double *vector::Sub(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] - v2[i];
    }
    return newvct;
}

double *vector::Mult(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] * v2[i];
    }
    return newvct;
}

double *vector::Div(double *v1, double *v2, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = v1[i] / v2[i];
    }
    return newvct;
}

double *vector::Lerp(double *v1, double *v2, double t, int n)
{
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = (1 - t) * v1[i] + t * v2[i];
    }
    return newvct;
}

double *vector::Cross(double *v1, double *v2, int n) {}

double *vector::Conv(double *v1, double *v2, int n1, int n2)
{
    double *newvct = new double[n1 + n2 - 1];
    int k = 0;
    for (int i = 1; i < n2; i++)
    {
        newvct[k] = vector::Dot(vector::Reverse(vector::Slice(v2, 0, i), i), vector::Slice(v1, 0, i), i);
        k++;
    }
    for (int i = 0; i < n1 - n2 + 1; i++)
    {
        newvct[k] = vector::Dot(vector::Reverse(v2, n2), vector::Slice(v1, i, i + n2), n2);
        k++;
    }
    int p = n1 - n2;
    for (int i = 1; i < n2; i++)
    {
        newvct[k] = vector::Dot(vector::Reverse(vector::Slice(v2, i, n2), n2 - i), vector::Slice(v1, p + i, n1), n1 - (p + i));
        k++;
    }
    return newvct;
}

vct::vct()
{
    this->n = 0;
    this->p = nullptr;
}

vct::vct(double *v, int n)
{
    this->n = n;
    this->p = v;
}

vct::vct(const vct &v)
{
    this->n = v.size();
    this->p = new double[this->n];
    for (int i = 0; i < this->n; i++)
    {
        this->p[i] = v[i];
    }
}

vct::~vct()
{
    delete[] this->p;
}

int vct::size() const
{
    return this->n;
}

double *vct::getP() const
{
    return this->p;
}

vct vct::Zeros(int n)
{
    return vct(vector::Zeros(n), n);
}

vct vct::Ones(int n)
{
    return vct(vector::Ones(n), n);
}

vct vct::Full(int n, double x)
{
    return vct(vector::Full(n, x), n);
}

vct vct::Copy(const vct &v)
{
    return vct(vector::Copy(v.p, v.n), v.n);
}

double vct::Min(const vct &v)
{
    double res = v[0];
    for (int i = 1; i < v.n; i++)
    {
        if (v[i] < res)
        {
            res = v[i];
        }
    }
    return res;
}

double vct::Max(const vct &v)
{
    double res = v[0];
    for (int i = 1; i < v.n; i++)
    {
        if (v[i] > res)
        {
            res = v[i];
        }
    }
    return res;
}

double vct::Mean(const vct &v)
{
    double res = 0.0;
    for (int i = 0; i < v.n; i++)
    {
        res += v[i];
    }
    return res / v.n;
}

double vct::Sum(const vct &v)
{
    double res = 0.0;
    for (int i = 0; i < v.n; i++)
    {
        res += v[i];
    }
    return res;
}

double vct::Prod(const vct &v)
{
    double res = 1.0;
    for (int i = 0; i < v.n; i++)
    {
        res *= v[i];
    }
    return res;
}

double vct::Len(const vct &v)
{
    return vector::Len(v.p, v.n);
}

double vct::Dist(const vct &v1, const vct &v2)
{
    return vector::Dist(v1.p, v2.p, v1.n);
}

double vct::Dot(const vct &v1, const vct &v2)
{
    return vector::Dot(v1.p, v2.p, v1.n);
}

vct vct::Abs(const vct &v)
{
    return vct(vector::Abs(v.p, v.n), v.n);
}

vct vct::Clip(const vct &v, double a, double b)
{
    return vct(vector::Clip(v.p, a, b, v.n), v.n);
}

vct vct::Reverse(const vct &v)
{
    return vct(vector::Reverse(v.p, v.n), v.n);
}

vct vct::Slice(const vct &v, int ii, int jj)
{
    return vct(vector::Slice(v.p, ii, jj), v.n);
}

vct vct::Lerp(const vct &v1, const vct &v2, double t)
{
    return vct(vector::Lerp(v1.getP(), v2.getP(), t, v1.size()), v1.size());
}

vct vct::Cross(const vct &v1, const vct &v2) {} // TODO

vct vct::Conv(const vct &v1, const vct &v2)
{
    return vct(vector::Conv(v1.p, v2.p, v1.n, v2.n), v1.n + v2.n - 1);
}

vct &vct::operator=(const vct &v)
{
    delete[] this->p;
    this->n = v.n;
    this->p = vector::Copy(v.p, v.n);
    return *this;
}

double &vct::operator[](int index) const
{
    return this->p[index >= 0 ? index : this->n + index];
}

vct &vct::operator+=(const double &x)
{
    double *newvct = vector::Add(this->p, x, this->n);
    delete[] this->p;
    this->p = newvct;
    return *this;
}

vct &vct::operator-=(const double &x)
{
    double *newvct = vector::Add(this->p, -x, this->n);
    delete[] this->p;
    this->p = newvct;
    return *this;
}

vct &vct::operator*=(const double &x)
{
    double *newvct = vector::Scale(this->p, x, this->n);
    delete[] this->p;
    this->p = newvct;
    return *this;
}

vct &vct::operator/=(const double &x)
{
    double *newvct = vector::Scale(this->p, 1 / x, this->n);
    delete[] this->p;
    this->p = newvct;
    return *this;
}

vct &vct::operator+=(const vct &v2)
{
    double *newvct = vector::Add(this->p, v2.p, this->n);
    delete[] this->p;
    this->p = newvct;
    return *this;
}

vct &vct::operator-=(const vct &v2)
{
    double *newvct = vector::Sub(this->p, v2.p, this->n);
    delete[] this->p;
    this->p = newvct;
    return *this;
}

vct operator+(vct v, const double &x)
{
    v += x;
    return v;
}

vct operator-(vct v, const double &x)
{
    v -= x;
    return v;
}

vct operator*(vct v, const double &x)
{
    v *= x;
    return v;
}

vct operator/(vct v, const double &x)
{
    v /= x;
    return v;
}

vct operator+(vct v1, const vct &v2)
{
    v1 += v2;
    return v1;
}

vct operator-(vct v1, const vct &v2)
{
    v1 -= v2;
    return v1;
}

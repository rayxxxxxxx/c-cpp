#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "linalg/vector.hpp"

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

double *vector::Random(int n, int a, int b)
{
    std::srand((unsigned int)time(NULL));
    double *newvct = new double[n];
    for (int i = 0; i < n; i++)
    {
        newvct[i] = a + std::rand() % (b - a);
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
    this->n = v.n;
    this->p = vector::Copy(v.p, v.n);
}

vct::~vct()
{
    delete[] this->p;
}

int vct::size() const
{
    return this->n;
}

double *vct::ptr() const
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

vct vct::Random(int n, int a, int b)
{
    return vct(vector::Random(n, a, b), n);
}

vct vct::Copy(const vct &v)
{
    return vct(vector::Copy(v.p, v.n), v.n);
}

double vct::Len(const vct &v)
{
    return vector::Len(v.p, v.n);
}

double vct::Dist(const vct &v1, const vct &v2)
{
    return vector::Dist(v1.p, v2.p, v1.n);
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

vct &vct::operator*=(const vct &v2)
{
    double *newvct = vector::Mult(this->p, v2.p, this->n);
    delete[] this->p;
    this->p = newvct;
    return *this;
}

vct &vct::operator/=(const vct &v2)
{
    double *newvct = vector::Div(this->p, v2.p, this->n);
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

vct operator*(vct v1, const vct &v2)
{
    v1 *= v2;
    return v1;
}

vct operator/(vct v1, const vct &v2)
{
    v1 /= v2;
    return v1;
}

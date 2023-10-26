#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "vector.hpp"

double *vector::zeros(size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = 0.0;
    }
    return newvct;
}

double *vector::ones(size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = 1.0;
    }
    return newvct;
}

double *vector::full(size_t n, double x)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = x;
    }
    return newvct;
}

double *vector::random(size_t n, double a, double b)
{
    std::srand(static_cast<unsigned>(time(0)));
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a)));
    }
    return newvct;
}

double *vector::copy(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = v[i];
    }
    return newvct;
}

void vector::Delete(double *v)
{
    delete[] v;
}

double vector::mag(double *v, size_t n)
{
    double res = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        res += v[i] * v[i];
    }
    return std::sqrt(res);
}

double vector::dist(double *v1, double *v2, size_t n)
{
    double res = 0.0;
    for (size_t i = 0; i < n; i++)
    {
        res += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    return std::sqrt(res);
}

double *vector::reciprocal(double *v, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = 1 / v[i];
    }
    return newvct;
}

double *vector::add(double *v, double x, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = v[i] + x;
    }
    return newvct;
}

double *vector::sub(double *v, double x, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = v[i] - x;
    }
    return newvct;
}

double *vector::mul(double *v, double x, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = x * v[i];
    }
    return newvct;
}

double *vector::add(double *v1, double *v2, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = v1[i] + v2[i];
    }
    return newvct;
}

double *vector::sub(double *v1, double *v2, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = v1[i] - v2[i];
    }
    return newvct;
}

double *vector::mul(double *v1, double *v2, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
    {
        newvct[i] = v1[i] * v2[i];
    }
    return newvct;
}

double *vector::div(double *v1, double *v2, size_t n)
{
    double *newvct = new double[n];
    for (size_t i = 0; i < n; i++)
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

vct::vct(double *v, size_t n)
{
    this->n = n;
    this->p = v;
}

vct::vct(const vct &v)
{
    this->n = v.n;
    this->p = vector::copy(v.p, v.n);
}

vct::~vct()
{
    if (this->p != nullptr)
    {
        delete[] this->p;
    }
}

size_t vct::size() const
{
    return this->n;
}

double *vct::ptr() const
{
    return this->p;
}

vct vct::copy() const
{
    return vct(vector::copy(p, n), n);
}

vct vct::zeros(size_t n)
{
    return vct(vector::zeros(n), n);
}

vct vct::ones(size_t n)
{
    return vct(vector::ones(n), n);
}

vct vct::full(size_t n, double x)
{
    return vct(vector::full(n, x), n);
}

vct vct::random(size_t n, double a, double b)
{
    return vct(vector::random(n, a, b), n);
}

vct vct::copy(const vct &v)
{
    return vct(vector::copy(v.p, v.n), v.n);
}

double vct::mag() const
{
    return vector::mag(this->p, this->n);
}

vct vct::reciprocal() const
{
    return vct(vector::reciprocal(this->p, this->n), this->n);
}

double vct::mag(const vct &v)
{
    return vector::mag(v.p, v.n);
}

vct vct::reciprocal(const vct &v)
{
    return vct(vector::reciprocal(v.p, v.n), v.n);
}

double vct::dist(const vct &v1, const vct &v2)
{
    return vector::dist(v1.p, v2.p, v1.n);
}

vct &vct::operator=(const vct &v)
{
    delete[] this->p;
    this->n = v.n;
    this->p = vector::copy(v.p, v.n);
    return *this;
}

double &vct::operator[](size_t index) const
{
    return this->p[index];
}

vct &vct::operator+=(const double &x)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] += x;
    }
    return *this;
}

vct &vct::operator-=(const double &x)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] -= x;
    }
    return *this;
}

vct &vct::operator*=(const double &x)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] *= x;
    }
    return *this;
}

vct &vct::operator/=(const double &x)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] /= x;
    }
    return *this;
}

vct &vct::operator+=(const vct &v)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] += v.p[i];
    }
    return *this;
}

vct &vct::operator-=(const vct &v)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] -= v.p[i];
    }
    return *this;
}

vct &vct::operator*=(const vct &v)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] *= v.p[i];
    }
    return *this;
}

vct &vct::operator/=(const vct &v)
{
    for (size_t i = 0; i < this->n; i++)
    {
        this->p[i] /= v.p[i];
    }
    return *this;
}

vct operator+(const vct &v, const double &x)
{
    return vct(vector::add(v.ptr(), x, v.size()), v.size());
}

vct operator-(const vct &v, const double &x)
{
    return vct(vector::sub(v.ptr(), x, v.size()), v.size());
}

vct operator*(const vct &v, const double &x)
{
    return vct(vector::mul(v.ptr(), x, v.size()), v.size());
}

vct operator/(const vct &v, const double &x)
{
    return vct(vector::mul(v.ptr(), 1 / x, v.size()), v.size());
}

vct operator+(const double &x, const vct &v)
{
    return vct(vector::add(v.ptr(), x, v.size()), v.size());
}

vct operator-(const double &x, const vct &v)
{
    return vct(vector::sub(v.ptr(), x, v.size()), v.size());
}

vct operator*(const double &x, const vct &v)
{
    return vct(vector::mul(v.ptr(), x, v.size()), v.size());
}

vct operator/(const double &x, const vct &v)
{
    return vct(vector::mul(v.ptr(), 1 / x, v.size()), v.size());
}

vct operator+(const vct &v1, const vct &v2)
{
    return vct(vector::add(v1.ptr(), v2.ptr(), v1.size()), v1.size());
}

vct operator-(const vct &v1, const vct &v2)
{
    return vct(vector::sub(v1.ptr(), v2.ptr(), v1.size()), v1.size());
}

vct operator*(const vct &v1, const vct &v2)
{
    return vct(vector::mul(v1.ptr(), v2.ptr(), v1.size()), v1.size());
}

vct operator/(const vct &v1, const vct &v2)
{
    double *rv2 = vector::reciprocal(v2.ptr(), v2.size());
    vct v = vct(vector::mul(v1.ptr(), rv2, v1.size()), v1.size());
    delete[] rv2;
    return v;
}

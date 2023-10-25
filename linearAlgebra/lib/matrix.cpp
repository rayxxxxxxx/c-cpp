#include <stdlib.h>
#include <time.h>
#include <stdexcept>
#include <math.h>

#include "linalg/matrix.hpp"

double *matrix::row(double **m, size_t k, size_t r, size_t c)
{
    double *rw = new double[c];
    for (size_t j = 0; j < c; j++)
    {
        rw[j] = m[k][j];
    }
    return rw;
}

double *matrix::col(double **m, size_t k, size_t r, size_t c)
{
    double *cl = new double[r];
    for (size_t i = 0; i < r; i++)
    {
        cl[i] = m[i][k];
    }
    return cl;
}

double **matrix::zeros(size_t r, size_t c)
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
            newmtrx[i][j] = 0.0;
        }
    }
    return newmtrx;
}

double **matrix::ones(size_t r, size_t c)
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
            newmtrx[i][j] = 1.0;
        }
    }
    return newmtrx;
}

double **matrix::full(size_t r, size_t c, double x)
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
            newmtrx[i][j] = x;
        }
    }
    return newmtrx;
}

double **matrix::diag(size_t n, double x)
{
    double **newmtrx = new double *[n];
    for (size_t i = 0; i < n; i++)
    {
        newmtrx[i] = new double[n];
    }
    for (size_t i = 0; i < n; i++)
    {
        newmtrx[i][i] = x;
    }
    return newmtrx;
}

double **matrix::random(size_t r, size_t c, double a, double b)
{
    std::srand(static_cast<unsigned>(time(0)));
    double **newmtrx = new double *[r];
    for (size_t i = 0; i < r; i++)
    {
        newmtrx[i] = new double[c];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[i][j] = a + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (b - a)));
        }
    }
    return newmtrx;
}

double **matrix::copy(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = m[i][j];
        }
    }
    return newmtrx;
}

void matrix::Delete(double **m, size_t r)
{
    for (size_t i = 0; i < r; i++)
    {
        delete[] m[i];
    }
    delete m;
}

double matrix::det(double **m, size_t r, size_t c)
{
    double **UTriangle = matrix::UTriangle(m, r, c);
    double res = 1.0;
    for (size_t i = 0; i < r; i++)
    {
        res *= UTriangle[i][i];
    }
    return res;
}

double **matrix::reciprocal(double **m, size_t r, size_t c)
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
            newmtrx[i][j] = 1 / m[i][j];
        }
    }
    return newmtrx;
}

double **matrix::transpose(double **m, size_t r, size_t c)
{
    double **newmtrx = new double *[c];
    for (size_t i = 0; i < c; i++)
    {
        newmtrx[i] = new double[r];
    }
    for (size_t i = 0; i < r; i++)
    {
        for (size_t j = 0; j < c; j++)
        {
            newmtrx[j][i] = m[i][j];
        }
    }
    return newmtrx;
}

double **matrix::inverse(double **m, size_t r, size_t c) {}

double **matrix::LTriangle(double **m, size_t r, size_t c)
{
    double **L = matrix::copy(m, r, c);
    for (size_t j = c - 1; j > 0; j--)
    {
        for (size_t i = j - 1; i >= 0; i--)
        {
            L[i] = vector::add(vector::scale(L[j], -L[i][j] / L[j][j], c), L[i], c);
        }
    }
    return L;
}

double **matrix::UTriangle(double **m, size_t r, size_t c)
{
    double **U = matrix::copy(m, r, c);
    for (size_t j = 0; j < c - 1; j++)
    {
        for (size_t i = j + 1; i < r; i++)
        {
            U[i] = vector::add(vector::scale(U[j], -U[i][j] / U[j][j], c), U[i], c);
        }
    }
    return U;
}

double ***matrix::LU(double **m, size_t r, size_t c)
{
    double **L = matrix::diag(r, 1.0);
    double **U = matrix::copy(m, r, c);
    for (size_t j = 0; j < c - 1; j++)
    {
        for (size_t i = j + 1; i < r; i++)
        {
            L[i][j] = U[i][j] / U[j][j];
            U[i] = vector::add(vector::scale(U[j], -U[i][j] / U[j][j], c), U[i], c);
        }
    }
    return new (double **[]){L, U};
}

double **matrix::add(double **m, double x, size_t r, size_t c)
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
            newmtrx[i][j] = m[i][j] + x;
        }
    }
    return newmtrx;
}

double **matrix::sub(double **m, double x, size_t r, size_t c)
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
            newmtrx[i][j] = m[i][j] - x;
        }
    }
    return newmtrx;
}

double **matrix::scale(double **m, double x, size_t r, size_t c)
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
            newmtrx[i][j] = x * m[i][j];
        }
    }
    return newmtrx;
}

double **matrix::add(double **m1, double **m2, size_t r, size_t c)
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
            newmtrx[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return newmtrx;
}

double **matrix::sub(double **m1, double **m2, size_t r, size_t c)
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
            newmtrx[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return newmtrx;
}

double **matrix::scale(double **m1, double **m2, size_t r, size_t c)
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
            newmtrx[i][j] = m1[i][j] * m2[i][j];
        }
    }
    return newmtrx;
}

mtrx::mtrx()
{
    this->r = 0;
    this->c = 0;
    this->m = nullptr;
}

mtrx::mtrx(double **m, size_t r, size_t c)
{
    this->r = r;
    this->c = c;
    this->m = m;
}

mtrx::mtrx(const mtrx &m)
{
    this->r = m.nrow();
    this->c = m.ncol();
    this->m = new double *[this->r];
    for (size_t i = 0; i < this->r; i++)
    {
        this->m[i] = new double[this->c];
    }
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] = m[i][j];
        }
    }
}

mtrx::~mtrx()
{
    for (size_t i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
}

size_t mtrx::nrow() const
{
    return this->r;
}

size_t mtrx::ncol() const
{
    return this->c;
}

double **mtrx::ptr() const
{
    return this->m;
}

vct mtrx::row(const mtrx &m, size_t k)
{
    return vct(matrix::row(m.ptr(), k, m.nrow(), m.ncol()), m.ncol());
}

vct mtrx::col(const mtrx &m, size_t k)
{
    return vct(matrix::col(m.ptr(), k, m.nrow(), m.ncol()), m.nrow());
}

mtrx mtrx::zeros(size_t r, size_t c)
{
    return mtrx(matrix::zeros(r, c), r, c);
}

mtrx mtrx::ones(size_t r, size_t c)
{
    return mtrx(matrix::ones(r, c), r, c);
}

mtrx mtrx::full(size_t r, size_t c, double x)
{
    return mtrx(matrix::full(r, c, x), r, c);
}

mtrx mtrx::diag(size_t n, double x)
{
    return mtrx(matrix::diag(n, x), n, n);
}

mtrx mtrx::random(size_t r, size_t c, double a, double b)
{
    return mtrx(matrix::random(r, c, a, b), r, c);
}

mtrx mtrx::copy(const mtrx &m)
{
    return mtrx(matrix::copy(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

void mtrx::Delete(mtrx &m)
{
    matrix::Delete(m.ptr(), m.r);
}

double mtrx::det(const mtrx &m)
{
    return matrix::det(m.ptr(), m.nrow(), m.ncol());
}

mtrx mtrx::reciprocal(const mtrx &m)
{
    return mtrx(matrix::reciprocal(m.ptr(), m.nrow(), m.ncol()), m.ncol(), m.nrow());
}

mtrx mtrx::transpose(const mtrx &m)
{
    return mtrx(matrix::transpose(m.ptr(), m.nrow(), m.ncol()), m.ncol(), m.nrow());
}

mtrx mtrx::inverse(const mtrx &m) {}

mtrx mtrx::LTriangle(const mtrx &m)
{
    return mtrx(matrix::LTriangle(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx mtrx::UTriangle(const mtrx &m)
{
    return mtrx(matrix::UTriangle(m.ptr(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx *mtrx::LU(const mtrx &m)
{
    double ***dec = matrix::LU(m.ptr(), m.nrow(), m.ncol());
    return new mtrx[]{mtrx(dec[0], m.nrow(), m.ncol()), mtrx(dec[1], m.nrow(), m.ncol())};
}

mtrx &mtrx::operator=(const mtrx &m)
{
    for (size_t i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->r = m.nrow();
    this->c = m.ncol();
    this->m = matrix::copy(m.ptr(), m.nrow(), m.ncol());
    return *this;
}

double *mtrx::operator[](size_t index) const
{
    return this->m[index];
}

mtrx &mtrx::operator+=(const double &x)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] += x;
        }
    }
    return *this;
}

mtrx &mtrx::operator-=(const double &x)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] -= x;
        }
    }
    return *this;
}

mtrx &mtrx::operator*=(const double &x)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] *= x;
        }
    }
    return *this;
}

mtrx &mtrx::operator/=(const double &x)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] /= x;
        }
    }
    return *this;
}

mtrx &mtrx::operator+=(const mtrx &m)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] += m[i][j];
        }
    }
    return *this;
}

mtrx &mtrx::operator-=(const mtrx &m)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] -= m[i][j];
        }
    }
    return *this;
}

mtrx &mtrx::operator*=(const mtrx &m)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] *= m[i][j];
        }
    }
    return *this;
}

mtrx &mtrx::operator/=(const mtrx &m)
{
    for (size_t i = 0; i < this->r; i++)
    {
        for (size_t j = 0; j < this->c; j++)
        {
            this->m[i][j] /= m[i][j];
        }
    }
    return *this;
}

mtrx operator+(const mtrx &m, const double &x)
{
    return mtrx(matrix::add(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator-(const mtrx &m, const double &x)
{
    return mtrx(matrix::sub(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator*(const mtrx &m, const double &x)
{
    return mtrx(matrix::scale(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator/(const mtrx &m, const double &x)
{
    return mtrx(matrix::scale(m.ptr(), 1 / x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator+(const double &x, const mtrx &m)
{
    return mtrx(matrix::add(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator-(const double &x, const mtrx &m)
{
    return mtrx(matrix::sub(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator*(const double &x, const mtrx &m)
{
    return mtrx(matrix::scale(m.ptr(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator/(const double &x, const mtrx &m)
{
    return mtrx(matrix::scale(m.ptr(), 1 / x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx operator+(const mtrx &m1, const mtrx &m2)
{
    return mtrx(matrix::add(m1.ptr(), m2.ptr(), m1.nrow(), m1.ncol()), m1.nrow(), m1.ncol());
}

mtrx operator-(const mtrx &m1, const mtrx &m2)
{
    return mtrx(matrix::sub(m1.ptr(), m2.ptr(), m1.nrow(), m1.ncol()), m1.nrow(), m1.ncol());
}

mtrx operator*(const mtrx &m1, const mtrx &m2)
{
    return mtrx(matrix::scale(m1.ptr(), m2.ptr(), m1.nrow(), m1.ncol()), m1.nrow(), m1.ncol());
}

mtrx operator/(const mtrx &m1, const mtrx &m2)
{
    double **rm2 = matrix::reciprocal(m2.ptr(), m2.nrow(), m2.ncol());
    mtrx m = mtrx(matrix::scale(m1.ptr(), rm2, m1.nrow(), m1.ncol()), m1.nrow(), m1.ncol());
    matrix::Delete(rm2, m2.nrow());
    return m;
}

#include <stdexcept>
#include <stdlib.h>
#include <math.h>

#include "../include/matrix.hpp"

double *matrix::Row(double **m, int k, int r, int c)
{
    double *rw = new double[c];
    for (int j = 0; j < c; j++)
    {
        rw[j] = m[k][j];
    }
    return rw;
}

double *matrix::Col(double **m, int k, int r, int c)
{
    double *cl = new double[r];
    for (int i = 0; i < r; i++)
    {
        cl[i] = m[i][k];
    }
    return cl;
}

double **matrix::Zeros(int r, int c)
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

double **matrix::Ones(int r, int c)
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

double **matrix::Full(int r, int c, double x)
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

double **matrix::Diag(int n, double x)
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

double **matrix::Copy(double **m, int r, int c)
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

double matrix::Min(double **m, int r, int c)
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

double matrix::Max(double **m, int r, int c)
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

double matrix::Mean(double **m, int r, int c)
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

double matrix::Sum(double **m, int r, int c)
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

double matrix::Prod(double **m, int r, int c)
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

double matrix::Det(double **m, int r, int c)
{
    double **UTriangle = matrix::UTriangle(m, r, c);
    double res = 1.0;
    for (int i = 0; i < r; i++)
    {
        res *= UTriangle[i][i];
    }
    return res;
}

double **matrix::Abs(double **m, int r, int c)
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

double **matrix::Clip(double **m, double a, double b, int r, int c)
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

double **matrix::Transpose(double **m, int r, int c)
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

double **matrix::InverseMatrix(double **m, int r, int c) {}

double **matrix::LTriangle(double **m, int r, int c)
{
    double **L = matrix::Copy(m, r, c);
    for (int j = c - 1; j > 0; j--)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            L[i] = vector::Add(vector::Scale(L[j], -L[i][j] / L[j][j], c), L[i], c);
        }
    }
    return L;
}

double **matrix::UTriangle(double **m, int r, int c)
{
    double **U = matrix::Copy(m, r, c);
    for (int j = 0; j < c - 1; j++)
    {
        for (int i = j + 1; i < r; i++)
        {
            U[i] = vector::Add(vector::Scale(U[j], -U[i][j] / U[j][j], c), U[i], c);
        }
    }
    return U;
}

double ***matrix::LU(double **m, int r, int c)
{
    double **L = matrix::Diag(r, 1.0);
    double **U = matrix::Copy(m, r, c);
    for (int j = 0; j < c - 1; j++)
    {
        for (int i = j + 1; i < r; i++)
        {
            L[i][j] = U[i][j] / U[j][j];
            U[i] = vector::Add(vector::Scale(U[j], -U[i][j] / U[j][j], c), U[i], c);
        }
    }
    return new (double **[]){L, U};
}

double **matrix::Add(double **m, double x, int r, int c)
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

double **matrix::Scale(double **m, double x, int r, int c)
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

double **matrix::Add(double **m1, double **m2, int r, int c)
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

double **matrix::Sub(double **m1, double **m2, int r, int c)
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

double **matrix::Mult(double **m1, double **m2, int r1, int c1, int r2, int c2)
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

mtrx::mtrx()
{
    this->r = 0;
    this->c = 0;
    this->m = nullptr;
}

mtrx::mtrx(double **m, int r, int c)
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
    for (int i = 0; i < this->r; i++)
    {
        this->m[i] = new double[this->c];
    }
    for (int i = 0; i < this->r; i++)
    {
        for (int j = 0; j < this->c; j++)
        {
            this->m[i][j] = m[i][j];
        }
    }
}

mtrx::~mtrx()
{
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
}

int mtrx::nrow() const
{
    return this->r;
}

int mtrx::ncol() const
{
    return this->c;
}

double **mtrx::getM() const
{
    return this->m;
}

vct mtrx::Row(const mtrx &m, int k)
{
    return vct(matrix::Row(m.getM(), k, m.nrow(), m.ncol()), m.ncol());
}

vct mtrx::Col(const mtrx &m, int k)
{
    return vct(matrix::Col(m.getM(), k, m.nrow(), m.ncol()), m.nrow());
}

mtrx mtrx::Zeros(int r, int c)
{
    return mtrx(matrix::Zeros(r, c), r, c);
}

mtrx mtrx::Ones(int r, int c)
{
    return mtrx(matrix::Ones(r, c), r, c);
}

mtrx mtrx::Full(int r, int c, double x)
{
    return mtrx(matrix::Full(r, c, x), r, c);
}

mtrx mtrx::Diag(int n, double x)
{
    return mtrx(matrix::Diag(n, x), n, n);
}

mtrx mtrx::Copy(const mtrx &m)
{
    return mtrx(matrix::Copy(m.getM(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

double mtrx::Min(const mtrx &m)
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

double mtrx::Max(const mtrx &m)
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

double mtrx::Mean(const mtrx &m)
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

double mtrx::Sum(const mtrx &m)
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

double mtrx::Prod(const mtrx &m)
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

double mtrx::Det(const mtrx &m)
{
    return matrix::Det(m.getM(), m.nrow(), m.ncol());
}

mtrx mtrx::Abs(const mtrx &m)
{
    return mtrx(matrix::Abs(m.getM(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx mtrx::Clip(const mtrx &m, double a, double b)
{
    return mtrx(matrix::Clip(m.getM(), a, b, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx mtrx::Transpose(const mtrx &m)
{
    return mtrx(matrix::Transpose(m.getM(), m.nrow(), m.ncol()), m.ncol(), m.nrow());
}

mtrx mtrx::InverseMatrix(const mtrx &m) {}

mtrx mtrx::LTriangle(const mtrx &m)
{
    return mtrx(matrix::LTriangle(m.getM(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx mtrx::UTriangle(const mtrx &m)
{
    return mtrx(matrix::UTriangle(m.getM(), m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx *mtrx::LU(const mtrx &m)
{
    double ***dec = matrix::LU(m.getM(), m.nrow(), m.ncol());
    return new mtrx[]{mtrx(dec[0], m.nrow(), m.ncol()), mtrx(dec[1], m.nrow(), m.ncol())};
}

mtrx mtrx::Add(const mtrx &m, double x)
{
    return mtrx(matrix::Add(m.getM(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx mtrx::Scale(const mtrx &m, double x)
{
    return mtrx(matrix::Scale(m.getM(), x, m.nrow(), m.ncol()), m.nrow(), m.ncol());
}

mtrx &mtrx::operator=(const mtrx &m)
{
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->r = m.nrow();
    this->c = m.ncol();
    this->m = matrix::Copy(m.getM(), m.nrow(), m.ncol());
    return *this;
}

double *mtrx::operator[](int index) const
{
    return this->m[index];
}

mtrx &mtrx::operator+=(const double &x)
{
    double **newmtrx = matrix::Add(this->m, x, this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = newmtrx;
    return *this;
}

mtrx &mtrx::operator-=(const double &x)
{
    double **newmtrx = matrix::Add(this->m, -x, this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = newmtrx;
    return *this;
}

mtrx &mtrx::operator*=(const double &x)
{
    double **newmtrx = matrix::Scale(this->m, x, this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = newmtrx;
    return *this;
}

mtrx &mtrx::operator/=(const double &x)
{
    double **newmtrx = matrix::Scale(this->m, 1 / x, this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = newmtrx;
    return *this;
}

mtrx &mtrx::operator+=(const mtrx &m)
{
    double **newmtrx = matrix::Add(this->m, m.getM(), this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = newmtrx;
    return *this;
}

mtrx &mtrx::operator-=(const mtrx &m)
{
    double **newmtrx = matrix::Sub(this->m, m.getM(), this->r, this->c);
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = newmtrx;
    return *this;
}

mtrx &mtrx::operator*=(const mtrx &m)
{
    double **newmtrx = matrix::Mult(this->m, m.getM(), this->r, this->c, m.nrow(), m.ncol());
    for (int i = 0; i < this->r; i++)
    {
        delete[] this->m[i];
    }
    delete[] this->m;
    this->m = newmtrx;
    return *this;
}

mtrx operator+(mtrx m, const double &x)
{
    m += x;
    return m;
}

mtrx operator-(mtrx m, const double &x)
{
    m -= x;
    return m;
}

mtrx operator*(mtrx m, const double &x)
{
    m *= x;
    return m;
}

mtrx operator/(mtrx m, const double &x)
{
    m /= x;
    return m;
}

mtrx operator+(mtrx m1, const mtrx &m2)
{
    m1 += m2;
    return m1;
}

mtrx operator-(mtrx m1, const mtrx &m2)
{
    m1 -= m2;
    return m1;
}

mtrx operator*(mtrx m1, const mtrx &m2)
{
    m1 *= m2;
    return m1;
}

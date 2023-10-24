#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "./vector.hpp"

namespace matrix
{
    double *Row(double **m, int k, int r, int c);
    double *Col(double **m, int k, int r, int c);
    double **Zeros(int r, int c);
    double **Ones(int r, int c);
    double **Full(int r, int c, double x);
    double **Diag(int n, double x);
    double **Copy(double **m, int r, int c);
    void Delete(double **m, int r);

    double Min(double **m, int r, int c);
    double Max(double **m, int r, int c);
    double Mean(double **m, int r, int c);
    double Sum(double **m, int r, int c);
    double Prod(double **m, int r, int c);
    double Det(double **m, int r, int c);

    double **Abs(double **m, int r, int c);
    double **Clip(double **m, double a, double b, int r, int c);
    double **Transpose(double **m, int r, int c);
    double **InverseMatrix(double **m, int r, int c);
    double **LTriangle(double **m, int r, int c);
    double **UTriangle(double **m, int r, int c);
    double ***LU(double **m, int r, int c);

    double **Add(double **m, double x, int r, int c);
    double **Scale(double **m, double x, int r, int c);
    double **Add(double **m1, double **m2, int r, int c);
    double **Sub(double **m1, double **m2, int r, int c);
    double **Mult(double **m1, double **m2, int r1, int c1, int r2, int c2);
}

class mtrx
{
private:
    int r;
    int c;
    double **m;

public:
    mtrx();
    mtrx(double **m, int r, int c);
    mtrx(const mtrx &m);
    ~mtrx();

    int nrow() const;
    int ncol() const;
    double **ptr() const;

    static vct Row(const mtrx &m, int k);
    static vct Col(const mtrx &m, int k);
    static mtrx Zeros(int r, int c);
    static mtrx Ones(int r, int c);
    static mtrx Full(int r, int c, double x);
    static mtrx Diag(int n, double x);
    static mtrx Copy(const mtrx &m);
    static void Delete(mtrx &m);

    static double Min(const mtrx &m);
    static double Max(const mtrx &m);
    static double Mean(const mtrx &m);
    static double Sum(const mtrx &m);
    static double Prod(const mtrx &m);
    static double Det(const mtrx &m);

    static mtrx Abs(const mtrx &m);
    static mtrx Clip(const mtrx &m, double a, double b);
    static mtrx Transpose(const mtrx &m);
    static mtrx InverseMatrix(const mtrx &m);
    static mtrx LTriangle(const mtrx &m);
    static mtrx UTriangle(const mtrx &m);
    static mtrx *LU(const mtrx &m);

    static mtrx Add(const mtrx &m, double x);
    static mtrx Scale(const mtrx &m, double x);

    mtrx &operator=(const mtrx &m);
    double *operator[](int index) const;

    mtrx &operator+=(const double &x);
    mtrx &operator-=(const double &x);
    mtrx &operator*=(const double &x);
    mtrx &operator/=(const double &x);

    mtrx &operator+=(const mtrx &m);
    mtrx &operator-=(const mtrx &m);
    mtrx &operator*=(const mtrx &m);

    friend mtrx operator+(mtrx m1, const double &x);
    friend mtrx operator-(mtrx m1, const double &x);
    friend mtrx operator*(mtrx m1, const double &x);
    friend mtrx operator/(mtrx m1, const double &x);

    friend mtrx operator+(mtrx m1, const mtrx &m2);
    friend mtrx operator-(mtrx m1, const mtrx &m2);
    friend mtrx operator*(mtrx m1, const mtrx &m2);
};

mtrx operator+(mtrx m1, const double &x);
mtrx operator-(mtrx m1, const double &x);
mtrx operator*(mtrx m1, const double &x);
mtrx operator/(mtrx m1, const double &x);

mtrx operator+(mtrx m1, const mtrx &m2);
mtrx operator-(mtrx m1, const mtrx &m2);
mtrx operator*(mtrx m1, const mtrx &m2);

#endif
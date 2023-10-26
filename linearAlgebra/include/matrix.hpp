#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.hpp"

namespace matrix
{
    double *row(double **m, size_t k, size_t r, size_t c);
    double *col(double **m, size_t k, size_t r, size_t c);
    double **zeros(size_t r, size_t c);
    double **ones(size_t r, size_t c);
    double **full(size_t r, size_t c, double x);
    double **diag(size_t n, double x);
    double **random(size_t r, size_t c, double a, double b);
    double **copy(double **m, size_t r, size_t c);
    void Delete(double **m, size_t r);

    double det(double **m, size_t r, size_t c);

    double **reciprocal(double **m, size_t r, size_t c);
    double **transpose(double **m, size_t r, size_t c);
    double **inverse(double **m, size_t r, size_t c); // TODO
    double **LTriangle(double **m, size_t r, size_t c);
    double **UTriangle(double **m, size_t r, size_t c);

    double ***LU(double **m, size_t r, size_t c);

    double **add(double **m, double x, size_t r, size_t c);
    double **sub(double **m, double x, size_t r, size_t c);
    double **mul(double **m, double x, size_t r, size_t c);

    double **add(double **m1, double **m2, size_t r, size_t c);
    double **sub(double **m1, double **m2, size_t r, size_t c);
    double **mul(double **m1, double **m2, size_t r, size_t c);
}

class mtrx
{
private:
    size_t r;
    size_t c;
    double **m;

public:
    mtrx();
    mtrx(double **m, size_t r, size_t c);
    mtrx(const mtrx &m);
    ~mtrx();

    size_t nrow() const;
    size_t ncol() const;
    double **ptr() const;

    vct row(size_t k) const;
    vct col(size_t k) const;
    mtrx copy() const;

    double det() const;

    mtrx reciprocal() const;
    mtrx transpose() const;
    mtrx inverse() const;

    static vct row(const mtrx &m, size_t k);
    static vct col(const mtrx &m, size_t k);
    static mtrx zeros(size_t r, size_t c);
    static mtrx ones(size_t r, size_t c);
    static mtrx full(size_t r, size_t c, double x);
    static mtrx diag(size_t n, double x);
    static mtrx random(size_t r, size_t c, double a, double b);
    static mtrx copy(const mtrx &m);

    static double det(const mtrx &m); // memory issues (fast memory groth)

    static mtrx reciprocal(const mtrx &m);
    static mtrx transpose(const mtrx &m);
    static mtrx inverse(const mtrx &m);   // TODO
    static mtrx LTriangle(const mtrx &m); // memory issues (fast memory groth)
    static mtrx UTriangle(const mtrx &m); // memory issues (fast memory groth)
    static mtrx *LU(const mtrx &m);       // memory issues (fast memory groth)

    double *operator[](size_t index) const;
    mtrx &operator=(const mtrx &m);

    mtrx &operator+=(const double &x);
    mtrx &operator-=(const double &x);
    mtrx &operator*=(const double &x);
    mtrx &operator/=(const double &x);

    mtrx &operator+=(const mtrx &m);
    mtrx &operator-=(const mtrx &m);
    mtrx &operator*=(const mtrx &m);
    mtrx &operator/=(const mtrx &m);

    friend mtrx operator+(const mtrx &m, const double &x);
    friend mtrx operator-(const mtrx &m, const double &x);
    friend mtrx operator*(const mtrx &m, const double &x);
    friend mtrx operator/(const mtrx &m, const double &x);

    friend mtrx operator+(const double &x, const mtrx &m);
    friend mtrx operator-(const double &x, const mtrx &m);
    friend mtrx operator*(const double &x, const mtrx &m);
    friend mtrx operator/(const double &x, const mtrx &m);

    friend mtrx operator+(const mtrx &m1, const mtrx &m2);
    friend mtrx operator-(const mtrx &m1, const mtrx &m2);
    friend mtrx operator*(const mtrx &m1, const mtrx &m2);
    friend mtrx operator/(const mtrx &m1, const mtrx &m2);
};

mtrx operator+(const mtrx &m, const double &x);
mtrx operator-(const mtrx &m, const double &x);
mtrx operator*(const mtrx &m, const double &x);
mtrx operator/(const mtrx &m, const double &x);

mtrx operator+(const double &x, const mtrx &m);
mtrx operator-(const double &x, const mtrx &m);
mtrx operator*(const double &x, const mtrx &m);
mtrx operator/(const double &x, const mtrx &m);

mtrx operator+(const mtrx &m1, const mtrx &m2);
mtrx operator-(const mtrx &m1, const mtrx &m2);
mtrx operator*(const mtrx &m1, const mtrx &m2);
mtrx operator/(const mtrx &m1, const mtrx &m2);

#endif
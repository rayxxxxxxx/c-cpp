#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace vector
{
    double *zeros(size_t n);
    double *ones(size_t n);
    double *full(size_t n, double x);
    double *random(size_t n, double a, double b);
    double *copy(double *v, size_t n);
    double *Delete(double *v);

    double mag(double *v, size_t n);
    double dist(double *v1, double *v2, size_t n);

    double *reciprocal(double *v, size_t n);

    double *add(double *v, double x, size_t n);
    double *sub(double *v, double x, size_t n);
    double *scale(double *v, double x, size_t n);

    double *add(double *v1, double *v2, size_t n);
    double *sub(double *v1, double *v2, size_t n);
    double *scale(double *v1, double *v2, size_t n);
    double *div(double *v1, double *v2, size_t n);
}

class vct
{
private:
    size_t n;
    double *p;

public:
    vct();
    vct(double *v, size_t n);
    vct(const vct &v);
    ~vct();

    size_t size() const;
    double *ptr() const;

    static vct zeros(size_t n);
    static vct ones(size_t n);
    static vct full(size_t n, double x);
    static vct random(size_t n, double a, double b);
    static vct copy(const vct &v);
    static vct Delete(const vct &v);

    static double mag(const vct &v);
    static double dist(const vct &v1, const vct &v2);

    static vct reciprocal(const vct &v);

    vct &operator=(const vct &v);
    double &operator[](size_t idx) const;

    vct &operator+=(const double &x);
    vct &operator-=(const double &x);
    vct &operator*=(const double &x);
    vct &operator/=(const double &x);

    vct &operator+=(const vct &v);
    vct &operator-=(const vct &v);
    vct &operator*=(const vct &v);
    vct &operator/=(const vct &v);

    friend vct operator+(const vct &v, const double &x);
    friend vct operator-(const vct &v, const double &x);
    friend vct operator*(const vct &v, const double &x);
    friend vct operator/(const vct &v, const double &x);

    friend vct operator+(const double &x, const vct &v);
    friend vct operator-(const double &x, const vct &v);
    friend vct operator*(const double &x, const vct &v);
    friend vct operator/(const double &x, const vct &v);

    friend vct operator+(const vct &v1, const vct &v2);
    friend vct operator-(const vct &v1, const vct &v2);
    friend vct operator*(const vct &v1, const vct &v2);
    friend vct operator/(const vct &v1, const vct &v2);
};

vct operator+(const vct &v, const double &x);
vct operator-(const vct &v, const double &x);
vct operator*(const vct &v, const double &x);
vct operator/(const vct &v, const double &x);

vct operator+(const double &x, const vct &v);
vct operator-(const double &x, const vct &v);
vct operator*(const double &x, const vct &v);
vct operator/(const double &x, const vct &v);

vct operator+(const vct &v1, const vct &v2);
vct operator-(const vct &v1, const vct &v2);
vct operator*(const vct &v1, const vct &v2);
vct operator/(const vct &v1, const vct &v2);

#endif
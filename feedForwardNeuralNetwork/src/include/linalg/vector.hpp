#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace vector
{
    double *Zeros(int n);
    double *Ones(int n);
    double *Full(int n, double x);
    double *Random(int n, int a, int b);
    double *Copy(double *v, int n);

    double Len(double *v, int n);
    double Dist(double *v1, double *v2, int n);

    double *Add(double *v, double x, int n);
    double *Scale(double *v, double x, int n);

    double *Add(double *v1, double *v2, int n);
    double *Sub(double *v1, double *v2, int n);
    double *Mult(double *v1, double *v2, int n);
    double *Div(double *v1, double *v2, int n);
}

class vct
{
private:
    int n;
    double *p;

public:
    vct();
    vct(double *v, int n);
    vct(const vct &v);
    ~vct();

    int size() const;
    double *ptr() const;

    static vct Zeros(int n);
    static vct Ones(int n);
    static vct Full(int n, double x);
    static vct Random(int n, int a, int b);
    static vct Copy(const vct &v);

    static double Len(const vct &v);
    static double Dist(const vct &v1, const vct &v2);

    vct &operator=(const vct &v);
    double &operator[](int idx) const;

    vct &operator+=(const double &x);
    vct &operator-=(const double &x);
    vct &operator*=(const double &x);
    vct &operator/=(const double &x);

    vct &operator+=(const vct &v2);
    vct &operator-=(const vct &v2);
    vct &operator*=(const vct &v2);
    vct &operator/=(const vct &v2);

    friend vct operator+(vct v, const double &x);
    friend vct operator-(vct v, const double &x);
    friend vct operator*(vct v, const double &x);
    friend vct operator/(vct v, const double &x);

    friend vct operator+(vct v1, const vct &v2);
    friend vct operator-(vct v1, const vct &v2);
    friend vct operator*(vct v1, const vct &v2);
    friend vct operator/(vct v1, const vct &v2);
};

vct operator+(vct v, const double &x);
vct operator-(vct v, const double &x);
vct operator*(vct v, const double &x);
vct operator/(vct v, const double &x);

vct operator+(vct v1, const vct &v2);
vct operator-(vct v1, const vct &v2);
vct operator*(vct v1, const vct &v2);
vct operator/(vct v1, const vct &v2);

#endif
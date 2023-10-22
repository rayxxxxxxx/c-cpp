#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace vector
{
    double *Zeros(int n);
    double *Ones(int n);
    double *Full(int n, double x);
    double *Copy(double *v, int n);

    double Min(double *v, int n);
    double Max(double *v, int n);
    double Mean(double *v, int n);
    double Sum(double *v, int n);
    double Prod(double *v, int n);
    double Len(double *v, int n);
    double Dist(double *v1, double *v2, int n);
    double Dot(double *v1, double *v2, int n);

    double *Abs(double *v, int n);
    double *Clip(double *v, double a, double b, int n);
    double *Reverse(double *v, int n);
    double *Slice(double *v, int ii, int jj);

    double *Lerp(double *v1, double *v2, double t, int n);
    double *Cross(double *v1, double *v2, int n); // TODO
    double *Conv(double *v1, double *v2, int n1, int n2);

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
    double *getP() const;

    static vct Zeros(int n);
    static vct Ones(int n);
    static vct Full(int n, double x);
    static vct Copy(const vct &v);

    static double Min(const vct &v);
    static double Max(const vct &v);
    static double Mean(const vct &v);
    static double Sum(const vct &v);
    static double Prod(const vct &v);
    static double Len(const vct &v);
    static double Dist(const vct &v1, const vct &v2);
    static double Dot(const vct &v1, const vct &v2);

    static vct Abs(const vct &v);
    static vct Clip(const vct &v, double a, double b);
    static vct Reverse(const vct &v);
    static vct Slice(const vct &v, int ii, int jj);

    static vct Lerp(const vct &v1, const vct &v2, double t);
    static vct Cross(const vct &v1, const vct &v2); // TODO
    static vct Conv(const vct &v1, const vct &v2);

    vct &operator=(const vct &v);
    double &operator[](int idx) const;

    vct &operator+=(const double &x);
    vct &operator-=(const double &x);
    vct &operator*=(const double &x);
    vct &operator/=(const double &x);

    vct &operator+=(const vct &v2);
    vct &operator-=(const vct &v2);

    friend vct operator+(vct v, const double &x);
    friend vct operator-(vct v, const double &x);
    friend vct operator*(vct v, const double &x);
    friend vct operator/(vct v, const double &x);

    friend vct operator+(vct v1, const vct &v2);
    friend vct operator-(vct v1, const vct &v2);
};

vct operator+(vct v, const double &x);
vct operator-(vct v, const double &x);

vct operator+(vct v1, const vct &v2);
vct operator-(vct v1, const vct &v2);

#endif
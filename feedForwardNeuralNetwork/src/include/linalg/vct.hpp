#ifndef VECTOR_HPP
#define VECTOR_HPP

namespace vct
{
    double *Zeros(int n);
    double *Ones(int n);
    double *Full(int n, double x);
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

#endif
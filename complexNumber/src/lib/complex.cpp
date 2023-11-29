#include <stdexcept>
#include <math.h>

#include "complex.hpp"

Complex::Complex()
{
    this->re = 0;
    this->im = 0;
}

Complex::Complex(double real = 0, double imaginary = 0)
{
    this->re = real;
    this->im = imaginary;
}

Complex::Complex(const Complex &other)
{
    this->re = other.re;
    this->im = other.im;
}

Complex::~Complex() {}

double Complex::getRe() const
{
    return this->re;
}

double Complex::getIm() const
{
    return this->im;
}

double Complex::mag() const
{
    return sqrt(this->re * this->re + this->im * this->im);
}

double Complex::arg() const
{
    if (this->re == 0.0 && this->im == 0.0)
    {
        throw std::invalid_argument("both real and imaginary components equal to 0.0");
    }
    if (this->re == 0.0)
    {
        return M_PI_2;
    }
    return atan2(this->im, this->re);
}

Complex Complex::exp(double n)
{
    if (this->re == 0.0 && this->im == 0.0)
    {
        throw std::invalid_argument("both real and imaginary components equal to 0.0");
    }
    double arg = this->arg();
    double mag = this->mag();
    return Complex(powf(mag, n) * cos(n * arg), powf(mag, n) * sin(n * arg));
}

Complex &Complex::operator=(const Complex &other)
{
    this->re = other.re;
    this->im = other.im;
    return *this;
}

double Complex::operator[](size_t i) const
{
    if (i == 0)
    {
        return this->re;
    }
    if (i == 1)
    {
        return this->im;
    }
    throw std::invalid_argument("invalid index. Must be 0 (for real component) or 1 (for imaginary component)");
}

Complex &Complex::operator+=(double x)
{
    this->re += x;
    return *this;
}

Complex &Complex::operator-=(double x)
{
    this->re -= x;
    return *this;
}

Complex &Complex::operator*=(double x)
{
    this->re *= x;
    this->im *= x;
    return *this;
}

Complex &Complex::operator/=(double x)
{
    if (x == 0.0)
    {
        throw std::invalid_argument("division by zero");
    }
    this->re /= x;
    this->im /= x;
    return *this;
}

Complex &Complex::operator+=(const Complex &other)
{
    this->re += other.re;
    this->im += other.im;
    return *this;
}

Complex &Complex::operator-=(const Complex &other)
{
    this->re -= other.re;
    this->im -= other.im;
    return *this;
}

Complex &Complex::operator*=(const Complex &other)
{
    double re = this->re * other.re - this->im * other.im;
    double im = this->re * other.im + other.re * this->im;
    this->re = re;
    this->im = im;
    return *this;
}

Complex &Complex::operator/=(const Complex &other)
{
    if (other.re == 0.0 && other.im == 0.0)
    {
        throw std::invalid_argument("division by zero");
    }
    double denominator = other.re * other.re + other.im * other.im;
    double re = this->re * other.re + this->im * other.im;
    double im = other.re * this->im - this->re * other.im;
    this->re = re / denominator;
    this->im = im / denominator;
    return *this;
}

bool Complex::operator==(const Complex &other)
{
    return this->mag() == other.mag();
}

bool Complex::operator!=(const Complex &other)
{
    return this->mag() != other.mag();
}

bool Complex::operator>(const Complex &other)
{
    return this->mag() > other.mag();
}

bool Complex::operator<(const Complex &other)
{
    return this->mag() < other.mag();
}

bool Complex::operator>=(const Complex &other)
{
    return this->mag() >= other.mag();
}

bool Complex::operator<=(const Complex &other)
{
    return this->mag() <= other.mag();
}

Complex operator+(const Complex &a, const Complex &b)
{
    return Complex(a.getRe() + b.getRe(), a.getIm() + b.getIm());
}

Complex operator-(const Complex &a, const Complex &b)
{
    return Complex(a.getRe() - b.getRe(), a.getIm() - b.getIm());
}

Complex operator*(const Complex &a, const Complex &b)
{
    double re = a.getRe() * b.getRe() - a.getIm() * b.getIm();
    double im = a.getRe() * b.getIm() + b.getRe() * a.getIm();
    return Complex(re, im);
}

Complex operator/(const Complex &a, const Complex &b)
{
    if (b.getRe() == 0.0 && b.getIm() == 0.0)
    {
        throw std::invalid_argument("division by zero");
    }
    double denominator = b.getRe() * b.getRe() + b.getIm() * b.getIm();
    double re = a.getRe() * b.getRe() + a.getIm() * b.getIm();
    double im = b.getRe() * a.getIm() - a.getRe() * b.getIm();
    return Complex(re / denominator, im / denominator);
}

Complex Complex::zero()
{
    return Complex(0, 0);
}

Complex Complex::one()
{
    return Complex(1, 1);
}

Complex Complex::oneRe()
{
    return Complex(1, 0);
}

Complex Complex::oneIm()
{
    return Complex(0, 1);
}

Complex Complex::real(double real)
{
    return Complex(real, 0);
}

Complex Complex::imaginary(double imaginary)
{
    return Complex(0, imaginary);
}

Complex operator+(const Complex &a, double x)
{
    return Complex(a.getRe() + x, a.getIm());
}

Complex operator-(const Complex &a, double x)
{
    return Complex(a.getRe() - x, a.getIm());
}

Complex operator*(const Complex &a, double x)
{
    double re = a.getRe() * x;
    double im = a.getIm() * x;
    return Complex(re, im);
}

Complex operator/(const Complex &a, double x)
{
    if (x == 0.0)
    {
        throw std::invalid_argument("division by zero");
    }
    double re = a.getRe() / x;
    double im = a.getIm() / x;
    return Complex(re, im);
}

Complex operator+(double x, const Complex &a)
{
    return Complex(a.getRe() + x, a.getIm());
}

Complex operator-(double x, const Complex &a)
{
    return Complex(a.getRe() - x, a.getIm());
}

Complex operator*(double x, const Complex &a)
{
    double re = a.getRe() * x;
    double im = a.getIm() * x;
    return Complex(re, im);
}

Complex operator/(double x, const Complex &a)
{
    if (a.getRe() == 0.0 && a.getIm() == 0.0)
    {
        throw std::invalid_argument("division by zero");
    }
    double denominator = a.getRe() * a.getRe() + a.getIm() * a.getIm();
    double re = a.getRe() * x;
    double im = -a.getIm() * x;
    return Complex(re / denominator, im / denominator);
}

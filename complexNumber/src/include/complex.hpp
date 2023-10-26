#ifndef COMPLEX_NUMBER_HPP
#define COMPLEX_NUMBER_HPP

class Complex
{
private:
    double re;
    double im;

public:
    Complex();
    Complex(double real, double imaginary);
    Complex(const Complex &other);
    ~Complex();

    double getRe() const;
    double getIm() const;

    double mag() const;
    double arg() const;

    Complex exp(double n);

    double operator[](int i) const;

    Complex &operator=(const Complex &other);

    Complex &operator+=(double x);
    Complex &operator-=(double x);
    Complex &operator*=(double x);
    Complex &operator/=(double x);

    Complex &operator+=(const Complex &other);
    Complex &operator-=(const Complex &other);
    Complex &operator*=(const Complex &other);
    Complex &operator/=(const Complex &other);

    bool operator==(const Complex &other);
    bool operator!=(const Complex &other);
    bool operator>(const Complex &other);
    bool operator<(const Complex &other);
    bool operator>=(const Complex &other);
    bool operator<=(const Complex &other);

    static Complex zero();
    static Complex one();
    static Complex oneRe();
    static Complex oneIm();
    static Complex real(double real);
    static Complex imaginary(double imaginary);
};

Complex operator+(const Complex &a, double x);
Complex operator-(const Complex &a, double x);
Complex operator*(const Complex &a, double x);
Complex operator/(const Complex &a, double x);

Complex operator+(double x, const Complex &a);
Complex operator-(double x, const Complex &a);
Complex operator*(double x, const Complex &a);
Complex operator/(double x, const Complex &a);

Complex operator+(const Complex &a, const Complex &b);
Complex operator-(const Complex &a, const Complex &b);
Complex operator*(const Complex &a, const Complex &b);
Complex operator/(const Complex &a, const Complex &b);

#endif
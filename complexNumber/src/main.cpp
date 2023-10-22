#include <iostream>

#include "complex.hpp"

void printComplex(const Complex &c)
{
    std::cout << c.getRe() << "+" << c.getIm() << "i" << std::endl;
}

int main(int argc, char **args)
{
    Complex c = Complex(1, 1);
    printComplex(c);

    std::cout << c[0] << std::endl;
    std::cout << c[1] << std::endl;

    try
    {
        std::cout << c[2] << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << c.mag() << std::endl;
    std::cout << c.arg() << std::endl;

    Complex c2 = Complex(c);
    printComplex(c2);
    std::cout << c2.mag() << std::endl;
    std::cout << c2.arg() << std::endl;

    Complex c3 = c;
    printComplex(c3);
    std::cout << c3.mag() << std::endl;
    std::cout << c3.arg() << std::endl;

    printComplex(Complex::zero());
    printComplex(Complex::one());
    printComplex(Complex::oneRe());
    printComplex(Complex::oneIm());
    printComplex(Complex::real(100));
    printComplex(Complex::imaginary(100));

    try
    {
        printComplex(Complex::zero().exp(0));
        printComplex(Complex::zero().exp(1));
        printComplex(Complex::zero().exp(10));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        printComplex(Complex::one().exp(0));
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    printComplex(Complex::one().exp(1));
    printComplex(Complex::one().exp(10));

    printComplex(Complex::one() += 1);
    printComplex(Complex::one() -= 1);
    printComplex(Complex::one() *= 1);
    printComplex(Complex::one() /= 1);

    try
    {
        printComplex(Complex::one() /= 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    printComplex(Complex::one() += Complex::one());
    printComplex(Complex::one() -= Complex::one());
    printComplex(Complex::one() *= Complex::one());
    printComplex(Complex::one() /= Complex::one());

    printComplex(Complex(1, 1) + Complex(1, 1));
    printComplex(Complex(1, 1) - Complex(1, 1));
    printComplex(Complex(1, 1) * Complex(1, 1));
    printComplex(Complex(1, 1) / Complex(1, 1));

    printComplex(Complex(1, 1) + 1);
    printComplex(Complex(1, 1) - 1);
    printComplex(Complex(1, 1) * 1);
    printComplex(Complex(1, 1) / 1);

    try
    {
        printComplex(Complex(1, 1) / 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
#include <math.h>

#include <iostream>
#include <iomanip>

#include <string>

#include "linalg.hpp"

template <typename T>
void println(T data, std::string end = "");

void printVector(const vct &v);
void printMatrix(const mtrx &m);

double fnc(double x);

int main(int argc, char const *argv[])
{
    size_t n = 2;
    size_t m = 3;

    // size_t i = 0;
    // while (true)
    // {
    //     {
    //         vct v0 = vct::zeros(n);
    //         vct v1 = vct::ones(n);
    //         vct v2 = vct::full(n, 2);
    //         vct v3 = vct::full(n, 3);
    //         vct v4 = vct::full(n, -4);

    //         vct v2cp1 = v2.copy();
    //         vct v2cp2 = vct::copy(v2);

    //         v1.mag();
    //         vct::mag(v1);

    //         v2.reciprocal();
    //         vct::reciprocal(v2);

    //         vct::dist(v0, v1);

    //         v2 + 100;
    //         v2 - 100;
    //         v2 * 100;
    //         v2 / 100;

    //         100 + v2;
    //         100 - v2;
    //         100 * v2;
    //         100 / v2;

    //         v2 + v3;
    //         v2 - v3;
    //         v2 *v3;
    //         v2 / v3;

    //         mtrx m0 = mtrx::zeros(n, m);
    //         mtrx m1 = mtrx::ones(n, m);
    //         mtrx m2 = mtrx::full(n, m, 2);
    //         mtrx m3 = mtrx::full(n, m, 3);
    //         mtrx m4 = mtrx::full(n, m, -4);

    //         mtrx m2cp1 = m2.copy();
    //         mtrx m2cp2 = mtrx::copy(m2);

    //         // mtrx::ones(n, n).det(); // fast memoy usage groth
    //         // mtrx::det(mtrx::ones(n, n)); // fast memoy usage groth

    //         m2.reciprocal();
    //         mtrx::reciprocal(m2);

    //         m2.transpose();
    //         mtrx::transpose(m2);

    //         m2 + 100;
    //         m2 - 100;
    //         m2 * 100;
    //         m2 / 100;

    //         100 + m2;
    //         100 - m2;
    //         100 * m2;
    //         100 / m2;

    //         m2 + m3;
    //         m2 - m3;
    //         m2 *m3;
    //         m2 / m3;

    //         linalg::min(v2);
    //         linalg::max(v2);
    //         linalg::mean(v2);
    //         linalg::sum(v2);
    //         linalg::prod(v2);

    //         linalg::abs(v4);
    //         linalg::clip(v4, -1.0, 0.0);
    //         linalg::lerp(v1, v2, 0.7);

    //         linalg::square(v2);
    //         linalg::pow(v2, 3);
    //         linalg::sqrt(v2);
    //         linalg::exp(v2);
    //         linalg::map(fnc, v2);

    //         linalg::min(m2);
    //         linalg::max(m2);
    //         linalg::mean(m2);
    //         linalg::sum(m2);
    //         linalg::prod(m2);

    //         linalg::abs(m4);
    //         linalg::clip(m2, -1.0, 0.0);
    //         linalg::lerp(m1, m2, 0.7);

    //         linalg::square(m2);
    //         linalg::pow(m2, 3);
    //         linalg::sqrt(m2);
    //         linalg::exp(m2);
    //         linalg::map(fnc, m2);
    //         linalg::mapRow(fnc, m2);
    //         linalg::mapCol(fnc, m2);

    //         linalg::dot(v1, v2);
    //         linalg::dot(v1, m1);
    //         linalg::dot(m1.transpose(), v1);
    //         linalg::mul(v1, v2);
    //         linalg::mul(m1, m2.transpose());

    //         std::cout << i << std::endl;
    //         i++;
    //     }
    // }

    vct v0 = vct::zeros(m);
    vct v1 = vct::ones(m);
    vct v2 = vct::full(m, 2);
    vct v3 = vct::full(m, 3);
    vct v4 = vct::full(m, -4);

    printVector(v0);
    printVector(v1);
    printVector(v2);
    printVector(v3);
    printVector(v4);

    println(v4[0]);

    vct v2cp1 = v2.copy();
    vct v2cp2 = vct::copy(v2);

    printVector(v2cp1);
    printVector(v2cp2);

    std::cout << v1.mag() << std::endl;
    std::cout << vct::mag(v1) << std::endl;

    printVector(v2.reciprocal());
    printVector(vct::reciprocal(v2));

    std::cout << vct::dist(v0, v1) << std::endl;

    printVector(v2 + 100);
    printVector(v2 - 100);
    printVector(v2 * 100);
    printVector(v2 / 100);

    printVector(100 + v2);
    printVector(100 - v2);
    printVector(100 * v2);
    printVector(100 / v2);

    printVector(v2 + v3);
    printVector(v2 - v3);
    printVector(v2 * v3);
    printVector(v2 / v3);

    std::cout << "==============================================" << std::endl;

    mtrx m0 = mtrx::zeros(n, m);
    mtrx m1 = mtrx::ones(n, m);
    mtrx m2 = mtrx::full(n, m, 2);
    mtrx m3 = mtrx::full(n, m, 3);
    mtrx m4 = mtrx::full(n, m, -4);

    printMatrix(m0);
    printMatrix(m1);
    printMatrix(m2);
    printMatrix(m3);
    printMatrix(m4);

    println(m4[0][0]);

    mtrx m2cp1 = m2.copy();
    mtrx m2cp2 = mtrx::copy(m2);

    printMatrix(m2cp1);
    printMatrix(m2cp2);

    println(m2.det());
    println(mtrx::det(m2));

    printMatrix(m2.reciprocal());
    printMatrix(mtrx::reciprocal(m2));

    printMatrix(m2.transpose());
    printMatrix(mtrx::transpose(m2));

    printMatrix(m2 + 100);
    printMatrix(m2 - 100);
    printMatrix(m2 * 100);
    printMatrix(m2 / 100);

    printMatrix(100 + m2);
    printMatrix(100 - m2);
    printMatrix(100 * m2);
    printMatrix(100 / m2);

    printMatrix(m2 + m3);
    printMatrix(m2 - m3);
    printMatrix(m2 * m3);
    printMatrix(m2 / m3);

    std::cout << "==============================================" << std::endl;

    println(linalg::min(v2));
    println(linalg::max(v2));
    println(linalg::mean(v2));
    println(linalg::sum(v2));
    println(linalg::prod(v2));

    printVector(linalg::abs(v4));
    printVector(linalg::clip(v4, -1.0, 0.0));
    printVector(linalg::lerp(v1, v2, 0.7));

    printVector(linalg::square(v2));
    printVector(linalg::pow(v2, 3));
    printVector(linalg::sqrt(v2));
    printVector(linalg::exp(v2));
    printVector(linalg::sin(v2));
    printVector(linalg::cos(v2));
    printVector(linalg::tan(v2));
    printVector(linalg::sinh(v2));
    printVector(linalg::cosh(v2));
    printVector(linalg::tanh(v2));
    printVector(linalg::map(fnc, v2));

    std::cout << "==============================================" << std::endl;

    println(linalg::min(m2));
    println(linalg::max(m2));
    println(linalg::mean(m2));
    println(linalg::sum(m2));
    println(linalg::prod(m2));

    printMatrix(linalg::abs(m4));
    printMatrix(linalg::clip(m2, -1.0, 0.0));
    printMatrix(linalg::lerp(m1, m2, 0.7));

    printMatrix(linalg::square(m2));
    printMatrix(linalg::pow(m2, 3));
    printMatrix(linalg::sqrt(m2));
    printMatrix(linalg::exp(m2));
    printMatrix(linalg::sin(m2));
    printMatrix(linalg::cos(m2));
    printMatrix(linalg::tan(m2));
    printMatrix(linalg::sinh(m2));
    printMatrix(linalg::cosh(m2));
    printMatrix(linalg::tanh(m2));
    printMatrix(linalg::map(fnc, m2));
    printMatrix(linalg::mapRow(fnc, m2));
    printMatrix(linalg::mapCol(fnc, m2));

    std::cout << "==============================================" << std::endl;

    println(linalg::dot(v1, v2));
    printVector(linalg::dot(m1, v1));
    printVector(linalg::dot(v1, m1.transpose()));
    printMatrix(linalg::mul(v1, v2));
    printMatrix(linalg::mul(m1, m2.transpose()));

    return 0;
}

template <typename T>
void println(T data, std::string end)
{
    std::cout << data << end << std::endl;
}

void printVector(const vct &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void printMatrix(const mtrx &m)
{
    for (int i = 0; i < m.nrow(); i++)
    {
        for (int j = 0; j < m.ncol(); j++)
        {
            std::cout << std::setprecision(3) << std::setw(5) << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

double fnc(double x)
{
    return 100 * x + 1;
}

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

#include "fnn.hpp"
#include "linalg/vct.hpp"
#include "linalg/mtrx.hpp"
#include "linalg/linalg.hpp"

void print(std::string str);
void println(std::string str);
void printVector(double *v, int n);
void printMatrix(double **m, int r, int c);

int main(int argc, char const *argv[])
{
    size_t nIn = 3;
    size_t nOut = 2;

    FNN model = FNN(nIn, nOut);

    double *res = model.predict(vct::Ones(nIn));

    printVector(res, nOut);

    std::cout << model.getError(vct::Ones(nIn), vct::Full(nIn, 1)) << std::endl;

    return 0;
}

void print(std::string str)
{
    std::cout << str;
}

void println(std::string str)
{
    std::cout << str << std::endl;
}

void printVector(double *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void printMatrix(double **m, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << std::setprecision(3) << std::setw(5) << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

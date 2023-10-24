#include <stdlib.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <limits>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "linalg/vct.hpp"
#include "linalg/mtrx.hpp"
#include "linalg/linalg.hpp"
#include "fnn/fnn.hpp"
#include "fnn/dataset.hpp"

void print(std::string str);
void println(std::string str);
void printVector(double *v, int n);
void printMatrix(double **m, int r, int c);

std::vector<std::string> split(std::string str, std::string delimeter);

void readIrisData(double **outDataX, double **outDataY);

int main(int argc, char const *argv[])
{
    size_t nIn = 4;
    size_t nOut = 1;
    size_t dataSize = 150;
    double testPercentage = 0.2;
    size_t testSize = (size_t)(testPercentage * dataSize);
    size_t trainSize = dataSize - testSize;

    double **xData = new double *[dataSize];
    double **yData = new double *[dataSize];

    double **xTrain = new double *[trainSize];
    double **yTrain = new double *[trainSize];

    double **xTest = new double *[testSize];
    double **yTest = new double *[testSize];

    dataset::loadCsv("../data/iris_mapped.csv", xData, yData, dataSize, nIn, nOut);
    dataset::shuffle(xData, yData, dataSize);
    dataset::divide(xData, yData, xTrain, yTrain, xTest, yTest, testPercentage, dataSize);

    FNN model = FNN(nIn, nOut);
    model.train(xTrain, yTrain, xTest, yTest, dataSize, testSize, 0.01, 0.01);
    std::cout << model.getError(xTest, yTest, testSize) << std::endl;

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

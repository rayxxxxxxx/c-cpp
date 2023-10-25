#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "fnn/fnn.hpp"
#include "fnn/dataset.hpp"

void print(std::string str);
void println(std::string str);
void printVector(const vct &v);
void printMatrix(const mtrx &m);

int main(int argc, char const *argv[])
{
    size_t nIn = 4;
    size_t nOut = 1;
    size_t dataSize = 150;
    double testPercentage = 0.3;
    size_t testSize = (size_t)(testPercentage * dataSize);
    size_t trainSize = dataSize - testSize;

    vct *xData = new vct[dataSize];
    vct *yData = new vct[dataSize];

    vct *xTrain = new vct[trainSize];
    vct *yTrain = new vct[trainSize];

    vct *xTest = new vct[testSize];
    vct *yTest = new vct[testSize];

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

void printVector(const vct &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

void printMatrix(const mtrx &m)
{
    for (size_t i = 0; i < m.nrow(); i++)
    {
        for (size_t j = 0; j < m.ncol(); j++)
        {
            std::cout << std::setprecision(3) << std::setw(5) << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

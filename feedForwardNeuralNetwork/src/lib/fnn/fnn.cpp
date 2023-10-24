#include <iostream>
#include <math.h>

#include "linalg/linalg.hpp"
#include "fnn/fnn.hpp"
#include "fnn/dataset.hpp"

double
F(double x)
{
    return 1.0 / (1 + exp(-x));
}

double dF(double x)
{
    return F(x) * (1 - F(x));
}

FNN::FNN(size_t inputSize, size_t outputSize)
{
    this->nIn = inputSize;
    this->nOut = outputSize;
    this->w = mtrx::Random(outputSize, inputSize, -1, 2);
    this->b = vct::Zeros(outputSize);
}

vct FNN::predict(vct x) const
{
    return linalg::Apply(F, linalg::Dot(w, x));
}

void FNN::train(vct *xTrain, vct *yTrain, vct *xTest, vct *yTest, size_t size, size_t testSize, double learningRate, double err)
{
    size_t trainSize = size - testSize;
    double currErr = this->getError(xTest, yTest, testSize);
    size_t j = 0;
    while (currErr > err)
    {
        mtrx grads = mtrx::Zeros(nOut, nIn);
        for (size_t i = 0; i < trainSize; i++)
        {
            vct a = linalg::Dot(w, xTrain[i]);
            vct y = linalg::Apply(F, a);
            vct deltaY = yTrain[i] - y;
            vct dFa = linalg::Apply(dF, a);

            grads += linalg::Mult(deltaY * dFa, xTrain[i]) * (-learningRate);
        }
        w -= grads;
        grads *= 0;

        dataset::shuffle(xTrain, yTrain, trainSize);
        currErr = this->getError(xTest, yTest, testSize);
        std::cout << currErr << " " << j << std::endl;
        j++;
    }
}

void FNN::backPropagation(vct xTest, vct yTest) {}

double FNN::getError(vct xTest, vct yTest)
{
    vct y = this->predict(xTest);
    return linalg::Sum(linalg::Square(yTest - y)) / nOut;
}

double FNN::getError(vct *xTest, vct *yTest, size_t size)
{
    double err = 0.0;
    for (size_t i = 0; i < size; i++)
    {
        err += this->getError(xTest[i], yTest[i]);
    }
    return err / size;
}

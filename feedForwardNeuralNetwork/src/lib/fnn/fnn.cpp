#include <iostream>
#include <math.h>

#include "linalg/linalg.hpp"
#include "fnn/fnn.hpp"
#include "fnn/dataset.hpp"

namespace la = linalg;

double F(double x)
{
    return 1.0 / (1.0 + std::exp(-x));
}

double dF(double x)
{
    return F(x) * (1.0 - F(x));
}

FNN::FNN(size_t inputSize, size_t outputSize)
{
    this->nIn = inputSize;
    this->nOut = outputSize;
    this->w = mtrx::random(outputSize, inputSize, -1.0, 1.0);
    this->b = vct::zeros(outputSize);
}

mtrx &FNN::getW()
{
    return this->w;
}

vct &FNN::getB()
{
    return this->b;
}

vct FNN::predict(vct x) const
{
    return la::map(F, la::dot(w, x) + b);
}

double FNN::getError(vct xTest, vct yTest)
{
    vct y = this->predict(xTest);
    return la::sum(la::square(yTest - y)) / nOut;
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

void FNN::backPropagation(vct xTrain, vct yTrain, mtrx &wgrads, vct &bgrads, double lr)
{
    vct a = la::dot(w, xTrain);
    vct y = la::map(F, a);
    vct deltaY = yTrain - y;
    vct dFa = la::map(dF, a);
    wgrads -= lr * la::mul(deltaY * dFa, xTrain);
    bgrads -= lr * deltaY * dFa;
}

void FNN::train(vct *xTrain, vct *yTrain, vct *xTest, vct *yTest, size_t size, size_t testSize, double lr, double err)
{
    long int j = 0;
    size_t trainSize = size - testSize;
    double currErr = this->getError(xTest, yTest, testSize);

    mtrx wgrads = mtrx::zeros(nOut, nIn);
    vct bgrads = vct::zeros(nOut);
    while (currErr > err)
    {
        for (size_t i = 0; i < trainSize; i++)
        {
            this->backPropagation(xTrain[i], yTrain[i], wgrads, bgrads, lr);
        }

        w -= wgrads;
        wgrads *= 0;
        bgrads *= 0;

        dataset::shuffle(xTrain, yTrain, trainSize);
        currErr = this->getError(xTest, yTest, testSize);

        std::cout << "epoch: " << j << ", "
                  << "MSE: " << currErr << std::endl;
        j++;
    }
}

#include <iostream>
#include <math.h>

#include "linalg/vct.hpp"
#include "linalg/mtrx.hpp"
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

double *FNN::predict(double *x) const
{
    return linalg::Apply(F, vct::Add(linalg::Dot(w, x, nOut, nIn), b, nOut), nOut);
}

void FNN::train(double **xTrain, double **yTrain, double **xTest, double **yTest, size_t size, size_t testSize, double learningRate = 1e-2, double err = 1e-2)
{
    size_t trainSize = size - testSize;
    double currErr = this->getError(xTest, yTest, testSize);
    size_t j = 0;
    while (currErr > err)
    {
        double **grads = mtrx::Zeros(nOut, nIn);
        for (size_t i = 0; i < trainSize; i++)
        {
            double *a = linalg::Dot(w, xTrain[i], nOut, nIn);
            double *y = linalg::Apply(F, a, nOut);
            double *deltaY = vct::Sub(yTrain[i], y, nOut);
            double *dFa = linalg::Apply(dF, a, nOut);

            double **tmpGrads = grads;
            grads = mtrx::Add(grads, mtrx::Scale(linalg::Mult(vct::Mult(deltaY, dFa, nOut), xTrain[i], nOut, nIn), -learningRate, nOut, nIn), nOut, nIn);
            mtrx::Delete(tmpGrads, nOut, nIn);

            delete[] a;
            delete[] y;
            delete[] deltaY;
            delete[] dFa;
        }
        double **tmpw = w;
        w = mtrx::Sub(w, grads, nOut, nIn);
        mtrx::Delete(tmpw, nOut, nIn);

        mtrx::Delete(grads, nOut, nIn);

        dataset::shuffle(xTrain, yTrain, trainSize);
        currErr = this->getError(xTest, yTest, testSize);
        std::cout << currErr << " " << j << std::endl;
        j++;
    }
}

void FNN::backPropagation(double *xTest, double *yTest) {}

double FNN::getError(double *xTest, double *yTest)
{
    double *y = this->predict(xTest);
    return linalg::Sum(linalg::Square(vct::Sub(yTest, y, nOut), nOut), nOut) / nOut;
}

double FNN::getError(double **xTest, double **yTest, size_t size)
{
    double err = 0.0;
    double *y = nullptr;
    for (size_t i = 0; i < size; i++)
    {
        y = this->predict(xTest[i]);
        err += linalg::Sum(linalg::Square(vct::Sub(yTest[i], y, nOut), nOut), nOut) / nOut;
    }
    return err / size;
}

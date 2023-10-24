#include <math.h>

#include "linalg/vct.hpp"
#include "linalg/mtrx.hpp"
#include "linalg/linalg.hpp"
#include "fnn/fnn.hpp"

double
F(double x)
{
    return 1.0 / (1 + exp(-x));
}

double dF(double x)
{
}

FNN::FNN(int inputSize, int outputSize)
{
    this->nIn = inputSize;
    this->nOut = outputSize;

    this->w = mtrx::Ones(outputSize, inputSize);
    this->b = vct::Zeros(outputSize);
}

double *FNN::predict(double *x) const
{
    return linalg::Apply(F, vct::Add(linalg::Dot(w, x, nOut, nIn), b, nOut), nOut);
}

void FNN::train(double **xTrain, double **yTrain, double **xTest, double **yTest, int batchesNum = 1, double learningRate = 1e-1, double err = 1e-2) {}

void FNN::backPropagation(double *xTest, double *yTest) {}

double FNN::getError(double *xTest, double *yTest)
{
    double *y = this->predict(xTest);
    return linalg::Sum(linalg::Square(vct::Sub(yTest, y, nOut), nOut), nOut) / nOut;
}

#ifndef FNN_HPP
#define FNN_HPP

#include "linalg/linalg.hpp"

double F(double x);
double dF(double x);

class FNN
{
private:
    size_t nIn;
    size_t nOut;

    mtrx w;
    vct b;

    void backPropagation(vct xTest, vct yTest, mtrx &grads, double lr);

public:
    FNN(size_t inputSize, size_t outputSize);

    vct predict(vct x) const;
    void train(vct *xTrain, vct *yTrain, vct *xTest, vct *yTest, size_t size, size_t testSize, double lr = 1e-2, double err = 1e-2);
    double getError(vct xTest, vct yTest);
    double getError(vct *xTest, vct *yTest, size_t size);
};

#endif
#ifndef FNN_HPP
#define FNN_HPP

double F(double x);
double dF(double x);

class FNN
{
private:
    size_t nIn;
    size_t nOut;

    double **w;
    double *b;

    void backPropagation(double *xTest, double *yTest);

public:
    FNN(size_t inputSize, size_t outputSize);

    double *predict(double *x) const;
    void train(double **xTrain, double **yTrain, double **xTest, double **yTest, size_t size, size_t testSize, double learningRate, double err);
    double getError(double *xTest, double *yTest);
    double getError(double **xTest, double **yTest, size_t size);
};

#endif
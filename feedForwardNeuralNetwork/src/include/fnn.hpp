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
    FNN(int inputSize, int outputSize);

    double *predict(double *x) const;
    void train(double **xTrain, double **yTrain, double **xTest, double **yTest, int batchesNum, double learningRate, double err);
    double getError(double *xTest, double *yTest);
};

#endif
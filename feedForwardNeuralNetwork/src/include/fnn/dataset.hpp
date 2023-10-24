#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>

namespace dataset
{
    void loadCsv(std::string filePath, double **outX, double **outY, size_t size, size_t nIn, size_t nOut, int skip = 0);
    void divide(double **x, double **y, double **trX, double **trY, double **tsX, double **tsY, double frac, size_t size);
    void shuffle(double **outX, double **outY, size_t size);
};

#endif
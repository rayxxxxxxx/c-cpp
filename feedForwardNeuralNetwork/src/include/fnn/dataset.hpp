#ifndef DATASET_HPP
#define DATASET_HPP

#include <string>
#include "linalg/linalg.hpp"

namespace dataset
{
    void loadCsv(std::string filePath, vct *outX, vct *outY, size_t size, size_t nIn, size_t nOut, size_t skip = 0);
    void divide(vct *x, vct *y, vct *trX, vct *trY, vct *tsX, vct *tsY, double frac, size_t size);
    void shuffle(vct *outX, vct *outY, size_t size);
};

#endif
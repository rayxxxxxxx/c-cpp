#include <stdlib.h>
#include <time.h>
#include <limits>
#include <string>
#include <vector>
#include <fstream>

#include "fnn/dataset.hpp"
#include "linalg/linalg.hpp"

std::vector<std::string> splitStr(std::string str, std::string delimeter)
{
    std::vector<std::string> result;
    size_t i = str.find(delimeter);
    while (i != std::string::npos)
    {
        result.push_back(str.substr(0, i));
        str.erase(0, i + 1);
        i = str.find(delimeter);
    }
    result.push_back(str);
    return result;
}

void dataset::loadCsv(std::string filePath, vct *outX, vct *outY, size_t size, size_t nIn, size_t nOut, size_t skip)
{
    std::string fp = std::string(filePath);
    std::ifstream file = std::ifstream();

    std::string line;
    std::vector<std::string> splitted;

    constexpr auto MAX_SIZE = std::numeric_limits<std::streamsize>::max();
    for (size_t i = 0; i < skip; i++)
    {
        file.ignore(MAX_SIZE, '\n');
    }

    size_t i = 0;
    file.open(fp);
    while (!file.eof())
    {
        std::getline(file, line);
        splitted = splitStr(line, ",");

        outX[i] = vct::zeros(nIn);
        for (size_t j = 0; j < nIn; j++)
        {
            outX[i][j] = std::atof(&splitted[j][0]);
        }

        outY[i] = vct::zeros(nOut);
        for (size_t j = 0; j < nOut; j++)
        {
            outY[i][j] = std::atof(&splitted[nIn + j][0]);
        }

        i++;
    }
    file.close();
}

void dataset::divide(vct *x, vct *y, vct *trX, vct *trY, vct *tsX, vct *tsY, double frac, size_t size)
{
    size_t testSize = (size_t)(frac * size);
    size_t trainSize = size - testSize;

    for (size_t i = 0; i < trainSize; i++)
    {
        trX[i] = x[i];
        trY[i] = y[i];
    }

    size_t j = 0;
    for (size_t i = trainSize; i < size; i++)
    {
        tsX[j] = x[i];
        tsY[j] = y[i];
        j++;
    }
}

void dataset::shuffle(vct *outX, vct *outY, size_t size)
{
    std::srand(static_cast<unsigned>(time(0)));
    for (size_t i = 0; i < 2 * size; i++)
    {
        size_t j = (unsigned int)rand() % size;
        size_t k = (unsigned int)rand() % size;

        vct tmp = outX[j];
        outX[j] = outX[k];
        outX[k] = tmp;

        tmp = outY[j];
        outY[j] = outY[k];
        outY[k] = tmp;
    }
}

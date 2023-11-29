#ifndef CSV_READER_H
#define CSV_READER_H

#include <string>
#include <array>
#include <vector>
#include <fstream>

#include <stdlib.h>

using std::pair;
using std::size_t;
using std::string;
using std::vector;

namespace csv
{
    pair<size_t, size_t> dataSize(string fp);
    vector<vector<string>> read(string fp);
};

#endif
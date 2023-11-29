
#include "csvReader.hpp"
#include "stringUtils.hpp"

#include <iostream>

using std::ifstream;
using std::pair;
using std::size_t;
using std::string;
using std::vector;

pair<size_t, size_t> csv::dataSize(string fp)
{
    size_t nrows = 0, ncols = 0;
    string line = "";
    ifstream file;

    file.open(fp);

    std::getline(file, line);
    ncols = string_utils::split(line, ',').size();

    file.clear();
    file.seekg(0);

    while (std::getline(file, line))
    {
        nrows++;
    }

    file.close();

    return pair<size_t, size_t>(nrows, ncols);
}

vector<vector<string>> csv::read(string fp)
{
    string line = "";
    ifstream file;
    vector<vector<string>> data;

    file.open(fp);

    while (std::getline(file, line))
    {
        data.push_back(string_utils::split(line, ','));
    }

    file.close();

    return data;
}
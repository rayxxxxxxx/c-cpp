#include <iostream>

#include "csvReader.hpp"

using std::pair;
using std::string;
using std::vector;

int main(int argc, char *argv[])
{
    string fp = "/home/rayxxx/Data/Development/CPP/libs/csvReader/data/iris_csv.csv";
    pair<size_t, size_t> dsize = csv::dataSize(fp);
    vector<vector<string>> data = csv::read(fp);

    std::cout << dsize.first << "\t" << dsize.second << '\n';

    for (const vector<string> line : data)
    {
        for (const string word : line)
        {
            std::cout << word << " ";
        }

        std::cout << "\n";
    }

    return 0;
}
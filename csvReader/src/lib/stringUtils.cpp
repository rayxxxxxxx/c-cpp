#include "stringUtils.hpp"

using std::size_t;
using std::string;
using std::vector;

vector<string> string_utils::split(string str, char delimeter)
{
    size_t i = 0, j = 0;
    vector<string> splitted;

    for (i; i < str.size(); i++)
    {
        if (str[i] == delimeter)
        {
            splitted.push_back(str.substr(j, i - j));
            j = i + 1;
        }
    }

    splitted.push_back(str.substr(j, i - j));

    return splitted;
}

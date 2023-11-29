#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <vector>

#include <stdlib.h>

using std::size_t;
using std::string;
using std::vector;

namespace string_utils
{
    vector<string> split(string str, char delimeter);
};

#endif
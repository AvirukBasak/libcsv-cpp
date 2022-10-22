#pragma once

#include <string>
#include <vector>

namespace csv
{
    typedef std::string Exception;
    const Exception TypeMismatchException;
    csv::data loadFile(const std::string &path);
}

#pragma once

#include <string>
#include <vector>

#include "data.hpp"

namespace csv
{
    /**
     * Tokenizes a line into a row.
     * @param std::string
     * @return std::vector<std::string>
     */
    std::vector<std::string> tokenizeLine(const std::string &line);

    /**
     * Loads a file and returns it as csv::data.
     * @param std::string Path to file
     * @return csv::data
     */
    data loadFile(const std::string &path);
}

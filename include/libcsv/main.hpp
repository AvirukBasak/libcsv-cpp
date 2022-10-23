#pragma once

#include <string>
#include <vector>

#include "value.hpp"
#include "row.hpp"
#include "data.hpp"
#include "exceptions.hpp"

namespace csv
{
    /**
     * Loads a file and returns it as csv::data.
     * @param std::string Path to file
     * @return csv::data
     */
    data loadFile(const std::string &path);
}

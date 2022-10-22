#pragma once

#include <string>
#include <vector>

#include "value.hpp"
#include "row.hpp"
#include "data.hpp"
#include "exceptions.hpp"

namespace csv
{
    data loadFile(const std::string &path);
}

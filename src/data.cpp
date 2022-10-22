#include <string>
#include <vector>

#include "libcsv/data.hpp"

data(const data &d)
    : m_

int csv::data::countRows()
{
    return m_rows;
}

int csv::data::countCols()
{
    return m_cols;
}

csv::row row()
{}

std::vector<csv::row> rows()
{}

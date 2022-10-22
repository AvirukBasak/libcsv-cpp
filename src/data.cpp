#include <string>
#include <vector>

#include "libcsv/data.hpp"

csv::data::data(const csv::data &d)
{}

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

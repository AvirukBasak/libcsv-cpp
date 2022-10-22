#include <string>
#include <vector>
#include <functional>

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

std::vector<std::string> csv::data::getColumns()
{}

csv::row csv::data::row(int rownum)
{}

std::vector<csv::row> csv::data::rows(const std::function<void (csv::row row)> &f)
{}

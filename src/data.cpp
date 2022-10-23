#include <string>
#include <vector>
#include <functional>

#include "libcsv/data.hpp"

csv::data::data(const std::vector<std::string> &colnames)
    : m_rowc(0), m_colc(colnames.size()), m_colnames(colnames)
{}

csv::data::data(const csv::data &d)
    : m_rowc(d.m_rowc), m_colc(d.m_colc), m_colnames(d.m_colnames), m_rows(d.m_rows)
{}

csv::data::~data()
{
    m_colnames.clear();
    m_rows.clear();
}

int csv::data::rows()
{
    return m_rowc;
}

int csv::data::columns()
{
    return m_colc;
}

std::vector<std::string> csv::data::getColumnNames()
{
    return m_colnames;
}

csv::row csv::data::getRow(int rownum)
{
    if (rownum < 0 || rownum >= m_rowc)
        throw csv::IndexOutOfBoundsException("for index " + std::to_string(rownum));
    return m_rows[rownum];
}

csv::row &csv::data::operator[](int rownum)
{
    if (rownum < 0 || rownum >= m_rowc)
        throw csv::IndexOutOfBoundsException("for index " + std::to_string(rownum));
    return m_rows[rownum];
}

std::vector<csv::row> csv::data::getRows(const std::function<bool (csv::row row)> &condition)
{
    std::vector<csv::row> vec_rows;
    for (const csv::row &row : m_rows)
        if (condition(row)) vec_rows.push_back(row);
    return vec_rows;
}

void csv::data::appendRow(const std::vector<std::string> &row)
{
    if (row.size() != m_colc)
        throw csv::ColumnSizeMismatchException("for row parameter with size " + std::to_string(row.size()));
    m_rows.push_back(csv::row(&m_colnames, row));
    m_rowc++;
}

#include <string>
#include <vector>
#include <functional>

#include "libcsv/exceptions.hpp"
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

csv::row csv::data::getRow(int index)
{
    return csv::data::operator[](index);
}

csv::row &csv::data::operator[](int index)
{
    if (index < 0 || index >= m_rowc)
        csv::throwException<csv::IndexOutOfBoundsException>("for row index " + std::to_string(index));
    return m_rows[index];
}

csv::row csv::data::getRow(const std::string &uid)
{
    return csv::data::operator[](uid);
}

csv::row csv::data::operator[](const std::string &uid)
{
    for (csv::row &row : m_rows)
        if (row.m_row[0].toString() == uid) return row;
    csv::throwException<csv::ValueNotFoundException>("for row uid \"" + uid + "\"");
    return csv::row();
}

std::vector<csv::row> csv::data::getRows(const std::function<bool (const csv::row &row)> &condition)
{
    std::vector<csv::row> vec_rows;
    for (const csv::row &row : m_rows)
        if (condition(row)) vec_rows.push_back(row);
    return vec_rows;
}

void csv::data::appendRow(const std::vector<std::string> &row)
{
    if (row.size() != m_colc)
        csv::throwException<csv::ColumnSizeMismatchException>("for row with size " + std::to_string(row.size()));
    m_rows.push_back(csv::row(&m_colnames, row));
    m_rowc++;
}

#include <string>
#include <vector>

#include "libcsv/exceptions.hpp"
#include "libcsv/row.hpp"

csv::row::row()
    : m_colnames(nullptr), m_row(std::vector<csv::value>())
{}

csv::row::row(const csv::row &r)
    : m_colnames(r.m_colnames), m_row(r.m_row)
{}

csv::row::row(const std::vector<std::string> *colnames, const std::vector<std::string> &r)
    : m_colnames(colnames)
{
    if ((*m_colnames).size() != r.size())
        csv::throwException<csv::ColumnSizeMismatchException>("for row parameter with size " + std::to_string(r.size()));
    for (auto &str : r)
        m_row.push_back(csv::value(str));
}

int csv::row::length()
{
    return m_row.size();
}

csv::value csv::row::column(const std::string &colname)
{
    return csv::row::operator[](colname);
}

csv::value &csv::row::operator[](const std::string &colname)
{
    int i = 0;
    for (const std::string &cn : *m_colnames)
        if (cn == colname)
            return m_row[i];
        else i++;
    csv::throwException<csv::ValueNotFoundException>("for column name \"" + colname + "\"");
    return csv::garbage_val;
}

csv::value csv::row::column(int index)
{
    return csv::row::operator[](index);
}

csv::value &csv::row::operator[](int index)
{
    if (index < 0 || index >= m_row.size())
        csv::throwException<csv::IndexOutOfBoundsException>("for column index " + std::to_string(index));
    return m_row[index];
}

csv::row::~row()
{
    m_row.clear();
}

#include <string>
#include <vector>

#include "libcsv/exceptions.hpp"
#include "libcsv/row.hpp"

csv::row::row(const csv::row &r)
    : m_colnames(r.m_colnames), m_row(r.m_row)
{}

csv::row::row(const std::vector<std::string> *colnames, const std::vector<std::string> &r)
    : m_colnames(colnames)
{
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

csv::row::~row()
{
    m_row.clear();
}

#include <string>
#include <vector>

#include "libcsv/row.hpp"

csv::row::row(const csv::row &r)
    : m_colnames(r.m_colnames), m_row(r.m_row)
{}

csv::row::row(const std::vector<std::string> *colnames, const std::vector<csv::value> &r)
    : m_colnames(colnames), m_row(r)
{}

int csv::row::length()
{
    return m_row.size();
}

csv::value csv::row::column(const std::string &colname)
{
    int i = 0;
    for (const std::string &cn : *m_colnames)
        if (cn == colname)
            return m_row[i];
        else i++;
    return "NULL";
}

csv::row::~row()
{
    m_row.clear();
}

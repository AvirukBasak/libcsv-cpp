#include <string>
#include <vector>

#include "libcsv/row.hpp"

csv::row::row(const csv::row &r)
    : m_colnames(r.m_colnames), m_row(r.m_row)
{}

csv::row::row(const std::vector<std::string> &colnames, const std::vector<csv::value> &row)
    : m_colnames(colnames), m_row(row)
{}

csv::value csv::row::column(const std::string &colname)
{
    int i = 0;
    for (const std::string &cn : m_colnames)
        if (cn == colname)
            return m_row[i];
        else i++;
}

csv::row::~row()
{
    m_colnames.clear();
    m_row.clear();
}

#pragma once

#include <string>
#include <vector>

namespace csv
{
    class row
    {
    public:
        row(const csv::row &r);
        row(const std::vector<std::string> &colnames, const std::vector<csv::value> &row);
        csv::value column(const std::string &colname);
        ~row();
    private:
        friend class csv::data;
        friend class csv::row;
        friend class csv::value;
        row();
        std::vector<std::string> m_colnames;
        std::vector<csv::value> m_row;
    };
}

#pragma once

#include <string>
#include <vector>

#include "value.hpp"
#include "exceptions.hpp"

namespace csv
{
    class row
    {
        friend class data;
        friend class row;
        friend class value;
    public:
        row(const row &r);
        row(const std::vector<std::string> &colnames, const std::vector<value> &row);
        value column(const std::string &colname);
        ~row();
    private:
        row();
        std::vector<std::string> m_colnames;
        std::vector<value> m_row;
    };
}

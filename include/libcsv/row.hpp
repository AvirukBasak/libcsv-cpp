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
        row() = delete;
        row(const row &r);
        row(const std::vector<std::string> *colnames, const std::vector<value> &r);
        int length();
        value column(const std::string &colname);
        ~row();
    private:
        row(const std::vector<std::string> &r);
        const std::vector<std::string> *m_colnames;
        std::vector<value> m_row;
    };
}

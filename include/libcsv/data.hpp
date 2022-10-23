#pragma once

#include <string>
#include <vector>
#include <functional>

#include "value.hpp"
#include "row.hpp"
#include "exceptions.hpp"

namespace csv
{
    class data
    {
        friend class data;
        friend class csv::row;
        friend class value;
    public:
        data();
        data(const data &d);
        int rows();
        int columns();
        std::vector<std::string> getColumnNames();
        void setColumnNames(const std::vector<std::string> &colnames);
        csv::row getRow(int rownum);
        std::vector<csv::row> getRows(const std::function<bool (csv::row row)> &condition);
        void insertNextRow(const csv::row &row);
        void insertNextRow(const std::vector<std::string> &row);
        ~data();
    private:
        int m_rowc;
        int m_colc;
        std::vector<std::string> m_colnames;
        std::vector<csv::row> m_rows;
    };
}

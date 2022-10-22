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
        data(const data &d);
        int countRows();
        int countCols();
        csv::row row(int rownum);
        std::vector<csv::row> rows(const std::function<void (csv::row row)> &f);
    private:
        data();
        int m_rows;
        int m_cols;
    };
}

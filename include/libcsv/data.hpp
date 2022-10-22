#pragma once

#include <string>
#include <vector>

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
        csv::row row();
        std::vector<csv::row> rows();
    private:
        data();
        int m_rows;
        int m_cols;
    };
}

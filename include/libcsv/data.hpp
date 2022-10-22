#pragma once

#include <string>
#include <vector>

namespace csv
{
    class data
    {
    public:
        data(const data &d);
        int countRows();
        int countCols();
        csv::row row();
        std::vector<csv::row> rows();
    private:
        friend class csv::data;
        friend class csv::row;
        friend class csv::value;
        data();
        int m_rows;
        int m_cols;
    };
}

#pragma once

#include <string>
#include <vector>

#include "exceptions.hpp"

namespace csv
{
    class value
    {
        friend class data;
        friend class row;
        friend class value;
    public:
        value(const value &v);
        value(const std::string &s);
        std::string toString();
        /**
         * @return bool
         * @throws TypeMismatchException if data in CSV file can't be converted to bool
         */
        bool toBool();
        char toChar();
        short toShort();
        int toInt();
        long long toLong();
        float toFloat();
        double toDouble();
    private:
        value();
        std::string m_val;
    };
}
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
#pragma once

#include <string>
#include <vector>

#include "value.hpp"
#include "row.hpp"
#include "data.hpp"
#include "exceptions.hpp"

namespace csv
{
    data loadFile(const std::string &path);
}
#pragma once
#include <string>

namespace csv
{
    typedef std::string Exception;
    const Exception TypeMismatchException = "csv::TypeMismatchException";
}

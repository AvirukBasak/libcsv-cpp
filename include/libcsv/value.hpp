#pragma once

#include <string>
#include <vector>

namespace csv
{
    class value
    {
    public:
        value(const csv::value &v);
        value(const std::string &s);
        std::string toString();
        /**
         * @return bool
         * @throws csv::TypeMismatchException if data in CSV file can't be converted to bool
         */
        bool toBool();
        char toChar();
        short toShort();
        int toInt();
        long long toLong();
        float toFloat();
        double toDouble();
    private:
        friend class csv::data;
        friend class csv::row;
        friend class csv::value;
        value();
        std::string m_val;
    };
}

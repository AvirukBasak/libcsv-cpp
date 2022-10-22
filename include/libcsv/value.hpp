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

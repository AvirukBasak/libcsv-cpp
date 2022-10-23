#pragma once

#include <string>
#include <vector>

namespace csv
{
    class value
    {
        friend class data;
        friend class row;
        friend class value;
    public:
        value();
        value(bool v);
        value(char v);
        value(short v);
        value(int v);
        value(long long v);
        value(float v);
        value(double v);
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
        std::string m_val;
    };
    static value garbage_val = "0";
}

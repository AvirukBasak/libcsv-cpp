#include <string>
#include <vector>

#include "libcsv/exceptions.hpp"
#include "libcsv/value.hpp"

csv::value::value(bool v)
    : m_val(v ? "true" : "false")
{}

csv::value::value(char v)
    : m_val(std::string("") + v)
{}

csv::value::value(short v)
    : m_val(std::to_string(v))
{}

csv::value::value(int v)
    : m_val(std::to_string(v))
{}

csv::value::value(long long v)
    : m_val(std::to_string(v))
{}

csv::value::value(float v)
    : m_val(std::to_string(v))
{}

csv::value::value(double v)
    : m_val(std::to_string(v))
{}

csv::value::value(const csv::value &v)
    : m_val(v.m_val)
{}

csv::value::value(const std::string &s)
    : m_val(s)
{}

std::string csv::value::toString()
{
    return m_val;
}

/**
 * @return bool
 * @throws csv::TypeMismatchException if data in CSV file can't be converted to bool
 */
bool csv::value::toBool()
{
    if (m_val == "true" || (int) std::stoi(m_val) == 1)
        return true;
    else if (m_val == "false" || (int) std::stoi(m_val) == 0)
        return false;
    else throw csv::TypeMismatchException("for value \"" + m_val + "\"");
    return false;
}

char csv::value::toChar()
{
    return (char) m_val[0];
}

short csv::value::toShort()
{
    return (short) std::stoi(m_val);
}

int csv::value::toInt()
{
    return (int) std::stoi(m_val);
}

long long csv::value::toLong()
{
    return (long long) std::stoll(m_val, nullptr, 10);
}

float csv::value::toFloat()
{
    return (float) std::stof(m_val);
}

double csv::value::toDouble()
{
    return (double) std::stof(m_val);
}

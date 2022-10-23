#include <iostream>
#include <string>

#include "libcsv/exceptions.hpp"

csv::Exception::Exception()
    : m_msg("csv::Exception")
{}

csv::Exception::Exception(const std::string &s)
    : m_msg("csv::Exception: " + s)
{}

std::string csv::Exception::toString()
{
    return m_msg;
}

void csv::Exception::print()
{
    std::cerr << m_msg << "\n";
}

csv::ValueNotFoundException::ValueNotFoundException()
    : csv::Exception("csv::ValueNotFoundException")
{}

csv::ValueNotFoundException::ValueNotFoundException(const std::string &s)
    : csv::Exception("csv::ValueNotFoundException: " + s)
{}

csv::TypeMismatchException::TypeMismatchException()
    : csv::Exception("csv::TypeMismatchException")
{}

csv::TypeMismatchException::TypeMismatchException(const std::string &s)
    : csv::Exception("csv::TypeMismatchException: " + s)
{}

csv::IndexOutOfBoundsException::IndexOutOfBoundsException()
    : csv::Exception("csv::IndexOutOfBoundsException")
{}

csv::IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string &s)
    : csv::Exception("csv::IndexOutOfBoundsException: " + s)
{}

csv::ColumnSizeMismatchException::ColumnSizeMismatchException()
    : csv::Exception("csv::ColumnSizeMismatchException")
{}

csv::ColumnSizeMismatchException::ColumnSizeMismatchException(const std::string &s)
    : csv::Exception("csv::ColumnSizeMismatchException: " + s)
{}

template <typename T>
void csv::throwException()
{
    throw T();
}

template <typename T>
void csv::throwException(const std::string &s)
{
    T ex = T(s);
#ifdef DEBUG
    ex.print();
#endif
    throw ex;
}

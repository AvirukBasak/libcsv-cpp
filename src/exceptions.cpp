#include <iostream>
#include <string>

#include "libcsv/exceptions.hpp"

csv::Exception::Exception()
    : m_msg("csv::Exception")
{}

csv::Exception::Exception(const std::string &s)
    : m_msg("csv::Exception: " + s)
{}

csv::Exception::Exception(const std::string &s, bool noprefix)
    : m_msg(s)
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
    : csv::Exception("csv::ValueNotFoundException", true)
{}

csv::ValueNotFoundException::ValueNotFoundException(const std::string &s)
    : csv::Exception("csv::ValueNotFoundException: " + s, true)
{}

csv::TypeMismatchException::TypeMismatchException()
    : csv::Exception("csv::TypeMismatchException", true)
{}

csv::TypeMismatchException::TypeMismatchException(const std::string &s)
    : csv::Exception("csv::TypeMismatchException: " + s, true)
{}

csv::IndexOutOfBoundsException::IndexOutOfBoundsException()
    : csv::Exception("csv::IndexOutOfBoundsException", true)
{}

csv::IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string &s)
    : csv::Exception("csv::IndexOutOfBoundsException: " + s, true)
{}

csv::ColumnSizeMismatchException::ColumnSizeMismatchException()
    : csv::Exception("csv::ColumnSizeMismatchException", true)
{}

csv::ColumnSizeMismatchException::ColumnSizeMismatchException(const std::string &s)
    : csv::Exception("csv::ColumnSizeMismatchException: " + s, true)
{}

csv::FileOpenFailedException::FileOpenFailedException()
    : csv::Exception("csv::FileOpenFailedException", true)
{}

csv::FileOpenFailedException::FileOpenFailedException(const std::string &s)
    : csv::Exception("csv::FileOpenFailedException: " + s, true)
{}

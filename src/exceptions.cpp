#include <iostream>
#include "libcsv/exceptions.hpp"

csv::Exception::Exception()
    : m_msg("csv::Exception")
{}

csv::Exception::Exception(const std::string &s)
    : m_msg("csv::Exception: " + s)
{}

csv::ValueNotFoundException::ValueNotFoundException()
    : m_msg("csv::ValueNotFoundException")
{}

csv::ValueNotFoundException::ValueNotFoundException(const std::string &s)
    : m_msg("csv::ValueNotFoundException: " + s)
{}

csv::TypeMismatchException::TypeMismatchException()
    : m_msg("csv::TypeMismatchException")
{}

csv::TypeMismatchException::TypeMismatchException(const std::string &s)
    : m_msg("csv::TypeMismatchException: " + s)
{}

csv::IndexOutOfBoundsException::IndexOutOfBoundsException()
    : m_msg("csv::IndexOutOfBoundsException")
{}

csv::IndexOutOfBoundsException::IndexOutOfBoundsException(const std::string &s)
    : m_msg("csv::IndexOutOfBoundsException: " + s)
{}

csv::ColumnSizeMismatchException::ColumnSizeMismatchException()
    : m_msg("csv::ColumnSizeMismatchException")
{}

csv::ColumnSizeMismatchException::ColumnSizeMismatchException(const std::string &s)
    : m_msg("csv::ColumnSizeMismatchException: " + s)
{}

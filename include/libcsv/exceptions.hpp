#pragma once
#include <string>

namespace csv
{
    class Exception
    {
    public:
        Exception();
        Exception(const std::string &str);
    private:
        std::string m_msg;
    };

    /** Occurs when a value is not found at a row, column. */
    class ValueNotFoundException : Exception
    {
    public:
        ValueNotFoundException();
        ValueNotFoundException(const std::string &str);
    };

    /** Occurs when csv::value to converted to an invalid C++ type. */
    class TypeMismatchException : Exception
    {
    public:
        TypeMismatchException();
        TypeMismatchException(const std::string &str);
    };

    /** Occurs when accessed index of a table is invalid. */
    class IndexOutOfBoundsException : Exception
    {
    public:
        IndexOutOfBoundsException();
        IndexOutOfBoundsException(const std::string &str);
    };

    /** Occurs when a row that is less or more in length than total number of column names is appended to a data table. */
    class ColumnSizeMismatchException : Exception
    {
    public:
        ColumnSizeMismatchException();
        ColumnSizeMismatchException(const std::string &str);
    };
}

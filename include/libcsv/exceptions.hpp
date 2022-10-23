#pragma once

#include <string>

namespace csv
{
    class Exception
    {
    public:
        Exception();
        Exception(const std::string &str);
        Exception(const std::string &s, bool noprefix);
        std::string toString();
        void print();
    protected:
        std::string m_msg;
    };

    /** Occurs when a value is not found at a row, column. */
    class ValueNotFoundException : public Exception
    {
    public:
        ValueNotFoundException();
        ValueNotFoundException(const std::string &str);
    };

    /** Occurs when csv::value to converted to an invalid C++ type. */
    class TypeMismatchException : public Exception
    {
    public:
        TypeMismatchException();
        TypeMismatchException(const std::string &str);
    };

    /** Occurs when accessed index of a table is invalid. */
    class IndexOutOfBoundsException : public Exception
    {
    public:
        IndexOutOfBoundsException();
        IndexOutOfBoundsException(const std::string &str);
    };

    /** Occurs when a row that is less or more in length than total number of column names is appended to a data table. */
    class ColumnSizeMismatchException : public Exception
    {
    public:
        ColumnSizeMismatchException();
        ColumnSizeMismatchException(const std::string &str);
    };

    /** Occurs when file reading fails. */
    class FileOpenFailedException : public Exception
    {
    public:
        FileOpenFailedException();
        FileOpenFailedException(const std::string &str);
    };

    /** Throw a message less exception*/
    template <typename T> void throwException();

    /** Throw an exception with a message */
    template <typename T> void throwException(const std::string &s);
}

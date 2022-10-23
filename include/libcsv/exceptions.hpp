#pragma once
#include <string>

namespace csv
{
    typedef std::string Exception;
    const Exception TypeMismatchException = "csv::TypeMismatchException";
    const Exception IndexOutOfBoundsException = "csv::IndexOutOfBoundsException";
    void throwException(Exception ex);
}

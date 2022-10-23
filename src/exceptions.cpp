#include <iostream>
#include "libcsv/exceptions.hpp"

void csv::throwException(csv::Exception ex)
{
#ifdef DEBUG
    std::cerr << ex << "\n";
#endif
    throw ex;
}

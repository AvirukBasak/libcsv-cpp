#pragma once

#include <string>
#include <vector>

#include "value.hpp"

namespace csv
{
    class row
    {
        friend class data;
        friend class row;
        friend class value;
    public:
        /**
         * Copy a row.
         * @param csv::row
         */
        row(const row &r);
        /**
         * Destroy row object.
         */
        ~row();
        /**
         * Get row length.
         * @return int
         */
        int length();
        /**
         * Get value of a row for a specified column name.
         * @param std::string
         * @return csv::value
         * @throws csv::ValueNotFoundException If column name doesn't exist
         */
        value column(const std::string &colname);
        /**
         * Get value of a row for a specified column name.
         * @param std::string
         * @return csv::value &
         * @throws csv::ValueNotFoundException If column name doesn't exist
         */
        value &operator[](const std::string &colname);
        /**
         * Get value of a row for a specified column index.
         * @param int
         * @return csv::value
         * @throws csv::IndexOutOfBoundsException If column index is out of range
         */
        value column(int index);
        /**
         * Get value of a row for a specified column index.
         * @param int
         * @return csv::value &
         * @throws csv::IndexOutOfBoundsException If column index is out of range
         */
        value &operator[](int index);
    private:
        /**
         * A row cannot be empty.
         */
        row();
        /**
         * Construct a row from a vector of std::string.
         * @param std::vector<std::string>* Pointer to csv::data::m_colnames
         * @param std::vector<std::string>
         */
        row(const std::vector<std::string> *colnames, const std::vector<std::string> &r);
        /** Pointer to csv::data::m_colnames */
        const std::vector<std::string> *m_colnames;
        /** Data in row */
        std::vector<value> m_row;
    };
}

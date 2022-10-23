#pragma once

#include <string>
#include <vector>

#include "value.hpp"
#include "exceptions.hpp"

namespace csv
{
    class row
    {
        friend class data;
        friend class row;
        friend class value;
    public:
        /**
         * A row cannot be empty.
         */
        row() = delete;
        /**
         * Copy a row.
         * @param csv::row
         */
        row(const row &r);
        /**
         * Construct a row from a vector of std::string.
         * @param std::vector<std::string>* Pointer to csv::data::m_colnames
         * @param std::vector<std::string>
         */
        row(const std::vector<std::string> *colnames, const std::vector<std::string> &r);
        /**
         * Get row length.
         * @return int
         */
        int length();
        /**
         * Get value of a row for a specified column.
         * @param std::string
         * @return csv::value
         * @throws csv::ValueNotFoundException If value is not found for specified column name
         */
        value column(const std::string &colname);
        /**
         * Get value of a row for a specified column.
         * @param std::string
         * @return csv::value &
         * @throws csv::ValueNotFoundException If value is not found for specified column name
         */
        value &operator[](const std::string &colname);
        ~row();
    private:
        /** Pointer to csv::data::m_colnames */
        const std::vector<std::string> *m_colnames;
        /** Data in row */
        std::vector<value> m_row;
    };
}

#pragma once

#include <string>
#include <vector>
#include <functional>

#include "row.hpp"
#include "value.hpp"

namespace csv
{
    class data
    {
        friend class data;
        friend class csv::row;
        friend class value;
    public:
        /**
         * Create a data object without any rows.
         * @param std::vector<std::string> Column names
         */
        data(const std::vector<std::string> &colnames);
        /**
         * Copy a data object.
         * @param csv::data Source data
         */
        data(const data &d);
        /**
         * Destroy data object.
         */
        ~data();
        /**
         * Get count of rows in the table.
         * @return int
         */
        int rows();
        /**
         * Get count of columns in the table.
         * @return int
         */
        int columns();
        /**
         * Get list of column names in the table.
         * @return std::vector<std::string>
         */
        std::vector<std::string> getColumnNames();
        /**
         * Get a row by index from table 
         * @return csv::row
         * @throws csv::IndexOutOfBoundsException If rownum is out of range
         */
        csv::row getRow(int rownum);
        /**
         * Get a row by index from table 
         * @return csv::row &
         * @throws csv::IndexOutOfBoundsException If rownum is out of range
         */
        csv::row &operator[](int rownum);
        /**
         * Get a list of rows from the table that satisfy the condition function.
         * @param std::function<bool (csv::row row)>
         * @return std::vector<csv::row>
         */
        std::vector<csv::row> getRows(const std::function<bool (csv::row row)> &condition);
        /**
         * Append a rows to the table.
         * @param std::vector<std::string>
         * @throw csv::ColumnSizeMismatchException If row.size() != data::columns()
         */
        void appendRow(const std::vector<std::string> &row);
    private:
        /** Count of rows */
        int m_rowc;
        /** Count of columns */
        int m_colc;
        /** Names of columns */
        std::vector<std::string> m_colnames;
        /** List of rows, i.e. the table */
        std::vector<csv::row> m_rows;
    };
}

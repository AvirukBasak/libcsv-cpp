#include <iostream>
#include "libcsv.hpp"

int main()
{
    /* 1st row -> string col names
     * 1st col -> numeric id, otherwise csv::data::row() returns row based on total number of rows
     * slno, names,     id,   marks
     *   5,   John,      i00,  83
     *   3,   Jack,      i01,  73
     *   2,   James,     i02,  96
     *   1,   Johnathan, i03,  79
     *   4,   Joseph,    i04,  84
     *   0,   Joe,       i05,  93
     */
    csv::data data = csv::loadFile("tests/files/test.csv");
    std::vector<std::string> colnames = data.getColumnNames();
    int rows = data.rows();
    int cols = data.columns();
    std::cout << "csv dimensions: " << rows << "×" << cols << "\n";
    std::string name = data[1]["names"].toString(); // returns "Jack"
    std::vector<csv::row> moreThan80 = data.getRows([](csv::row row) { return row["marks"].toInt() > 80; });
    for (auto &row : moreThan80)
        if (row["names"].toString() == "Joe") {
            std::cout << "Joe's score is over 80\n";
            std::cout << "Joe's id is " << row["id"].toString() << "\n";
            break;
        }
    return 0;
}

#include <iostream>
#include "libcsv.hpp"

int main()
{
    /* 1st row -> std::string column_name
     * 1st col -> std::string unique_id
     * uid,  slno,  names,       marks
     *  i03,  0      John,        83
     *  i05,  1      Jack,        73
     *  i01,  2      James,       96
     *  i04,  3      Johnathan,   79
     *  i02,  4      Joseph,      84
     *  i00,  5      Joe,         93
     */
    csv::data data = csv::loadFile("tests/files/test.csv");
    std::vector<std::string> colnames = data.getColumnNames();
    std::cout << "columns present: { ";
    for (const auto &name : colnames)
        std::cout << name << ", ";
    std::cout << "}\n";
    int rows = data.rows();
    int cols = data.columns();
    std::cout << "csv dimensions: " << rows << "×" << cols << "\n";
    std::string name = data["i02"]["names"].toString(); // returns "Joseph"
    std::cout << "retrieved name: " << name << ", for id: " << "i02" << "\n";
    std::vector<csv::row> moreThan80 = data.getRows([](auto row) { return row["marks"].toInt() > 80; });
    for (auto &row : moreThan80)
        if (row["names"].toString() == "Joe") {
            std::cout << "Joe's score is over 80\n";
            std::cout << "Joe's slno is " << row["slno"].toString() << "\n";
            break;
        }
    return 0;
}

/* OUTPUT

columns present: { uid, slno, names, marks, }
csv dimensions: 6×4
retrieved name: Joseph, for id: i02
Joe's score is over 80
Joe's slno is 5

*/

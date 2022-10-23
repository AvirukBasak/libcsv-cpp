#include <fstream>

#include "libcsv/data.hpp"
#include "libcsv/row.hpp"
#include "libcsv/value.hpp"
#include "libcsv/main.hpp"

csv::data csv::loadFile(const std::string &path)
{
    int rowno = 0;
    csv::data csvdata;
    std::ifstream csvfile;
    csvfile.open(path);
    while (csvfile) {
        std::string line;
        std::getline(csvfile, line);
        std::string val = "";
        std::vector<std::string> row;
        for (const char &c : line)
            if (c == ' ');
            else if (c == ',') {
                row.push_back(val);
                val = "";
            } else val += c;
        if (rowno == 0)
            csvdata.setColumnNames(row);
        else
            csvdata.insertNextRow(row);  
    }
    csvfile.close();
    return csvdata;
}

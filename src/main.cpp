#include <fstream>
#include <string>
#include <vector>

#include "libcsv/main.hpp"
#include "libcsv/data.hpp"

std::vector<std::string> csv::tokenizeLine(const std::string &line)
{
    std::string val = "";
    std::vector<std::string> tokens;
    for (const char &c : line)
        if (c == ' ');
        else if (c == ',') {
            tokens.push_back(val);
            val = "";
        } else val += c;
    return tokens;
}

csv::data csv::loadFile(const std::string &path)
{
    std::ifstream csvfile(path);
    std::string line;
    std::getline(csvfile, line);
    csv::data csvdata(csv::tokenizeLine(line));
    int rowno = 1;
    while (csvfile) {
        std::getline(csvfile, line);
        csvdata.appendRow(csv::tokenizeLine(line));
        rowno++;
    }
    csvfile.close();
    return csvdata;
}

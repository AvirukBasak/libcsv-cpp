#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "libcsv/main.hpp"
#include "libcsv/data.hpp"
#include "libcsv/exceptions.hpp"

std::vector<std::string> csv::tokenizeLine(const std::string &ln)
{
    std::string line = ln + "\n";
    std::string val = "";
    std::vector<std::string> tokens;
    for (const char &c : line)
        if (c == 0x20 || c == 0x0c);
        else if (c == 0x0a || c == ',') {
            tokens.push_back(val);
            val = "";
        } else val += c;
    return tokens;
}

csv::data csv::loadFile(const std::string &path)
{
    std::ifstream csvfile(path);
    std::string line;
    if (!csvfile.is_open())
        csv::throwException<csv::FileOpenFailedException>("for filepath \"" + path + "\"");
    if (!csvfile.eof())
        std::getline(csvfile, line);
    csv::data csvdata(csv::tokenizeLine(line));
    while (!csvfile.eof()) {
        std::getline(csvfile, line);
        if (line == "") break;
        csvdata.appendRow(csv::tokenizeLine(line));
    }
    csvfile.close();
    return csvdata;
}

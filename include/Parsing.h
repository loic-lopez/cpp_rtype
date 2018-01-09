//
// Created by Loic Dupil on 09/01/2018.
//

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>

#ifndef R_TYPE_PARSING_H
#define R_TYPE_PARSING_H

class Parsing
{

public:
    static void loadCSV(const std::string path, std::function<void (std::string const &, int const &)> layer);
};

#endif //R_TYPE_PARSING_H

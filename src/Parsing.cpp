//
// Created by Loic Dupil on 09/01/2018.
//

#include "Parsing.h"

void    Parsing::loadCSV(const std::string path, std::function<void (std::string const &, int const &)> layer)
{
    std::ifstream infile("./ressources/" + path + "/" + path + ".csv");
    std::string line;
        while (std::getline(infile, line)) {
            std::string pathSprite = "./ressources/" + path + "/" + line.substr(0, line.find(','));
            line = line.substr(line.find(',') + 1);
            //back.addLayer(pathSprite, std::stoi(line.substr(0, line.find(','))));
            layer(pathSprite, std::stoi(line.substr(0, line.find(','))));

        }


}
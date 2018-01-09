//
// Created by Zakelis on 09/01/2018.
//

#ifndef R_TYPE_MENU_H
#define R_TYPE_MENU_H

#include <SFML/Audio.hpp>
#include "Enum.h"
#include "Bg.h"

class Menu {
private:
    Bg background;
    sf::Music music;

public:
    Menu();
    ~Menu();
    void initMenu(const std::string &path);
    void drawMenu(sf::RenderWindow &App);

};


#endif //R_TYPE_MENU_H

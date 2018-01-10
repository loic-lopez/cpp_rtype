//
// Created by Zakelis on 09/01/2018.
//

#ifndef R_TYPE_MENU_H
#define R_TYPE_MENU_H

#include <SFML/Audio.hpp>
#include "Parsing.h"
#include "Enum.h"
#include "Bg.h"
#include "HUD.h"

class Menu {
private:
    Orientation orientation;
    Bg background;
    Hud hud;
    sf::Music music;

public:
    Menu();
    ~Menu();
    void initMenu(const std::string &path_dir);
    void drawMenu(sf::RenderWindow &App);
};


#endif //R_TYPE_MENU_H

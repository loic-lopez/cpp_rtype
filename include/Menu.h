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
    sf::Sprite menuBackgroundSprite;
    sf::Texture backgroundTexture;
    sf::Music music;
    Hud hud;

public:
    Menu();
    ~Menu();
    void initMenu(const std::string &path);
    void drawMenu(sf::RenderWindow &App);
};


#endif //R_TYPE_MENU_H

//
// Created by loic lopez on 09/01/2018.
//

#ifndef R_TYPE_WINDOW_H
#define R_TYPE_WINDOW_H

#include <SFML/Graphics.hpp>
#include <Thor/Graphics.hpp>
#include "Enum.h"
#include "static_constructor.h"

class WindowProperties
{
public:
    static unsigned int WIN_HEIGHT;
    static unsigned int WIN_WIDTH;
    static GameState    gameState;
    static sf::RenderWindow *App;
    static Orientation orientation;
    static unsigned int MAX_PLAYER_HP;
    static Difficulty difficulty;

    static void StaticWindow()
    {
        (void)static_constructor<&WindowProperties::StaticWindow>::c;

        sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();

        WIN_HEIGHT = videoMode.height;
        WIN_WIDTH = videoMode.width;
        orientation = Orientation::HORIZONTAL;
        gameState = GameState::LEVEL5;
        difficulty = Difficulty::HARMLESS;
        App = new sf::RenderWindow(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "R-TYPE", sf::Style::Fullscreen);
        App->setVerticalSyncEnabled(true);
        MAX_PLAYER_HP = 5;
    }
};

#endif //R_TYPE_WINDOW_H

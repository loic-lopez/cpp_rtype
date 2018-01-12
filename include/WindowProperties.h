//
// Created by loic lopez on 09/01/2018.
//

#ifndef R_TYPE_WINDOW_H
#define R_TYPE_WINDOW_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Graphics.hpp>

template<void(*ctor)()>
struct static_constructor
{
    struct constructor { constructor() { ctor(); } };
    static constructor c;
};

template<void(*ctor)()>
typename static_constructor<ctor>::constructor static_constructor<ctor>::c;

class WindowProperties
{
public:
    static unsigned int WIN_HEIGHT;
    static unsigned int WIN_WIDTH;
    static GameState    gameState;


    static void StaticWindow()
    {
        (void)static_constructor<&WindowProperties::StaticWindow>::c;

        sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();

        WIN_HEIGHT = videoMode.height;
        WIN_WIDTH = videoMode.width;
        gameState = GameState::MENU;
    }
};

#endif //R_TYPE_WINDOW_H

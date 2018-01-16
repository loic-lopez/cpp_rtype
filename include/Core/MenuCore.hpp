//
// Created by Pierre on 30/11/2017.
//

#ifndef RTYPE_GameCore_H
#define RTYPE_GameCore_H

#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <Handler/MenuHandler.h>
#include "Enum.h"
#include "Player.h"
#include "Enemy.h"
#include "WindowProperties.h"
#include "HUD.h"
#include "Button.h"

class MenuCore
{
private:
    void eventHandler(sf::Event& event);

    static MenuCore m_instance;

    MenuCore();

    ~MenuCore();

    MenuCore &operator=(const MenuCore &)
    {
        return *this;
    }

    MenuCore(const MenuCore &)
    {}

    sf::Clock clock;
    MenuHandler menu;

public:
    static MenuCore &Instance();
    void start();
};


#endif //RTYPE_GameCore_H

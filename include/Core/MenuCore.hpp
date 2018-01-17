//
// Created by Pierre on 30/11/2017.
//

#ifndef RTYPE_GameCore_H
#define RTYPE_GameCore_H

#include <SFML/Graphics.hpp>
#include <Handler/MenuHandler.h>
#include "Enum.h"
#include "Static/WindowProperties.h"
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

    MenuHandler menu;

public:
    static MenuCore &Instance();
    void start();
};


#endif //RTYPE_GameCore_H

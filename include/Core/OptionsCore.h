//
// Created by Zakelis on 22/01/2018.
//

#ifndef R_TYPE_OPTIONSCORE_H
#define R_TYPE_OPTIONSCORE_H

#include <SFML/Graphics.hpp>
#include "Handler/OptionsHandler.h"
#include "Enum.h"
#include "Static/WindowProperties.h"
#include "Button.h"

class OptionsCore
{
private:
    void eventHandler(sf::Event& event);

    static OptionsCore m_instance;

    OptionsCore();

    ~OptionsCore();

    OptionsCore &operator=(const OptionsCore &)
    {
        return *this;
    }

    OptionsCore(const OptionsCore &)
    {}

    OptionsHandler  options;

public:
    static OptionsCore &Instance();
    void start();
};

#endif //R_TYPE_OPTIONSCORE_H

//
// Created by Zakelis on 22/01/2018.
//

#ifndef R_TYPE_CreditsCORE_H
#define R_TYPE_CreditsCORE_H

#include <SFML/Graphics.hpp>
#include "Handler/CreditsHandler.h"
#include "Enum.h"
#include "Static/WindowProperties.h"
#include "Button.h"

class CreditsCore
{
private:
    void eventHandler(sf::Event& event);

    static CreditsCore m_instance;

    CreditsCore();

    ~CreditsCore();

    CreditsCore &operator=(const CreditsCore &)
    {
        return *this;
    }

    CreditsCore(const CreditsCore &)
    {}

    CreditsHandler  Credits;

public:
    static CreditsCore &Instance();
    void start();
};

#endif //R_TYPE_CreditsCORE_H

//
// Created by loic lopez on 17/01/2018.
//

#ifndef R_TYPE_MENUINGAMECORE_H
#define R_TYPE_MENUINGAMECORE_H


#include <SFML/System/Clock.hpp>
#include <Handler/MenuInGameHandler.h>
#include <Enum.h>

class MenuInGameCore
{
private:
    GameState previousGameState;
public:
    GameState getPreviousGameState() const;
    void setPreviousGameState(GameState previousGameState);

private:
    static MenuInGameCore   m_instance;
    MenuInGameHandler       menuInGameHandler;

    void EventHandler(sf::Event &event);
    MenuInGameCore();
    ~MenuInGameCore();
    MenuInGameCore &operator=(const MenuInGameCore&)
    {
        return *this;
    }
    MenuInGameCore(const MenuInGameCore&)
    {
    }

public:
    static MenuInGameCore &Instance();
    void start();
};


#endif //R_TYPE_MENUINGAMECORE_H

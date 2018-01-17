//
// Created by loic lopez on 17/01/2018.
//

#include <Static/WindowProperties.h>
#include <Core/MenuInGameCore.h>
#include <Handler/GameHandler.h>

MenuInGameCore MenuInGameCore::m_instance = MenuInGameCore();

void MenuInGameCore::EventHandler(sf::Event &event)
{
    while (WindowProperties::App->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                WindowProperties::gameState = GameState::CLOSE;
                break;
            }

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    WindowProperties::gameState = previousGameState;
                }
                break;
            default:
                break;
        }
    }
}

MenuInGameCore::MenuInGameCore()
{
    menuInGameHandler.initMenuInGameHandler("inGameMenu");
}

MenuInGameCore &MenuInGameCore::Instance()
{
    return m_instance;
}

void MenuInGameCore::start()
{
    sf::Event Event{};

    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::GAMEOVER)
    {
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17)
        {
            clock.restart();
            this->menuInGameHandler.updateMenuInGame(Event, *WindowProperties::App);
            this->menuInGameHandler.drawMenuInGame(*WindowProperties::App);
            GameHandler::Instance().getCurrentLevel()->drawAll(*WindowProperties::App);
            this->EventHandler(Event);
            WindowProperties::App->display();
        }
    }
}

GameState MenuInGameCore::getPreviousGameState() const
{
    return previousGameState;
}

void MenuInGameCore::setPreviousGameState(GameState previousGameState)
{
    MenuInGameCore::previousGameState = previousGameState;
}

MenuInGameCore::~MenuInGameCore()
{

}
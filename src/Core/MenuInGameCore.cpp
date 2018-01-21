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
            case sf::Event::KeyReleased:
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

    WindowProperties::App->setMouseCursorVisible(true);
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::INGAMEMENU)
    {
        this->menuInGameHandler.updateMenuInGame(Event, *WindowProperties::App);
        GameHandler::Instance().getCurrentLevel(previousGameState)->drawAll(*WindowProperties::App);
        this->menuInGameHandler.drawMenuInGame(*WindowProperties::App);
        this->EventHandler(Event);
        WindowProperties::App->display();
    }
    WindowProperties::App->setMouseCursorVisible(false);
}

GameState MenuInGameCore::getPreviousGameState() const
{
    return previousGameState;
}

void MenuInGameCore::setPreviousGameState(GameState previousGameState)
{
    MenuInGameCore::previousGameState = previousGameState;
    WindowProperties::gameState = GameState::INGAMEMENU;
}

MenuInGameCore::~MenuInGameCore()
{

}

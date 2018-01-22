//
// Created by Loïc on 16/01/2018.
//

#include <Core/WinScreenCore.h>

WinScreenCore WinScreenCore::m_instance = WinScreenCore();

WinScreenCore::WinScreenCore()
{
    this->winScreen.initWinScreen("winScreen");
}

WinScreenCore::~WinScreenCore()
{

}

WinScreenCore &WinScreenCore::Instance()
{
    return m_instance;
}

void WinScreenCore::start()
{
    sf::Event Event{};

    this->winScreen.playMusic();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::WIN)
    {
        this->winScreen.updateWinScreen(Event, *WindowProperties::App);
        this->winScreen.drawWinScreen(*WindowProperties::App);
        this->EventHandler(Event);
        WindowProperties::App->display();
    }
    this->winScreen.stopMusic();
}

void WinScreenCore::EventHandler(sf::Event &event)
{
    while (WindowProperties::App->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                WindowProperties::gameState = GameState::CLOSE;
                this->winScreen.stopMusic();
                break;
            }

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    WindowProperties::gameState = GameState::CLOSE;
                    this->winScreen.stopMusic();
                }

                break;
            default:
                break;
        }
    }
}

WinScreenHandler &WinScreenCore::getWinScreen()
{
    return winScreen;
}

GameState WinScreenCore::getPreviousGameState() const
{
    return previousGameState;
}

void WinScreenCore::setPreviousGameState(GameState previousGameState)
{
    WinScreenCore::previousGameState = previousGameState;
}

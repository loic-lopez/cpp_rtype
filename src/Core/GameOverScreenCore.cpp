//
// Created by Zakelis on 16/01/2018.
//

#include <Core/GameOverScreenCore.h>

GameOverScreenCore GameOverScreenCore::m_instance = GameOverScreenCore();

GameOverScreenCore::GameOverScreenCore()
{
    this->gameOverScreen.initGameOverScreen("gameOverScreen");
}

GameOverScreenCore::~GameOverScreenCore()
{

}

GameOverScreenCore &GameOverScreenCore::Instance()
{
    return m_instance;
}

void GameOverScreenCore::start()
{
    sf::Event Event{};
    this->gameOverScreen.playMusic();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::GAMEOVER)
    {
        this->gameOverScreen.updateGameOverScreen(Event, *WindowProperties::App);
        this->gameOverScreen.drawGameOverScreen(*WindowProperties::App);
        this->EventHandler(Event);
        WindowProperties::App->display();
    }
    this->gameOverScreen.stopMusic();
}

void GameOverScreenCore::EventHandler(sf::Event &event)
{
    while (WindowProperties::App->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                WindowProperties::gameState = GameState::CLOSE;
                this->gameOverScreen.stopMusic();
                break;
            }

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                {
                    WindowProperties::gameState = GameState::CLOSE;
                    this->gameOverScreen.stopMusic();
                }

                break;
            default:
                break;
        }
    }
}
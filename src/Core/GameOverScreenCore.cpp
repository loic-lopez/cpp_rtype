//
// Created by Zakelis on 16/01/2018.
//

#include <Core/GameOverScreenCore.h>

GameOverScreenCore GameOverScreenCore::m_instance = GameOverScreenCore();

GameOverScreenCore::GameOverScreenCore() {
    this->gameOverScreen.initGameOverScreen("gameOverScreen");
}

GameOverScreenCore::~GameOverScreenCore() {

}

GameOverScreenCore &GameOverScreenCore::Instance() {
    return m_instance;
}

void GameOverScreenCore::start() {

    sf::Event Event{};

    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::GAMEOVER) {
        std::cout << (int) WindowProperties::gameState << std::endl;
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17) {
            clock.restart();
            this->gameOverScreen.updateGameOverScreen(Event, *WindowProperties::App);
            this->gameOverScreen.drawGameOverScreen(*WindowProperties::App);
            this->EventHandler(Event);
            WindowProperties::App->display();
        }
    }
}

void GameOverScreenCore::EventHandler(sf::Event &event) {
    while (WindowProperties::App->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                WindowProperties::gameState = GameState::CLOSE;
                this->gameOverScreen.stopMusic();
                break;
            }

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape) {
                    WindowProperties::gameState = GameState::CLOSE;
                    this->gameOverScreen.stopMusic();
                }

                break;
            case sf::Event::Resized:
                break;
            case sf::Event::LostFocus:
                break;
            case sf::Event::GainedFocus:
                break;
            case sf::Event::TextEntered:
                break;
            case sf::Event::KeyReleased:
                break;
            case sf::Event::MouseWheelMoved:
                break;
            case sf::Event::MouseWheelScrolled:
                break;
            case sf::Event::MouseButtonPressed:
                break;
            case sf::Event::MouseButtonReleased:
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseEntered:
                break;
            case sf::Event::MouseLeft:
                break;
            case sf::Event::JoystickButtonPressed:
                break;
            case sf::Event::JoystickButtonReleased:
                break;
            case sf::Event::JoystickMoved:
                break;
            case sf::Event::JoystickConnected:
                break;
            case sf::Event::JoystickDisconnected:
                break;
            case sf::Event::TouchBegan:
                break;
            case sf::Event::TouchMoved:
                break;
            case sf::Event::TouchEnded:
                break;
            case sf::Event::SensorChanged:
                break;
            case sf::Event::Count:
                break;
        }
    }
}
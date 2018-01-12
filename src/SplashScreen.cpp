//
// Created by Zakelis on 12/01/2018.
//

#include "SplashScreen.h"

SplashScreen SplashScreen::m_instance = SplashScreen();

SplashScreen::SplashScreen() {
    this->progressBar.setShowBackgroundAndFrame(true);
    this->progressBar.setSize({(float)WindowProperties::WIN_WIDTH / 2, (float)WindowProperties::WIN_HEIGHT / 4});
    this->progressBar.setFrameThickness(0.f);
    this->progressBar.setOrigin(0.0f, 0.0f);
    this->progressBar.setPosition(sf::Vector2f((float)WindowProperties::WIN_WIDTH / 4, ((float)WindowProperties::WIN_HEIGHT / 2) - (float)WindowProperties::WIN_HEIGHT / 8));
    std::cerr << this->progressBar.getPosition().x << "          " << this->progressBar.getPosition().y << std::endl;
    this->progressBar.setColor(sf::Color(25, 25, 112));
    this->progressBar.setBackgroundColor(sf::Color(220, 220, 220));
    this->progressBar.setFrameColor(sf::Color(0, 0, 0));
    this->progressBar.setPercentage(0.f);
}

SplashScreen::~SplashScreen() {

}

SplashScreen &SplashScreen::Instance() {
    return m_instance;
}

void SplashScreen::start() {
    bool isIncreasing{true};
    sf::Clock clock;
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::SPLASHSCREEN) {
        sf::Event event;
        while (WindowProperties::App->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
            WindowProperties::gameState = GameState::CLOSE;
        }
        const float frame{clock.restart().asSeconds() * 0.4f};
        const float target{isIncreasing ? progressBar.getRatio() + frame : progressBar.getRatio() - frame};
        if (target > 1.f)
            break;
        progressBar.setRatio(target);
        WindowProperties::App->draw(progressBar);
        WindowProperties::App->display();

    }
    WindowProperties::gameState = GameState::MENU;
}

void SplashScreen::EventHandler(sf::Event &event) {
    while (WindowProperties::App->pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                WindowProperties::gameState = GameState::CLOSE;
                break;

            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    WindowProperties::gameState = GameState::CLOSE;
                break;
        }
    }
}

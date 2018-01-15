//
// Created by Zakelis on 12/01/2018.
//

#include "SplashScreen.h"

SplashScreen SplashScreen::m_instance = SplashScreen();

SplashScreen::SplashScreen()
{
    this->progressBar.setShowBackgroundAndFrame(true);
    this->progressBar.setSize({(float) WindowProperties::WIN_WIDTH / 2, (float) WindowProperties::WIN_HEIGHT / 4});
    this->progressBar.setFrameThickness(5.f);
    this->progressBar.setOrigin(0.0f, 0.0f);
    this->progressBar.setPosition(sf::Vector2f((float) WindowProperties::WIN_WIDTH / 4,
                                               ((float) WindowProperties::WIN_HEIGHT / 2) -
                                               (float) WindowProperties::WIN_HEIGHT / 8));

    this->progressBar.setColor(sf::Color(25, 25, 112));
    this->progressBar.setBackgroundColor(sf::Color(220, 220, 220));
    this->progressBar.setFrameColor(sf::Color(255,215,0));
    this->progressBar.setPercentage(0.f);

    this->backgroundTexture.loadFromFile("./ressources/menu/menu_background.jpg");
    this->backgroundSprite.setTexture(backgroundTexture);
    float scaleX = (float) WindowProperties::WIN_WIDTH / this->backgroundSprite.getGlobalBounds().width;
    float scaleY = (float) WindowProperties::WIN_HEIGHT / this->backgroundSprite.getGlobalBounds().height;
    this->backgroundSprite.setPosition(0, 0);
    this->backgroundSprite.setScale(sf::Vector2f(scaleX, scaleY));
    this->music.openFromFile("./ressources/splashscreen/Guerre.ogg");
}

SplashScreen::~SplashScreen()
{

}

SplashScreen &SplashScreen::Instance()
{
    return m_instance;
}

void SplashScreen::start()
{
    bool isIncreasing{true};
    sf::Clock clock;
    this->music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::SPLASHSCREEN)
    {
        sf::Event event;
        while (WindowProperties::App->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                WindowProperties::gameState = GameState::CLOSE;
        }
        const float frame{clock.restart().asSeconds() * 0.5f};
        const float target{isIncreasing ? progressBar.getRatio() + frame : progressBar.getRatio() - frame};
        if (target > 1.f)
        {
            WindowProperties::gameState = GameState::MENU;
            break;
        }
        progressBar.setRatio(target);

        WindowProperties::App->draw(this->backgroundSprite);
        WindowProperties::App->draw(progressBar);
        WindowProperties::App->display();

    }
    this->music.stop();
}

void SplashScreen::EventHandler(sf::Event &event)
{
    while (WindowProperties::App->pollEvent(event))
    {
        switch (event.type)
        {
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

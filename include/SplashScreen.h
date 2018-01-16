//
// Created by Zakelis on 12/01/2018.
//

#ifndef R_TYPE_SPLASHSCREEN_H
#define R_TYPE_SPLASHSCREEN_H

#include <SelbaWard.hpp>
#include <SFML/Audio/Music.hpp>
#include "WindowProperties.h"

class SplashScreen : selbaward::ProgressBar
{
private:
    static SplashScreen m_instance;
    sf::Texture         backgroundTexture;
    sf::Sprite          backgroundSprite;
    sw::ProgressBar     progressBar;
    sf::Music           music;

    void EventHandler(sf::Event &event);
    SplashScreen();
    ~SplashScreen();
    SplashScreen &operator=(const SplashScreen &)
    {
        return *this;
    }

    SplashScreen(const SplashScreen &)
    {}

public:
    static SplashScreen &Instance();
    void start();
};

#endif //R_TYPE_SPLASHSCREEN_H

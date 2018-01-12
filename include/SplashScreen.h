//
// Created by Zakelis on 12/01/2018.
//

#ifndef R_TYPE_SPLASHSCREEN_H
#define R_TYPE_SPLASHSCREEN_H

#include <SelbaWard.hpp>
#include "WindowProperties.h"

class SplashScreen : selbaward::ProgressBar
{
private:
    static SplashScreen m_instance;
    void EventHandler(sf::Event &event);
    SplashScreen();
    ~SplashScreen();
    SplashScreen &operator=(const SplashScreen &)
    {}

    SplashScreen(const SplashScreen &)
    {}

public:
    static SplashScreen &Instance();
    void start();

    sw::ProgressBar progressBar;
};

#endif //R_TYPE_SPLASHSCREEN_H

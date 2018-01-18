//
// Created by Zakelis on 18/01/2018.
//

#ifndef R_TYPE_PREGAMETEST_H
#define R_TYPE_PREGAMETEST_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Audio/Music.hpp>
#include <memory>
#include "static_constructor.h"
#include "WindowProperties.h"

class PreGameTest
{
private:
    //LEVEL VARIABLES
    sf::Texture     preGameBackgroundTexture;
    sf::Sprite      preGameBackgroundSprite;
    sf::Texture     preGameTextTexture;
    sf::Sprite      preGameTextSprite;
    sf::Music       preGameMusic;

    //INV FADING VARIABLES
    float           baseFadeOpacityPercentageDecreasing;
    float           floatFadeOpacity;
    int             fadeOpacity;

public:
    void            loadPreGameLevel1();
    void            loadPreGameLevel2();
    void            loadPreGameLevel3();
    void            loadPreGameLevel4();
    void            loadPreGameLevel5();
};
#endif //R_TYPE_PREGAMETEST_H

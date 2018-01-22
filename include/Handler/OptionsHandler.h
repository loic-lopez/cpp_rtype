//
// Created by Zakelis on 22/01/2018.
//

#ifndef R_TYPE_OPTIONSHANDLER_H
#define R_TYPE_OPTIONSHANDLER_H

#include <SFML/Audio.hpp>
#include <Thor/Particles.hpp>
#include <Thor/Animations.hpp>
#include <Thor/Graphics.hpp>
#include <Thor/Vectors.hpp>
#include <Thor/Math.hpp>
#include "Parsing.h"
#include "Enum.h"
#include "Bg.h"
#include "HUD.h"
#include "Button.h"

class OptionsHandler {
private:

    //BACKGROUND AND MUSIC
    sf::Sprite optionsBackgroundSprite;
    sf::Texture backgroundTexture;
    sf::Music music;

    //BUTTON SYSTEM
    std::vector<std::string> buttonEffectsPaths;
    std::vector<std::shared_ptr<Button>> optionsButtons;
    std::vector<std::function<void()>> functionsHandler;

public:
    OptionsHandler();
    ~OptionsHandler();
    void initOptions(const std::string &path);
    void drawOptions(sf::RenderWindow &App);
    void updateOptions(sf::Event &e, sf::RenderWindow &window);
    void determineButtonsPosition();
    void stopMusic();
    void startMusic();
};

#endif

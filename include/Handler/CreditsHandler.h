//
// Created by Zakelis on 22/01/2018.
//

#ifndef R_TYPE_CreditsHANDLER_H
#define R_TYPE_CreditsHANDLER_H

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

class CreditsHandler {
private:

    //BACKGROUND AND MUSIC
    sf::Sprite CreditsBackgroundSprite;
    sf::Texture backgroundTexture;

    //BUTTON SYSTEM
    std::vector<std::string> buttonEffectsPaths;
    std::vector<std::shared_ptr<Button>> CreditsButtons;
    std::vector<std::function<void()>> functionsHandler;

public:
    CreditsHandler();
    ~CreditsHandler();
    void initCredits(const std::string &path);
    void drawCredits(sf::RenderWindow &App);
    void updateCredits(sf::Event &e, sf::RenderWindow &window);
    void determineButtonsPosition();
    void stopMusic();
    void startMusic();
};

#endif

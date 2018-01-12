//
// Created by Zakelis on 09/01/2018.
//

#ifndef R_TYPE_MENU_H
#define R_TYPE_MENU_H

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

class Menu {
private:

    //BACKGROUND AND MUSIC
    sf::Sprite menuBackgroundSprite;
    sf::Texture backgroundTexture;
    sf::Music music;

    //BUTTON SYSTEM
    std::vector<std::string> buttonEffectsPaths;
    std::vector<Button *> menuButtons;

    //MOUSE PARTICLES SYSTEM
    sf::Texture mouseParticleTexture;
    thor::UniversalEmitter particleEmitter;
    thor::ParticleSystem particleSystem;

    thor::ColorAnimation colorizer;
    thor::FadeAnimation fader;
    thor::PolarVector2f particleVelocity;

public:
    Menu();
    ~Menu();
    void initMenu(const std::string &path);
    void drawMenu(sf::RenderWindow &App);
    void updateMenu(sf::Event &e, sf::RenderWindow &window); // TODO : A APPELLER DANS LA BOUCLE DE JEU AVANT LE DRAW
    void determineButtonsPosition();
    void modifyParticleVelocity(int delta);
};


#endif //R_TYPE_MENU_H

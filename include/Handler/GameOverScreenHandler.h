//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_GAMEOVERSCREENHANDLER_H
#define R_TYPE_GAMEOVERSCREENHANDLER_H

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

class GameOverScreenHandler {
private:

    //BACKGROUND AND MUSIC
    sf::Sprite backgroundSprite;
    sf::Texture backgroundTexture;
    sf::Music music;

    // TEXT ON GAMEOVER SCREEN
    sf::Sprite textSprite;
    sf::Texture textTexture;

    //BUTTON SYSTEM
    std::vector<std::string> buttonEffectsPaths;
    std::vector<Button *> gameOverButtons;
    std::vector<std::function<void()>> functionsHandler;

public:
    GameOverScreenHandler();
    ~GameOverScreenHandler();
    void initGameOverScreen(const std::string &path);
    void drawGameOverScreen(sf::RenderWindow &App);
    void updateGameOverScreen(sf::Event &e, sf::RenderWindow &window); // TODO : A APPELLER DANS LA BOUCLE DE JEU AVANT LE DRAW
    void determineButtonsPosition();
    void stopMusic();
};

#endif //R_TYPE_GAMEOVERSCREENHANDLER_H

//
// Created by Zakelis on 16/01/2018.
//

#ifndef R_TYPE_WINSCREENHANDLER_H
#define R_TYPE_WINSCREENHANDLER_H

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

class WinScreenHandler
{
private:

    //BACKGROUND AND MUSIC
    Bg background;

    sf::Music music;

    // TEXT ON GAMEOVER SCREEN
    sf::Sprite textSprite;
    sf::Texture textTexture;

    //BUTTON SYSTEM
    std::vector<std::string> buttonEffectsPaths;
    std::vector<std::shared_ptr<Button>> winButtons;
    std::vector<std::function<void()>> functionsHandler;

public:
    WinScreenHandler();

    ~WinScreenHandler();

    void initWinScreen(const std::string &path);

    void drawWinScreen(sf::RenderWindow &App);
    void drawWinScreen(sf::RenderWindow &App, int opacity);

    void updateWinScreen(sf::Event &e, sf::RenderWindow &window);

    void determineButtonsPosition();

    void playMusic();

    void stopMusic();
    const Bg &getBackground() const;
};

#endif //R_TYPE_WINSCREENHANDLER_H

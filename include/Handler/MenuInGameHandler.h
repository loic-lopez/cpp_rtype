//
// Created by loic lopez on 17/01/2018.
//

#ifndef R_TYPE_MENUINGAMEHANDLER_H
#define R_TYPE_MENUINGAMEHANDLER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include <Button.h>

class MenuInGameHandler
{
private:
    //BUTTON SYSTEM
    std::vector<std::string> buttonEffectsPaths;
    std::vector<std::function<void()>> functionsHandler;
    std::vector<std::shared_ptr<Button>> menuInGameButtons;

public:

    MenuInGameHandler();

    ~MenuInGameHandler();

    void initMenuInGameHandler(const std::string &path);

    void drawMenuInGame(sf::RenderWindow &App);

    void updateMenuInGame(sf::Event &e, sf::RenderWindow &window);

    void determineButtonsPosition();
};


#endif //R_TYPE_MENUINGAMEHANDLER_H

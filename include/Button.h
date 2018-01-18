//
// Created by Zakelis on 11/01/2018.
//

#ifndef R_TYPE_BUTTON_H
#define R_TYPE_BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <Thor/Shapes.hpp>
#include <Thor/Graphics.hpp>
#include <functional>


namespace buttonState
{
    enum
    {
        NORMAL = 0,
        HOVERED = 1,
        CLICKED = 2
    };
};

class Button
{
public:
    explicit Button(std::vector<std::string> buttonEffectsPaths);

    ~Button();

    void setPosition(sf::Vector2f position);
    // TODO : REPRENDRE L'ALGO DE POSITION DANS LA CLASSE HUD DANS UNE BOUCLE ET APPELER SETPOSITION POUR CHAQUE BOUTONS ?
    void setSize(sf::Vector2f size);
    void setBackground();

    sf::Vector2f getPosition();
    sf::Vector2f getDimensions();
    sf::Vector2f getTextureSize();
    sf::Uint32  getState();
    void        setState(sf::Uint32 state);

    sf::RectangleShape buttonShape;

    std::function<void()> onClick;

    void update(sf::Event& e, sf::RenderWindow& window);

    void setButtonColor(const sf::Color &);

private:

    sf::Texture *textureNormal;
    sf::Texture *textureHovered;
    sf::Texture *textureClicked;

    sf::Vector2f buttonSize;
    sf::Vector2f buttonPosition;
    sf::Uint32 actualButtonState;

};

#endif //R_TYPE_BUTTON_H

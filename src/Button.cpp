//
// Created by Zakelis on 11/01/2018.
//

#include "Button.h"


Button::Button() {

}

Button::Button(std::vector<std::string> buttonEffectsPaths, sf::Vector2f position) {
    this->textureNormal->loadFromFile(buttonEffectsPaths[0]);
    this->textureHovered->loadFromFile(buttonEffectsPaths[1]);
    this->textureClicked->loadFromFile(buttonEffectsPaths[2]);
    this->buttonPosition.x = position.x;
    this->buttonPosition.y = position.y;
    this->actualButtonState = buttonState::NORMAL;
}

Button::~Button() {

}

void Button::setPosition(sf::Vector2f position) {
    this->buttonPosition = position;
}

void Button::setSize(sf::Vector2f size) {
    this->buttonSize.x = size.x;
    this->buttonSize.y = size.y;
}

void Button::setBackground() {

}

sf::Vector2f Button::getPosition() {
    return this->buttonPosition;
}

sf::Vector2f Button::getDimensions() {
    return sf::Vector2f(this->buttonShape.getGlobalBounds().width, this->buttonShape.getGlobalBounds().height);
}

sf::Uint32 Button::getState() {
    return this->actualButtonState;
}

void Button::update(sf::Event &e, sf::RenderWindow &window) {
    //perform updates for user mouse interactions
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    bool mouseInButton = mousePosition.x >= buttonShape.getPosition().x - buttonShape.getGlobalBounds().width / 2
                         && mousePosition.x <= buttonShape.getPosition().x + buttonShape.getGlobalBounds().width / 2
                         && mousePosition.y >= buttonShape.getPosition().y - buttonShape.getGlobalBounds().height / 2
                         && mousePosition.y <= buttonShape.getPosition().y + buttonShape.getGlobalBounds().height / 2;

    if (e.type == sf::Event::MouseMoved) {
        if (mouseInButton) {
            actualButtonState = buttonState::HOVERED;
        } else {
            actualButtonState = buttonState::NORMAL;
        }
    }

    if (e.type == sf::Event::MouseButtonPressed) {
        switch (e.mouseButton.button) {
            case sf::Mouse::Left: {
                if (mouseInButton) {
                    actualButtonState = buttonState::CLICKED;
                } else {
                    actualButtonState = buttonState::NORMAL;
                }
            }
            default:
                break;
        }
    }

    if (e.type == sf::Event::MouseButtonReleased) {
        switch (e.mouseButton.button) {
            case sf::Mouse::Left: {
                if (mouseInButton) {
                    actualButtonState = buttonState::HOVERED;
                } else {
                    actualButtonState = buttonState::NORMAL;
                }
            }
            default:
                break;
        }
    }

    switch (actualButtonState) {
        case buttonState::NORMAL: {
            this->buttonShape.setTexture(this->textureNormal);
            break;
        }

        case buttonState::HOVERED: {
            this->buttonShape.setTexture(this->textureHovered);
            break;
        }

        case buttonState::CLICKED: {
            this->buttonShape.setTexture(this->textureClicked);
            break;
        }
        default:
            break;
    }
}


//
// Created by Zakelis on 11/01/2018.
//

#include "Button.h"


Button::Button(std::vector<std::string> buttonEffectsPaths, std::function<void()> onClick) {
    this->textureNormal = new sf::Texture;
    this->textureHovered = new sf::Texture;
    this->textureClicked = new sf::Texture;
    this->textureNormal->loadFromFile(buttonEffectsPaths[0]);
    this->textureHovered->loadFromFile(buttonEffectsPaths[1]);
    this->textureClicked->loadFromFile(buttonEffectsPaths[2]);
    std::cout << "Textures well applied" << std::endl;
    this->actualButtonState = buttonState::NORMAL;
    this->buttonShape.setTexture(this->textureNormal);
    this->buttonShape.setSize(this->getTextureSize());
    this->onClick = onClick;
}

Button::Button(std::vector<std::string> buttonEffectsPaths) {
    this->textureNormal = new sf::Texture;
    this->textureHovered = new sf::Texture;
    this->textureClicked = new sf::Texture;
    this->textureNormal->loadFromFile(buttonEffectsPaths[0]);
    this->textureHovered->loadFromFile(buttonEffectsPaths[1]);
    this->textureClicked->loadFromFile(buttonEffectsPaths[2]);
    std::cout << "Textures well applied" << std::endl;
    this->actualButtonState = buttonState::NORMAL;
    this->buttonShape.setTexture(this->textureNormal);
    this->buttonShape.setSize(this->getTextureSize());
}

Button::~Button() {

}

void Button::setPosition(sf::Vector2f position) {
    this->buttonPosition = position;
    this->buttonShape.setOrigin(this->buttonPosition);
}

void Button::setSize(sf::Vector2f size) {

}

void Button::setBackground() {

}

sf::Vector2f Button::getPosition() {
    return this->buttonPosition;
}

sf::Vector2f Button::getDimensions() {
    return sf::Vector2f(this->buttonShape.getGlobalBounds().width, this->buttonShape.getGlobalBounds().height);
}

sf::Vector2f Button::getTextureSize() {
    return sf::Vector2f(this->buttonShape.getTexture()->getSize().x, this->buttonShape.getTexture()->getSize().y);
}

sf::Uint32 Button::getState() {
    return this->actualButtonState;
}

void Button::update(sf::Event &e, sf::RenderWindow &window) {
    //perform updates for user mouse interactions
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    bool mouseInButton = mousePosition.x >= buttonShape.getPosition().x
                         && mousePosition.x <= buttonShape.getPosition().x + buttonShape.getGlobalBounds().width
                         && mousePosition.y >= buttonShape.getPosition().y
                         && mousePosition.y <= buttonShape.getPosition().y + buttonShape.getGlobalBounds().height;

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
            std::cout << "Button Clicked." << std::endl;
            this->buttonShape.setTexture(this->textureClicked);
            this->onClick();
            break;
        }
        default:
            break;
    }
}




//
// Created by Zakelis on 22/01/2018.
//

#include <Core/CreditsCore.h>

CreditsCore CreditsCore::m_instance = CreditsCore();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
CreditsCore::CreditsCore()
{
    this->Credits.initCredits("credits");
}

CreditsCore::~CreditsCore()
{
}

CreditsCore &CreditsCore::Instance()
{
    return m_instance;
}

/************************************************* MAINLOOP *************************************************/
void CreditsCore::start()
{
    sf::Event Event{};

    this->Credits.startMusic();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::CREDITS)
    {
        this->Credits.updateCredits(Event, *WindowProperties::App);
        this->Credits.drawCredits(*WindowProperties::App);
        this->eventHandler(Event);
        WindowProperties::App->display();
    }
    this->Credits.stopMusic();
}

void CreditsCore::eventHandler(sf::Event &event)
{
    while (WindowProperties::App->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                WindowProperties::gameState = GameState::CLOSE;
                this->Credits.stopMusic();
                break;
            }

            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape) {
                    WindowProperties::gameState = GameState::CLOSE;
                    this->Credits.stopMusic();
                }

                break;
            }
            default:
                break;
        }
    }
}
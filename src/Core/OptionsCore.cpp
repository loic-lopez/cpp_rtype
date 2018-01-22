//
// Created by Zakelis on 22/01/2018.
//

#include <Core/OptionsCore.h>

OptionsCore OptionsCore::m_instance = OptionsCore();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
OptionsCore::OptionsCore()
{
    this->options.initOptions("options");
}

OptionsCore::~OptionsCore()
{
}

OptionsCore &OptionsCore::Instance()
{
    return m_instance;
}

/************************************************* MAINLOOP *************************************************/
void OptionsCore::start()
{
    sf::Event Event{};

    this->options.startMusic();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::OPTIONS)
    {
        this->options.updateOptions(Event, *WindowProperties::App);
        this->options.drawOptions(*WindowProperties::App);
        this->eventHandler(Event);
        WindowProperties::App->display();
    }
    this->options.stopMusic();
}

void OptionsCore::eventHandler(sf::Event &event)
{
    while (WindowProperties::App->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                WindowProperties::gameState = GameState::CLOSE;
                this->options.stopMusic();
                break;
            }

            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape) {
                    WindowProperties::gameState = GameState::CLOSE;
                    this->options.stopMusic();
                }

                break;
            }
            default:
                break;
        }
    }
}
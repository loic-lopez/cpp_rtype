//
// Created by Zàkelis on 30/11/2017.
//

#include <Core/MenuCore.hpp>

MenuCore MenuCore::m_instance = MenuCore();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
MenuCore::MenuCore()
{
    this->menu.initMenu("menu");
}

MenuCore::~MenuCore()
{
}

MenuCore &MenuCore::Instance()
{
    return m_instance;
}

/************************************************* MAINLOOP *************************************************/
void MenuCore::start()
{
    sf::Event Event{};

    this->menu.startMusic();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::MENU)
    {
        std::cout << "GAMESTATE VIA MENU : " <<(int) WindowProperties::gameState << std::endl;
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17)
        {
            clock.restart();
            this->menu.updateMenu(Event, *WindowProperties::App);
            this->menu.drawMenu(*WindowProperties::App);
            this->eventHandler(Event);
            WindowProperties::App->display();
        }
    }
    this->menu.stopMusic();
}

void MenuCore::eventHandler(sf::Event &event)
{
    while (WindowProperties::App->pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::Closed:
            {
                WindowProperties::gameState = GameState::CLOSE;
                this->menu.stopMusic();
                break;
            }

            case sf::Event::KeyPressed:
            {
                if (event.key.code == sf::Keyboard::Escape) {
                    WindowProperties::gameState = GameState::CLOSE;
                    this->menu.stopMusic();
                }

                break;
            }
            default:
                break;
        }
    }
}
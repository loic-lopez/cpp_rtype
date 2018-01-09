//
// Created by Eric on 30/11/2017.
//

#include "Game.h"

Game Game::m_instance = Game();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
Game::Game()
{

}

Game::~Game()
{
    while (bulletsEnemy.size() != 0)
    {
        delete (bulletsEnemy[0]);
        bulletsEnemy.erase(bulletsEnemy.begin());
    }
    while (entities.size() != 0)
    {
        delete (entities[0]);
        entities.erase(entities.begin());
    }
}

Game &Game::Instance()
{
    return m_instance;
}

/************************************************* PLAYER CONTROLLER *************************************************/
void Game::changeOrientation(Orientation orientation)
{
    level.changeOrientation(orientation);
    play.changeOrientation(orientation);
    for (size_t i = 0; i < bulletsEnemy.size(); i++)
        bulletsEnemy[i]->changeOrientation(orientation);
    for (size_t i = 0; i < bulletsAllied.size(); i++)
        bulletsAllied[i]->changeOrientation(orientation);
    for (size_t i = 0; i < entities.size(); i++)
        entities[i]->changeOrientation(orientation);
}

void Game::controller()
{
    sf::Keyboard keyboard;

    if (keyboard.isKeyPressed(sf::Keyboard::Up))
        play.move(sf::Vector2f(0, -1));
    if (keyboard.isKeyPressed(sf::Keyboard::Down))
        play.move(sf::Vector2f(0, 1));
    if (keyboard.isKeyPressed(sf::Keyboard::Left))
        play.move(sf::Vector2f(-1, 0));
    if (keyboard.isKeyPressed(sf::Keyboard::Right))
        play.move(sf::Vector2f(1, 0));
    if (keyboard.isKeyPressed(sf::Keyboard::Space))
        play.shoot();
    if (keyboard.isKeyPressed(sf::Keyboard::Escape))
        gameState = GameState::CLOSE;
    if (keyboard.isKeyPressed(sf::Keyboard::A))
        changeOrientation(Orientation::HORIZONTAL);
    if (keyboard.isKeyPressed(sf::Keyboard::Z))
        changeOrientation(Orientation::VERTICAL);
}

void Game::XboxController()
{
    float posX;
    float posY;
    sf::Vector2f speed;


    posX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    posY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    speed = sf::Vector2f((posX / 100), (posY / 100));
    play.move(speed);
    if (sf::Joystick::isButtonPressed(0, 0))
    {
        play.shoot();
    }
    if (sf::Joystick::isButtonPressed(0, 1))
    {
        std::cout << "B" << std::endl;
    }
    if (sf::Joystick::isButtonPressed(0, 2))
    {
        std::cout << "zqdqzd" << std::endl;
    }
    if (sf::Joystick::isButtonPressed(0, 3))
    {
        std::cout << "Y" << std::endl;

    }
    if (sf::Joystick::isButtonPressed(0, 4))
    {
        std::cout << "l1" << std::endl;

    }
    if (sf::Joystick::isButtonPressed(0, 5))
    {
        std::cout << "R2" << std::endl;

    }
    if (sf::Joystick::isButtonPressed(0, 6))
    {
        std::cout << "Back" << std::endl;

    }
    if (sf::Joystick::isButtonPressed(0, 7))
    {
        std::cout << "start" << std::endl;

    }
    if (sf::Joystick::isButtonPressed(0, 8))
    {
        std::cout << "L3" << std::endl;

    }
}


/************************************************* ENTITIES *************************************************/

void Game::updateEntities()
{
    play.updatePos();
    for (size_t i = 0; i < entities.size(); i++)
    {
        this->entities[i]->updatePos();
        this->entities[i]->shoot();
    }
}

void Game::updateAlliedBullet()
{
    for (size_t i = 0; i < this->bulletsAllied.size(); i++)
    {
        if (!bulletsAllied[i]->outOfBounds())
        {
            delete (this->bulletsAllied[i]);
            this->bulletsAllied.erase(this->bulletsAllied.begin() + i);
            i--;
        }
        else
            this->bulletsAllied[i]->updatePos();
    }
    for (size_t i = 0; i < this->bulletsEnemy.size(); i++)
    {
        if (!bulletsEnemy[i]->outOfBounds())
        {
            delete (this->bulletsEnemy[i]);
            this->bulletsEnemy.erase(this->bulletsEnemy.begin() + i);
            i--;
        }
        else
            this->bulletsEnemy[i]->updatePos();
    }
}

/************************************************* MAINLOOP *************************************************/
void Game::start()
{
    gameState = GameState::GAME;
    level.initLvl("lvl1");
    entities.push_back(new Enemy(EnemyType::BASIC_A));
    play = Player();
    bulletsEnemy.reserve(100000);
    sf::RenderWindow App(sf::VideoMode(WindowProperties::WIN_WIDTH, WindowProperties::WIN_HEIGHT), "R-TYPE",
                         sf::Style::Fullscreen);
    App.setVerticalSyncEnabled(true);
    while (App.isOpen() && gameState != GameState::CLOSE)
    {
        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 17)
        {
            clock.restart();

            if (play.getGameMovementMode() == ControlType::KEYBOARD)
                controller();
            else if (play.getGameMovementMode() == ControlType::XBOXCONTROLLER)
                XboxController();

            updateEntities();
            updateAlliedBullet();
            drawAll(App);
            sf::Event Event;
            while (App.pollEvent(Event))
            {
                if (Event.type == sf::Event::Closed)
                    gameState = GameState::CLOSE;
            }
            App.display();
        }
    }
    gameState = GameState::CLOSE;
    App.close();
}

/************************************************* DRAW *************************************************/
void Game::drawAll(sf::RenderWindow &App)
{
    level.drawLvl(App);
    for (size_t i = 0; i < bulletsEnemy.size(); i++)
    {
        bulletsEnemy[i]->drawSprite(App);
    }
    for (size_t i = 0; i < bulletsAllied.size(); i++)
    {
        bulletsAllied[i]->drawSprite(App);
    }
    for (size_t i = 0; i < entities.size(); i++)
    {
        entities[i]->drawSprite(App);
    }
    play.drawSprite(App);
}

void Game::lock()
{
    mutex.lock();
}

void Game::unlock()
{
    mutex.unlock();
}

void Game::addBullet(IEntity *newBullet)
{
    if (((Bullet *) newBullet)->getSide() == Side::ENEMY)
        bulletsEnemy.push_back(newBullet);
    else
        bulletsAllied.push_back(newBullet);
}
//
// Created by loic lopez on 12/01/2018.
//

#include <Handler/GameHandler.h>

GameHandler GameHandler::m_instance = GameHandler();

/************************************************* CONSTRUCTOR DESTRUCTOR *************************************************/
GameHandler::GameHandler()
{
    level.initLvl("lvl1");
    hud.initHud("hud");
}

GameHandler::~GameHandler()
{
    while (!bulletsEnemy.empty())
    {
        delete (bulletsEnemy[0]);
        bulletsEnemy.erase(bulletsEnemy.begin());
    }
    while (!entities.empty())
    {
        delete (entities[0]);
        entities.erase(entities.begin());
    }
}

GameHandler &GameHandler::Instance()
{
    return m_instance;
}

/************************************************* PLAYER CONTROLLER *************************************************/
void GameHandler::changeOrientation(Orientation orientation)
{
    level.changeOrientation(orientation);
    player.changeOrientation(orientation);
    for (auto &bullet : bulletsEnemy)
        bullet->changeOrientation(orientation);
    for (auto &bullet : bulletsAllied)
        bullet->changeOrientation(orientation);
    for (auto &entity : entities)
        entity->changeOrientation(orientation);
}

void GameHandler::controller()
{
    sf::Keyboard keyboard;

    if (keyboard.isKeyPressed(sf::Keyboard::LShift))
    {
        if (keyboard.isKeyPressed(sf::Keyboard::Z))
            player.move(sf::Vector2f(0, -2));
        if (keyboard.isKeyPressed(sf::Keyboard::S))
            player.move(sf::Vector2f(0, 2));
        if (keyboard.isKeyPressed(sf::Keyboard::Q))
            player.move(sf::Vector2f(-2, 0));
        if (keyboard.isKeyPressed(sf::Keyboard::D))
            player.move(sf::Vector2f(2, 0));
    }
    else
    {
        if (keyboard.isKeyPressed(sf::Keyboard::Z))
            player.move(sf::Vector2f(0, -1));
        if (keyboard.isKeyPressed(sf::Keyboard::S))
            player.move(sf::Vector2f(0, 1));
        if (keyboard.isKeyPressed(sf::Keyboard::Q))
            player.move(sf::Vector2f(-1, 0));
        if (keyboard.isKeyPressed(sf::Keyboard::D))
            player.move(sf::Vector2f(1, 0));
    }

    if (keyboard.isKeyPressed(sf::Keyboard::Space))
        player.shoot();
    if (keyboard.isKeyPressed(sf::Keyboard::Escape))
        WindowProperties::gameState = GameState::CLOSE;/*
    if (keyboard.isKeyPressed(sf::Keyboard::A))
        changeOrientation(Orientation::HORIZONTAL);
    if (keyboard.isKeyPressed(sf::Keyboard::Z))
        changeOrientation(Orientation::VERTICAL);*/
}

void GameHandler::XboxController()
{
    float posX;
    float posY;
    sf::Vector2f speed;


    posX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    posY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    speed = sf::Vector2f((posX / 100), (posY / 100));
    player.move(speed);
    if (sf::Joystick::isButtonPressed(0, 0))
    {
        player.shoot();
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

void GameHandler::updateEntities()
{
    player.updatePos();
    for (size_t i = 0; i < entities.size(); i++)
    {
        this->entities[i]->updatePos();
        this->entities[i]->shoot();
    }
}

void GameHandler::updateAlliedBullet()
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
void GameHandler::start()
{
    entities.push_back(new Enemy(EnemyType::BASIC_A));
    bulletsEnemy.reserve(100000);

    if (level.getMusicStatus() == sf::SoundSource::Paused
        || level.getMusicStatus() == sf::SoundSource::Stopped)
        level.setMusicStatus("play");

    sf::Event Event;
    sf::Time elapsed;
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::GAME)
    {
        elapsed = clock.getElapsedTime();
        cloque = inv.getElapsedTime();
        if (elapsed.asMilliseconds() > 17)
        {
            clock.restart();
            if (player.getGameMovementMode() == ControlType::KEYBOARD)
                controller();
            else if (player.getGameMovementMode() == ControlType::XBOXCONTROLLER)
                XboxController();

            updateEntities();
            updateAlliedBullet();
            checkEntitiesBoxes();
            drawAll(*WindowProperties::App);
            while (WindowProperties::App->pollEvent(Event))
            {
                switch (Event.type)
                {
                    case sf::Event::Closed:
                    {
                        WindowProperties::gameState = GameState::CLOSE;
                        break;
                    }
                    case sf::Event::KeyPressed:
                    {
                        if (Event.key.code == sf::Keyboard::Escape)
                            WindowProperties::gameState = GameState::CLOSE;
                        break;
                    }
                    default:
                        break;
                }
            }
            WindowProperties::App->display();
        }
    }
    /*level1.start();
    level2.start();*/
    level.setMusicStatus("stop");
}

/************************************************* DRAW *************************************************/
void GameHandler::drawAll(sf::RenderWindow &App)
{
    level.drawLvl(App);
    hud.drawHud(App);
    for (auto &bullet : bulletsEnemy)
        bullet->drawSprite(App);
    for (auto &bullet : bulletsAllied)
        bullet->drawSprite(App);
    for (auto &entity : entities)
        entity->drawSprite(App);
    player.drawSprite(App);
}

void GameHandler::lock()
{
    mutex.lock();
}

void GameHandler::unlock()
{
    mutex.unlock();
}

void GameHandler::addBullet(IEntity *newBullet)
{
    if (((Bullet *) newBullet)->getSide() == Side::ENEMY)
        bulletsEnemy.push_back(newBullet);
    else
        bulletsAllied.push_back(newBullet);
}

void GameHandler::checkEntitiesBoxes()
{
    for (auto it = bulletsAllied.begin(); it < bulletsAllied.end(); ++it)
        if (!entities.empty())
            for (auto enemy = entities.begin(); enemy < entities.end(); ++enemy)
                if ((*it)->getHitBox().intersects((*enemy)->getHitBox()))
                {
                    if ((*enemy)->getType() == Textures::ENEMY1)
                        entities.erase(enemy);
                    bulletsAllied.erase(it);
                }

    for (auto it = bulletsEnemy.begin(); it != bulletsEnemy.end(); ++it)
    {
        if ((*it)->getHitBox().intersects(player.getHitBox()))
        {
            if (this->player.getHp() > 0 && cloque.asMilliseconds() > 1500)
            {
                inv.restart();
                this->player.setHp(*this->player.getHp() - 1);
                bulletsEnemy.erase(it);
            }


        }

    }
}

Player &GameHandler::getPlayer()
{
    return this->player;
}

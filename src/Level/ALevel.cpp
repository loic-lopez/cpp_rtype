//
// Created by loic lopez on 16/01/2018.
//

#include <Level/ALevel.h>
#include <Handler/GameHandler.h>

ALevel::ALevel() : player(GameHandler::Instance().getPlayer()), hud(GameHandler::Instance().getHud())
{
}

ALevel::~ALevel()
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

void ALevel::controller()
{
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
    {
        WindowProperties::gameState = GameState::CLOSE;
    }
}

void ALevel::XboxController()
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

void ALevel::drawAll(sf::RenderWindow &App)
{
    this->drawLvl(App);
    hud.drawHud(App);
    for (auto &bullet : bulletsEnemy)
        bullet->drawSprite(App);
    for (auto &bullet : bulletsAllied)
        bullet->drawSprite(App);
    for (auto &entity : entities)
        entity->drawSprite(App);
    player.drawSprite(App);
}

void ALevel::updateAlliedBullet()
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

void ALevel::updateEntities()
{
    player.updatePos();
    for (size_t i = 0; i < entities.size(); i++)
    {
        this->entities[i]->updatePos();
        this->entities[i]->shoot();
    }
}


void ALevel::addBullet(IEntity *newBullet)
{
    if (((Bullet *) newBullet)->getSide() == Side::ENEMY)
        bulletsEnemy.push_back(newBullet);
    else
        bulletsAllied.push_back(newBullet);
}

void ALevel::checkEntitiesBoxes()
{
    for (auto it = bulletsAllied.begin(); it < bulletsAllied.end(); ++it)
        if (!entities.empty())
            for (auto enemy = entities.begin(); enemy < entities.end(); ++enemy)
            {
                if ((*it)->getHitBox().intersects((*enemy)->getHitBox()))
                {

                    if ((*enemy)->getType() == Textures::ENEMY1)
                        entities.erase(enemy);
                    else if ((*enemy)->getType() == Textures::ENEMY2)
                    {
                        if ((*enemy)->getHp() <= 0)
                            entities.erase(enemy);
                        else
                        (*enemy)->setHp((*enemy)->getHp() - 1);
                    }
                    bulletsAllied.erase(it);
                    break;
                }
            }

    for (auto it = bulletsEnemy.begin(); it != bulletsEnemy.end(); ++it)
    {
        if ((*it)->getHitBox().intersects(player.getHitBox()))
        {
            if (this->player.getHp() > 0 && invulnerabilityTime.asMilliseconds() > 1500)
            {
                inv.restart();
                this->player.setHp(this->player.getHp() - 1);
                bulletsEnemy.erase(it);
                break;
            }
        }
    }
}

void ALevel::initLvl(const std::string &path)
{
    back.flushLayers();
    Parsing::loadCSV(path, [&, this](std::string const &path, int const &i)
    {
        if (path.substr(path.find_last_of('.') + 1) == "ogg")
        {
            music.openFromFile(path);
            music.setLoop(true);
        }
        else if (path.substr(path.find_last_of('.') + 1) == "png" ||
                 (path.substr(path.find_last_of('.') + 1) == "jpg"))
            this->back.addLayer(path, i);
    });
}

void ALevel::drawLvl(sf::RenderWindow &App)
{
    back.drawBackground(App);
}

void ALevel::pollEvent(sf::Event &Event)
{
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
}

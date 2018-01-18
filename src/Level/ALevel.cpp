//
// Created by loic lopez on 16/01/2018.
//

#include <Core/GameCore.h>
#include <Level/ALevel.h>

ALevel::ALevel() : player(GameHandler::Instance().getPlayer()), hud(GameHandler::Instance().getHud())
{
    this->isGameLost = false;
    this->transitionToGameOverScreenTexture.loadFromFile("./ressources/gameOverScreen/game_over_background.jpg");
    this->transitionToGameOverScreenSprite.setTexture(this->transitionToGameOverScreenTexture);
    float scaleX;
    float scaleY;
    scaleX = (float) WindowProperties::WIN_WIDTH / this->transitionToGameOverScreenSprite.getGlobalBounds().width;
    scaleY = (float) WindowProperties::WIN_HEIGHT / this->transitionToGameOverScreenSprite.getGlobalBounds().height;
    this->transitionToGameOverScreenSprite.scale(scaleX, scaleY);
    this->baseSoundAttenuationOnDeathPercentageDecreasing = 0.5;
    this->soundAttenuationOnDeath = 100;
    this->baseFadeOpacityPercentageIncreasing = 1.25;
    this->floatFadeOpacity = 0;
    this->fadeOpacity = 0;
    phaseMax  = 3;
    phase = 0;
    changePhase = false;
}

ALevel::~ALevel()
{
}

void ALevel::controller()
{
    if (keyboard.isKeyPressed(sf::Keyboard::LShift))
    {
        if (keyboard.isKeyPressed(sf::Keyboard::Z))
            player->move(sf::Vector2f(0, -2));
        if (keyboard.isKeyPressed(sf::Keyboard::S))
            player->move(sf::Vector2f(0, 2));
        if (keyboard.isKeyPressed(sf::Keyboard::Q))
            player->move(sf::Vector2f(-2, 0));
        if (keyboard.isKeyPressed(sf::Keyboard::D))
            player->move(sf::Vector2f(2, 0));
    }
    else
    {
        if (keyboard.isKeyPressed(sf::Keyboard::Z))
            player->move(sf::Vector2f(0, -1));
        if (keyboard.isKeyPressed(sf::Keyboard::S))
            player->move(sf::Vector2f(0, 1));
        if (keyboard.isKeyPressed(sf::Keyboard::Q))
            player->move(sf::Vector2f(-1, 0));
        if (keyboard.isKeyPressed(sf::Keyboard::D))
            player->move(sf::Vector2f(1, 0));
    }


    if (keyboard.isKeyPressed(sf::Keyboard::Space))
        player->shoot();
}

void ALevel::XboxController()
{
    float posX;
    float posY;
    sf::Vector2f speed;


    posX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    posY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    speed = sf::Vector2f((posX / 100), (posY / 100));
    player->move(speed);
    if (sf::Joystick::isButtonPressed(0, 0))
    {
        player->shoot();
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
    for (auto &bullet : bulletsEnemy)
        bullet->drawSprite(App);
    for (auto &bullet : bulletsAllied)
        bullet->drawSprite(App);
    for (auto &entity : ennemies)
        entity->drawSprite(App);
    player->drawSprite(App);
    hud.drawHud(App);
    if (this->isGameLost)
        App.draw(this->transitionToGameOverScreenSprite);
}

void ALevel::updateAlliedBullet()
{
    for (size_t i = 0; i < this->bulletsAllied.size(); i++)
    {
        if (!bulletsAllied[i]->outOfBounds())
        {
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
            this->bulletsEnemy.erase(this->bulletsEnemy.begin() + i);
            i--;
        }
        else
            this->bulletsEnemy[i]->updatePos();
    }
}

void ALevel::updateEntities()
{
    player->updatePos();
    for (size_t i = 0; i < ennemies.size(); i++)
    {
        this->ennemies[i]->updatePos();
        this->ennemies[i]->shoot();
    }
}

void ALevel::addBullet(IEntity *newBullet)
{
    if (((Bullet *) newBullet)->getSide() == Side::ENEMY)
        bulletsEnemy.push_back(std::shared_ptr<IEntity>(newBullet));
    else
        bulletsAllied.push_back(std::shared_ptr<IEntity>(newBullet));
}

void ALevel::checkEntitiesBoxes()
{
    for (auto it = bulletsAllied.begin(); it < bulletsAllied.end(); ++it)
        if (!ennemies.empty())
            for (auto enemy = ennemies.begin(); enemy < ennemies.end(); ++enemy)
            {
                if ((*it)->getHitBox().intersects((*enemy)->getHitBox()))
                {
                    if ((*enemy)->getType() == Textures::ENEMY1)
                        ennemies.erase(enemy);
                    else if ((*enemy)->getType() == Textures::ENEMY2)
                    {
                        if ((*enemy)->getHp() <= 0)
                            ennemies.erase(enemy);
                        else
                            (*enemy)->setHp((*enemy)->getHp() - 1);
                    }
                    else if ((*enemy)->getType() == Textures::BOSS1)
                    {
                        if ((*enemy)->getHp() <= 0)
                            ennemies.erase(enemy);
                        else
                            (*enemy)->setHp((*enemy)->getHp() - 1);
                    }
                    bulletsAllied.erase(it);
                    break;
                }
            }

    for (auto it = bulletsEnemy.begin(); it != bulletsEnemy.end(); ++it)
    {
        if ((*it)->getHitBox().intersects(player->getHitBox()))
        {
            if (this->player->getHp() > 0 && invulnerabilityTime.asMilliseconds() > 1500)
            {
                inv.restart();
                this->player->setHp(this->player->getHp() - 1);
                GameHandler::Instance().getHud().takeDamage();
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
            case sf::Event::KeyReleased:
            {
                if (Event.key.code == sf::Keyboard::Escape)
                {
                    GameCore::Instance().getMenuInGameCore().setPreviousGameState(currentGameLevel);
                    WindowProperties::gameState = GameState::INGAMEMENU;
                    GameCore::Instance().getMenuInGameCore().start();
                }
            }
            default:
                break;
        }
    }
    if (player->getHp() != 0)
    {
        if (player->getGameMovementMode() == ControlType::KEYBOARD)
            controller();
        else if (player->getGameMovementMode() == ControlType::XBOXCONTROLLER)
            XboxController();
    }
    else
    {
        this->isGameLost = true;
        this->soundAttenuationOnDeath -= this->baseSoundAttenuationOnDeathPercentageDecreasing;
        this->music.setVolume(this->soundAttenuationOnDeath);
        this->floatFadeOpacity += this->baseFadeOpacityPercentageIncreasing;
        this->fadeOpacity = int(std::round(this->floatFadeOpacity));
        if (this->fadeOpacity >= 255)
            WindowProperties::gameState = GameState::GAMEOVER;
        else
            this->transitionToGameOverScreenSprite.setColor(sf::Color(255, 255, 255, this->fadeOpacity));
    }
}

void ALevel::mainLoop(/*td::function<void(short)> generator*/)
{
    sf::Event Event;
    sf::Time elapsed;

    while (WindowProperties::App->isOpen() && WindowProperties::gameState == currentGameLevel)
    {
        elapsed = clock.getElapsedTime();
        invulnerabilityTime = inv.getElapsedTime();
        if (elapsed.asMilliseconds() > 17)
        {
            clock.restart();
            //enemiesGenerator(phase);
            updateEntities();
            updateAlliedBullet();
            checkEntitiesBoxes();
            drawAll(*WindowProperties::App);
            pollEvent(Event);
            WindowProperties::App->display();
        }
    }
}

void ALevel::generateEnemies(EnemyType type, int number, EnemyType type2, int number2)
{
   if (changePhase)
   {
       if (ennemies.empty())
       {
           phase++;
           changePhase = false;
       }
   }
   else
   {
       if (phase < phaseMax)
       {
           for (int i = 0; i < number; i++)
               ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(type)));
           if (type2 != EnemyType::NONE)
               for (int i = 0; i < number2; i++)
                   ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(type2)));
                changePhase = true;
       }
       else if (phase == phaseMax)
       {
           ennemies.push_back(std::shared_ptr<IEntity>(new Enemy(EnemyType::BOSS_A)));
           phase++;
       }
   }
}

void ALevel::enemiesGenerator(short phase)
{
    this->phases.at(phase)();
}


//
// Created by loic lopez on 16/01/2018.
//

#include <Core/GameCore.h>

ALevel::ALevel() : player(GameHandler::Instance().getPlayer()), hud(GameHandler::Instance().getHud())
{
    this->isGameLost = false;
    this->baseSoundAttenuationOnDeathPercentageDecreasing = 0.5;
    this->soundAttenuationOnDeath = 100;
    this->baseFadeOpacityPercentageIncreasing = 1.25;
    this->floatFadeOpacity = 0;
    this->fadeOpacity = 0;
    phase = 0;
    changePhase = false;
    playerBlinking = false;
    win = false;
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
    for (auto &power : powerUps)
        power->drawSprite(App);
    if (!playerBlinking)
        player->drawSprite(App);
    else
        player->drawSpriteBlinking();
    hud.drawHud(App);
}

void ALevel::updateAlliedBullet()
{
    for (auto it = bulletsAllied.begin(); it < bulletsAllied.end(); ++it)
    {
        if (!(*it)->outOfBounds())
            this->bulletsAllied.erase(it);
        else
            (*it)->updatePos();
    }
    for (auto it = bulletsEnemy.begin(); it < bulletsEnemy.end(); ++it)
    {
        if (!(*it)->outOfBounds())
            this->bulletsEnemy.erase(it);
        else
            (*it)->updatePos();
    }
}

void ALevel::updateEntities()
{
    sf::Vector2f    pos;

    player->updatePos();
    for (size_t i = 0; i < ennemies.size(); i++)
    {
        this->ennemies[i]->updatePos();
        this->ennemies[i]->shoot();
    }
    for (auto it = this->powerUps.begin(); it < this->powerUps.end(); ++it)
    {
        pos = (*it)->getPos();
        if (pos.x <= 0)
        {
            this->powerUps.erase(it);
            break;
        }
        (*it)->updatePos();
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
                if ((*it)->getHitBox().intersects((*enemy)->getHitBox()) && !isGameLost)
                {
                    if ((*enemy)->getHp() > 0)
                        (*enemy)->setHp((*enemy)->getHp() - 1);

                    if ((*enemy)->getHp() <= 0)
                    {
                        player->setScore(player->getScore() + (*enemy)->getReward());
                        ennemies.erase(enemy);
                    }
                    bulletsAllied.erase(it);
                    break;
                }
            }

    if (playerBlinking && invulnerabilityTime.asMilliseconds() > 1500)
    {
        player->setBlinkingValue(255);
        playerBlinking = false;
    }

    for (auto it = bulletsEnemy.begin(); it != bulletsEnemy.end(); ++it)
    {
        if ((*it)->getHitBox().intersects(player->getHitBox()) && !isGameLost && !win)
        {
            if (this->player->getHp() > 0 && invulnerabilityTime.asMilliseconds() > 1500)
            {
                playerBlinking = !playerBlinking;
                inv.restart();
                this->player->setHp(this->player->getHp() - 1);
                GameHandler::Instance().getHud().takeDamage();
                bulletsEnemy.erase(it);
                break;
            }
        }
    }
    for (auto it = powerUps.begin(); it < powerUps.end(); ++it)
    {
        if ((*it)->getHitBox().intersects(player->getHitBox()) && !isGameLost && !win)
        {
            if ((*it)->getType() == Textures::LIFEUP)
            {
                if (this->player->getHp() < WindowProperties::MAX_PLAYER_HP)
                {
                    this->player->setHp(player->getHp() + 1);
                    GameHandler::Instance().getHud().addHearth();
                }
            }
            else if ((*it)->getType() == Textures::STRAIGHT)
            {
                if (this->player->getWeapon() == WeaponType::STRAIGHT)
                    player->weaponUp();
                else
                    player->setWeapon(WeaponType::STRAIGHT, 10, 1);
            }
            else
            {
                if (this->player->getWeapon() == WeaponType::SPREAD)
                    player->weaponUp();
                else
                    player->setWeapon(WeaponType::SPREAD, 10, 1);
            }
            powerUps.erase(it);
            break;
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
                    GameCore::Instance().getMenuInGameCore().start();
                }
            }
            default:
                break;
        }
    }

    if (win)
    {
        this->soundAttenuationOnDeath -= this->baseSoundAttenuationOnDeathPercentageDecreasing;
        this->music.setVolume(this->soundAttenuationOnDeath);
        this->floatFadeOpacity += this->baseFadeOpacityPercentageIncreasing;
        this->fadeOpacity = int(std::round(this->floatFadeOpacity));
        if (this->fadeOpacity >= 255)
        {
            WindowProperties::gameState = GameState::WIN;
        }
        else
            GameCore::Instance().getWinScreenCore().getWinScreen().drawWinScreen(*WindowProperties::App, fadeOpacity);
    }
    else if (player->getHp() != 0)
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
        {
            GameOverScreenCore::Instance().setPreviousGameState(WindowProperties::gameState);
            WindowProperties::gameState = GameState::GAMEOVER;
        }
        else
            GameOverScreenCore::Instance().getGameOverScreen().drawGameOverScreen(*WindowProperties::App, fadeOpacity);

    }
}

void ALevel::mainLoop()
{
    sf::Event Event;
    sf::Time elapsed;
    sf::Time powerUp;

    while (WindowProperties::App->isOpen() && WindowProperties::gameState == currentGameLevel)
    {
        elapsed = clock.getElapsedTime();
        powerUp = cloque.getElapsedTime();
        invulnerabilityTime = inv.getElapsedTime();
        if (powerUp.asSeconds() > 10)
        {
            cloque.restart();
            this->powerUps.emplace_back(new PowerUp());
        }
        if (elapsed.asMilliseconds() > 17)
        {
            WindowProperties::App->display();
            clock.restart();
            updateEntities();
            updateAlliedBullet();
            checkEntitiesBoxes();
            drawAll(*WindowProperties::App);
            enemiesGenerator();
            pollEvent(Event);
        }
    }

    if (win)
    {
        WindowProperties::App->setMouseCursorVisible(true);
        GameCore::Instance().getWinScreenCore().start();
        WindowProperties::App->setMouseCursorVisible(false);
    }

    if (isGameLost)
    {
        WindowProperties::App->setMouseCursorVisible(true);
        GameCore::Instance().getGameOverScreen().start();
        WindowProperties::App->setMouseCursorVisible(false);
        if (WindowProperties::gameState == currentGameLevel)
        {
            GameHandler::Instance().resetGameToRetry();
            isGameLost = false;
        }
    }

}

void ALevel::generateEnemies(std::map<EnemyType, int> enemiesMap)
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
            for (auto &enemy : enemiesMap)
            {
                for (int i = 0; i < enemy.second; i++)
                    ennemies.emplace_back(new Enemy(enemy.first));
            }
            changePhase = true;
        }
        else if (phase == phaseMax)
        {
            for (auto &enemy : enemiesMap)
            {
                for (int i = 0; i < enemy.second; i++)
                    ennemies.emplace_back(new Enemy(enemy.first));
            }
            phase++;
        }
    }
}

void ALevel::enemiesGenerator()
{
    this->phases.at(phase)();
}

void ALevel::setPlayerBlinking(bool playerBlinking)
{
    ALevel::playerBlinking = playerBlinking;
}

void ALevel::setWin(bool win)
{
    ALevel::win = win;
}


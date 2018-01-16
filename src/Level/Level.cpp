//
// Created by Pierre on 03/12/2017.
//

#include <Parsing.h>
#include <Enemy.h>
#include "Level/Level.h"

Level::Level() : ALevel()
{
    initLvl("lvl1");
}

Level::~Level()
{
    music.stop();
    back.flushLayers();
}

void Level::start()
{
    sf::Event Event;
    sf::Time elapsed;

    for (int i = 0; i < (std::rand() % 10 + 10); ++i)
    {
        entities.push_back(new Enemy(EnemyType::BASIC_A));
        entities.push_back(new Enemy(EnemyType::BASIC_A));
    }
    bulletsEnemy.reserve(100000);

    music.play();
    while (WindowProperties::App->isOpen() && WindowProperties::gameState == GameState::LEVEL1)
    {
        elapsed = clock.getElapsedTime();
        invulnerabilityTime = inv.getElapsedTime();
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
            pollEvent(Event);
            WindowProperties::App->display();
        }
    }
/*level1.start();
level2.start();*//*

level.setMusicStatus("stop");*/

}

/*void Level::initLvl(const std::string &path)
{
    back.flushLayers();
    orientation = Orientation::VERTICAL;
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

void Level::drawLvl(sf::RenderWindow &App)
{
    back.drawBackground(App);
}

void Level::setMusicStatus(const std::string &status)
{
    if (status == "stop")
        music.stop();
    else if (status == "play")
        music.play();
    else if (status == "pause")
        music.pause();
}

const sf::SoundSource::Status Level::getMusicStatus() const
{
    return (music.getStatus());*/
/*
    if (music.getStatus() == sf::SoundSource::Stopped)
        return (sf::SoundSource::Stopped);
    else if (music.getStatus() == sf::SoundSource::Paused)
        return (sf::SoundSource::Paused);
    else if (music.getStatus() == sf::SoundSource::Playing)
        return (sf::SoundSource::Playing);
*/

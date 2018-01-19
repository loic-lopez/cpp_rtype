//
// Created by Zàkelis on 08/12/2017.
//

#include "TextureManager.h"

TextureManager TextureManager::m_instance = TextureManager();

TextureManager::TextureManager()
{
    sprites[(int) Textures::BULLET_BASIC_A] = Animation("bullet", Stance::IDLE);
    sprites[(int) Textures::BULLET_ENEMY_A] = Animation("enemyBulletA", Stance::IDLE);
    sprites[(int) Textures::PLAYER] = Animation("player", Stance::IDLE);
    sprites[(int) Textures::PLAYER_BULLETS_A] = Animation("playerBullets", Stance::IDLE);
    sprites[(int) Textures::ENEMY1] = Animation("enemy1", Stance::IDLE);
    sprites[(int) Textures::ENEMY2] = Animation("enemy2", Stance::IDLE);
    sprites[(int) Textures::BOSS1] = Animation("boss1", Stance::IDLE);
    sprites[(int) Textures::BOSS2] = Animation("boss2", Stance::IDLE);
    sprites[(int) Textures::LIFEUP] = Animation("life", Stance::IDLE);
    sprites[(int) Textures::STRAIGHT] = Animation("straight", Stance::IDLE);
    sprites[(int) Textures::SPREAD] = Animation("spread", Stance::IDLE);
}

TextureManager::~TextureManager()
{
    for (size_t i = 0; i < 6; i++)
    {
        sprites[i].freeDatas();
    }
}

TextureManager &TextureManager::Instance()
{
    return m_instance;
}

Animation &TextureManager::getSprite(Textures text)
{
    return (sprites[(int) text]);
}
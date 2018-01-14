//
// Created by Loic Dupil on 11/01/2018.
//

#include "GameEngine.h"

GameEngine GameEngine::m_Instance = GameEngine();

GameEngine::GameEngine()
{
    this->gameEngineThread = new sf::Thread([]() { GameEngine::Instance().ThreadRun(); });
    active = true;
}

GameEngine::~GameEngine()
{
    delete this->gameEngineThread;
}

void GameEngine::ThreadRun()
{
    GameEngine::Thing *player;
    GameEngine::Thing *enemy;
    while (Instance().active)
    {
        for (size_t i = 0; i < m_Instance.Entities.size(); i++)
        {
            if (m_Instance.Entities[i]->type == Textures::REIMU)
                player = m_Instance.Entities[i];
            if (m_Instance.Entities[i]->type == Textures::ENEMY1)
                enemy = m_Instance.Entities[i];
//            if (m_Instance.Entities[i]->type == Textures::REIMU)
//                std::cerr << "player trouvé" << std::endl;
//            if (m_Instance.Entities[i]->type == Textures::ENEMY1)
//                std::cerr << "ennemi trouvé" << std::endl;
//            if (m_Instance.Entities[i]->type == Textures::BULLET_ENEMY_A)
//                std::cerr << "balle ennemi trouvée" << std::endl;
        }
        for (size_t i = 0; i < m_Instance.Entities.size(); i++)
        {
            if (m_Instance.Entities[i]->type != Textures::REIMU && m_Instance.Entities[i]->type != Textures::REIMU_BULLETS_A)
            {
                //std::cerr << "check for remu's hitbox" << std::endl;
                if (m_Instance.checkPlayerBoxe(player, m_Instance.Entities[i]) == -1)
                {
                    std::cerr << "++Ally hurt" << std::endl;
                }
            }
            if (m_Instance.Entities[i]->type != Textures::REIMU && m_Instance.Entities[i]->type == Textures::BULLET_ENEMY_A)
            {
                //std::cerr << "check for enemy's hitbox" << std::endl;
                if (m_Instance.checkPlayerBoxe(enemy, m_Instance.Entities[i]) == -1)
                    std::cerr << "Enemy hurt" << std::endl;
            }
        }
    }
}

void GameEngine::checkHitBoxes()
{

}

GameEngine::Thing::Thing()
{

}

void GameEngine::start()
{
    Instance().gameEngineThread->launch();
}

GameEngine &GameEngine::Instance()
{
    return m_Instance;
}

void GameEngine::fillEntities(Entity *obj, Side side, Textures type)
{
    GameEngine::Thing *entity = new GameEngine::Thing();
    entity->obj = obj;
    entity->hitBox = obj->getBounds();
    entity->side = side;
    entity->type = type;

    Instance().Entities.push_back(entity);
}

std::vector<GameEngine::Thing *> GameEngine::getEntities()
{
    return std::vector<GameEngine::Thing *>();
}

int GameEngine::checkPlayerBoxe(GameEngine::Thing *player, GameEngine::Thing *obstacles)
{
    float _x = obstacles->hitBox.left;
    std::cerr << "-x: " << _x << std::endl;
    float _y = obstacles->hitBox.top;
    std::cerr << "-y: " << _y << std::endl;
    float x = obstacles->hitBox.width;
    std::cerr << "x: " << x << std::endl;
    float y = obstacles->hitBox.height;
    std::cerr << "y: " << y << std::endl;
    float _X = player->hitBox.left;
    std::cerr << "reimu -x: " << _X << std::endl;
    float _Y = player->hitBox.top;
    std::cerr << "reimu -y: " << _Y << std::endl;
    float X = player->hitBox.width;
    std::cerr << "reimu x: " << X << std::endl;
    float Y = player->hitBox.height;
    std::cerr << "reimu y: " << Y << std::endl;
    if (player->hitBox.intersects(obstacles->hitBox))
        return -1;
    else
        return 0;
}

void GameEngine::stopThread()
{
    Instance().active = false;
}

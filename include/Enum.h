//
// Created by loic lopez on 22/12/2017.
//

#ifndef RTYPE_ENUM_H
#define RTYPE_ENUM_H

#include <fstream>

enum class ControlType
{
    XBOXCONTROLLER,
    KEYBOARD
};

enum class Orientation
{
    VERTICAL,
    HORIZONTAL
};

enum class Stance : int
{
    IDLE = 0,
    DEATH = 1
};

enum class Side
{
    ALLIED,
    ENEMY
};

enum class GameState : int
{
    // TODO : AJOUTER DES GAMEOVER POUR CHAQUE LEVEL
    LEVEL1,
    LEVEL2,
    LEVEL3,
    LEVEL4,
    LEVEL5,
    SPLASHSCREEN,
    MENU,
    INGAMEMENU,
    CLOSE,
    GAMEOVER,
    PREGAME_LEVEL1,
    PREGAME_LEVEL2,
    PREGAME_LEVEL3,
    PREGAME_LEVEL4
};

enum class EnemyType
{
    BASIC_A,
    BASIC_B,
    BOSS_A,
    BOSS_B,
    NONE,
};

enum class BulletType
{
    PLAYER_A,
    BASIC_A,
    ENEMY_A
};

enum class WeaponType
{
    STRAIGHT,
    SPREAD,
    HOMING,
    ROTATE
};

enum class Textures
{
    PLAYER,
    PLAYER_BULLETS_A,
    ENEMY1,
    ENEMY2,
    BOSS1,
    BULLET_BASIC_A,
    BULLET_ENEMY_A,
    BOSS2,
};
#endif //RTYPE_ENUM_H

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

enum class Difficulty : int
{
    HARMLESS,
    SADISTIC,
    MERCILESS,
};

enum class GameState : int
{
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
    OPTIONS,
    WIN
};

enum class EnemyType
{
    BASIC_A,
    BASIC_B,
    BOSS_A,
    BOSS_B,
    BOSS_C,
    BOSS_D,
    BOSS_E,
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
    BOSS2,
    BOSS3,
    BOSS4,
    BOSS5,
    BULLET_BASIC_A,
    BULLET_ENEMY_A,
    LIFEUP,
    SPREAD,
    STRAIGHT
};

#endif //RTYPE_ENUM_H

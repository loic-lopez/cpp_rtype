//
// Created by Eric on 29/11/2017.
//

#include <WindowProperties.h>
#include "Entity.h"

Entity::Entity()
{
    shootCooldown = 0;
    hp = 100;
    orientation = WindowProperties::orientation;
}

Entity::~Entity()
{
}

int Entity::getHp() const
{
    return hp;
}

void Entity::setHp(int hp)
{
    Entity::hp = hp;
}

const sf::Vector2f &Entity::getPos() const
{
    return pos;
}

void Entity::setPos(const sf::Vector2f &pos)
{
    Entity::pos = pos;
}

Stance Entity::getStance() const
{
    return stance;
}

void Entity::setStance(Stance stance)
{
    Entity::stance = stance;
}

void Entity::drawSprite(sf::RenderWindow &App)
{
    sprites[(int) stance].drawFrame(App, pos, orientation);
}

void Entity::move(sf::Vector2f mov)
{
    pos.x += ((int) mov.x * speed);
    if (pos.x < 0)
        pos.x = 0;
    else if (pos.x > WindowProperties::WIN_WIDTH)
        pos.x = WindowProperties::WIN_WIDTH;
    pos.y += ((int) mov.y * speed);
    if (pos.y < 0)
        pos.y = 0;
    else if (pos.y > WindowProperties::WIN_HEIGHT)
        pos.y = WindowProperties::WIN_HEIGHT;
}

void Entity::changeOrientation(Orientation newOrientation)
{
    if (orientation != newOrientation)
    {
        float percentx = pos.x / (float) WindowProperties::WIN_WIDTH;
        float percenty = pos.y / (float) WindowProperties::WIN_HEIGHT;
        float previousx = trajectory.x;
        float previousy = trajectory.y;
        if (newOrientation == Orientation::HORIZONTAL)
        {
            pos.x = (1.f - percenty) * (float) WindowProperties::WIN_WIDTH;
            trajectory.x = -previousy;
        }
        else if (newOrientation == Orientation::VERTICAL)
        {
            pos.x = (percenty) * (float) WindowProperties::WIN_WIDTH;
            trajectory.x = previousy;
        }
        if (newOrientation == Orientation::HORIZONTAL)
        {
            pos.y = percentx * (float) WindowProperties::WIN_HEIGHT;
            trajectory.y = previousx;
        }
        else if (newOrientation == Orientation::VERTICAL)
        {
            pos.y = (1.f - percentx) * (float) WindowProperties::WIN_HEIGHT;
            trajectory.y = -previousx;
        }
        orientation = newOrientation;
    }
}

bool Entity::outOfBounds()
{
    return !(pos.x < 0 || pos.y < 0 || pos.x > WindowProperties::WIN_WIDTH || pos.y > WindowProperties::WIN_HEIGHT);
}

void Entity::setTrajectory(const sf::Vector2f &newTrajectory)
{
    trajectory = newTrajectory;
}

Orientation Entity::getOrientation() const
{
    return orientation;
}

void Entity::setOrientation(Orientation orientation)
{
    Entity::orientation = orientation;
}

sf::FloatRect   Entity::getBounds()
{
    return this->sprites[0].getSize();
}

void Entity::setSide(Side side)
{
    this->side = side;
}
Side Entity::getSide()
{
    return this->side;
}

void Entity::setType(Textures textures)
{
    this->type = textures;
}

Textures Entity::getType()
{
    return this->type;
}

sf::FloatRect Entity::getHitBox()
{
    sf::FloatRect hitbox = sprites[(int)stance].getSize();
    return (sf::FloatRect(pos.x - hitbox.width / 2.f, pos.y - hitbox.height / 2.f, hitbox.width, hitbox.height));
}

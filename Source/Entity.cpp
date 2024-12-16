#include "Entity.h"

Entity::Entity(float posX, float posY, sf::Texture img)
	:m_posX(posX),m_posY(posY),m_img(img)
{
}

Entity::Entity(float posX, float posY)
	:m_posX(posX), m_posY(posY)
{
}

Entity::Entity()
	:m_posX(0), m_posY(0)
{
}

Entity::~Entity()
{
}

void Entity::LoadTexture(sf::Texture img)
{
}

float Entity::GetX() const
{
	return m_posX;
}

float Entity::GetY() const
{
	return m_posY;
}

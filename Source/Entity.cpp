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

const float Entity::GetX()
{
	return m_posX;
}

const float Entity::GetY()
{
	return m_posY;
}

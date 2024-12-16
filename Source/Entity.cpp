#include "Entity.h"

Entity::Entity(float posX, float posY, sf::Texture img)
	:m_posX(posX),m_posY(posY),m_text(img)
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

void Entity::LoadTexture(std::string filePath)
{
	m_text.loadFromFile(filePath);
}

float Entity::GetX() const
{
	return m_posX;
}

float Entity::GetY() const
{
	return m_posY;
}

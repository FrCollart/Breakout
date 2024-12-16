#include "Entity.h"

Entity::Entity(float posX, float posY, sf::Texture img)
	:m_PosX(posX),m_PosY(posY),m_Text(img)
{
}

Entity::Entity(float posX, float posY)
	:m_PosX(posX), m_PosY(posY)
{
}

Entity::Entity()
	:m_PosX(0), m_PosY(0)
{
}

Entity::~Entity()
{
}

void Entity::LoadTexture(std::string filePath)
{
	m_Text.loadFromFile(filePath);
}

float Entity::GetX() const
{
	return m_PosX;
}

float Entity::GetY() const
{
	return m_PosY;
}

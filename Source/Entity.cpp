#include "Entity.h"

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

float Entity::GetX() const
{
	return m_PosX;
}

float Entity::GetY() const
{
	return m_PosY;
}

std::weak_ptr<sf::Drawable> Entity::GetSprite()
{
	if (!m_Sprite) 
	{
		sf::RectangleShape defaultRectangle(sf::Vector2f(50, 50));
		defaultRectangle.setFillColor(sf::Color::White);

		m_Sprite = std::make_shared<sf::RectangleShape>(defaultRectangle);
	}
	return m_Sprite;
}
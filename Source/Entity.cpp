#include "Entity.h"

Entity::Entity(float posX, float posY)
	: m_PosX(posX), m_PosY(posY)
{
}

Entity::Entity()
	: m_PosX(0.0f), m_PosY(0.0f)
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

void Entity::SetX(float x)
{
	m_PosX = x;
	SetSpritePos(m_PosX, m_PosY);
}

void Entity::SetY(float y)
{
	m_PosY = y;
	SetSpritePos(m_PosX, m_PosY);
}

void Entity::LoadTexture(const char* filePath)
{
	/*std::shared_ptr<sf::Texture> m_Texture = std::make_shared<sf::Texture>();
	if (!m_Texture->loadFromFile(filePath)) {
		throw std::runtime_error("Impossible de charger la texture !");
	}

	m_Sprite = std::make_shared<sf::Sprite>(*m_Texture);*/
}
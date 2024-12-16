#include "Ball.h"

Ball::Ball()
	: Entity(), m_Speed(10.0f), m_DirectionX(0.0f), m_DirectionY(1.0f), m_Size(50.0f)
{
	m_Sprite = std::make_shared<sf::CircleShape>(m_Size);
	SetSpritePos(m_PosX, m_PosY);
}

Ball::Ball(float size)
	: Entity(), m_Speed(10.0f), m_DirectionX(0.0f), m_DirectionY(1.0f), m_Size(size)
{
	m_Sprite = std::make_shared<sf::CircleShape>(m_Size);
	SetSpritePos(m_PosX, m_PosY);
}

Ball::Ball(float posX, float posY, float size)
	:Entity(posX, posY), m_Speed(10.0f), m_DirectionX(0.0f), m_DirectionY(1.0f), m_Size(size)
{
	m_Sprite = std::make_shared<sf::CircleShape>(m_Size);
	SetSpritePos(m_PosX, m_PosY);
}

Ball::~Ball()
{
}

void Ball::Update(float deltatime)
{
	m_PosX += deltatime * m_Speed * m_DirectionX;
	m_PosY += deltatime * m_Speed * m_DirectionY;
}

void Ball::SetSpritePos(float newX, float newY)
{
	auto sprite = std::dynamic_pointer_cast<sf::CircleShape>(m_Sprite);
	if (!sprite)
	{
		return;
	}

	sprite->setPosition(newX - m_Size, newY - m_Size);
}

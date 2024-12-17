#include "Player.h"
#include "GameConsts.h"

Player::Player() 
	: Entity(), m_Speed(200.0f), m_DirectionX(0.0f)
{
	sf::RectangleShape rectangle(sf::Vector2f(DEFAULT_PLAYER_WIDTH, DEFAULT_PLAYER_HEIGHT));
	rectangle.setFillColor(sf::Color::Blue);
	m_Sprite = std::make_shared<sf::RectangleShape>(rectangle);
}

void Player::Move()
{
	m_PosX += m_Speed * m_DirectionX;
}

void Player::SetDirection(float direction)
{
	m_DirectionX = direction;
}

void Player::SetSpritePos(float PosX, float PosY)
{
	auto sprite = std::dynamic_pointer_cast<sf::RectangleShape>(m_Sprite);
	if (!sprite)
	{
		return;
	}

	sprite->setPosition(PosX - DEFAULT_PLAYER_WIDTH/2, PosY - DEFAULT_PLAYER_HEIGHT / 2);
}

void Player::Update(float deltaTime)
{
	SetX(m_PosX + (deltaTime * m_Speed * m_DirectionX));
}

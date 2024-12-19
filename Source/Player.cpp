#include "Player.h"
#include "GameConsts.h"

Player::Player() 
	: Entity(), m_Speed(200.0f), m_DirectionX(0.0f), m_Width(DEFAULT_PLAYER_WIDTH), m_Height(DEFAULT_PLAYER_HEIGHT)
{
	sf::RectangleShape rectangle(sf::Vector2f(m_Width, m_Height));
	rectangle.setFillColor(sf::Color::Blue);
	m_Sprite = std::make_shared<sf::RectangleShape>(rectangle);
}

Player::Player(float posX, float posY)
	: Entity(posX, posY), m_Speed(200.0f), m_DirectionX(0.0f), m_Width(DEFAULT_PLAYER_WIDTH), m_Height(DEFAULT_PLAYER_HEIGHT)
{
	sf::RectangleShape rectangle(sf::Vector2f(m_Width, m_Height));
	rectangle.setFillColor(sf::Color::Blue);
	m_Sprite = std::make_shared<sf::RectangleShape>(rectangle);
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

void Player::OnCollide(Entity& other)
{
	// Do nothing
	(void)other;
}

void Player::Update(float deltaTime)
{
	SetX(m_PosX + (deltaTime * m_Speed * m_DirectionX));
}

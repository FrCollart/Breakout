#include "Ball.h"
#include "GameConsts.h"

Ball::Ball()
	: Entity(), m_Speed(DEFAULT_BALL_SPEED), m_DirectionX(DEFAULT_BALL_DIRECTIONX), m_DirectionY(DEFAULT_BALL_DIRECTIONY), m_Size(DEFAULT_BALL_SIZE)
{
	m_Sprite = std::make_shared<sf::CircleShape>(m_Size);
	//LoadTexture(TEXTUREBALL);	
}

Ball::Ball(float size)
	: Ball()
{
	m_Size = size;
}

Ball::Ball(float posX, float posY, float size)
	:Entity(posX, posY), m_Speed(DEFAULT_BALL_SPEED), m_DirectionX(DEFAULT_BALL_DIRECTIONX), m_DirectionY(DEFAULT_BALL_DIRECTIONY), m_Size(size)
{
	m_Sprite = std::make_shared<sf::CircleShape>(m_Size);
	//LoadTexture(TEXTUREBALL);
	SetSpritePos(m_PosX, m_PosY);
}

Ball::~Ball()
{
}

void Ball::SetSpeed(float speed)
{
	m_Speed = speed;
}

void Ball::SetDirectionX(float x)
{
	m_DirectionX = x;
}

void Ball::SetDirectionY(float y)
{
	m_DirectionY = y;
}

void Ball::FreeTheBall()
{
	m_DirectionY = -1.0f;
	m_FollowPlayer = false;
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

bool Ball::IsBallFree()
{
	return !m_FollowPlayer;
}

void Ball::Update(float deltatime)
{
	SetX(m_PosX + (deltatime * m_Speed * m_DirectionX));
	SetY(m_PosY + (deltatime * m_Speed * m_DirectionY));
}
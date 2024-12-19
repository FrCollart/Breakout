#include "Ball.h"

#include "GameConsts.h"
#include "Player.h"
#include "Brick.h"

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

void Ball::OnCollide(Entity& other)
{
	if (collisionCooldown > 0.0f) return;
	if (!dynamic_cast<Player*>(&other) && !dynamic_cast<Brick*>(&other)) return;

	float rectX = other.GetX();
	float rectY = other.GetY();

	auto brick = dynamic_cast<Brick*>(&other);
	float rectWidth = (brick) ? brick->GetWidth() : DEFAULT_PLAYER_WIDTH;
	float rectHeight = (brick) ? brick->GetHeight() : DEFAULT_PLAYER_HEIGHT;

	// If it's a player, calculate the directional effect based on the hit position
	if (dynamic_cast<Player*>(&other))
	{
		float playerCenterX = rectX;
		float impactOffset = m_PosX - playerCenterX;
		float maxOffset = rectWidth / 2.0f;

		float normalizedOffset = impactOffset / maxOffset;

		m_DirectionX = normalizedOffset;
		m_DirectionY = -std::abs(m_DirectionY); 
	}
	else // Brick
	{
		// For bricks, perform standard collision logic
		float closestX = std::max(rectX, std::min(m_PosX, rectX + rectWidth));
		float closestY = std::max(rectY, std::min(m_PosY, rectY + rectHeight));

		bool hitVertical = (closestX == m_PosX);
		bool hitHorizontal = (closestY == m_PosY);

		if (hitHorizontal)
		{
			m_DirectionX = -m_DirectionX;
		}
		if (hitVertical)
		{
			m_DirectionY = -m_DirectionY;
		}		
	}
	collisionCooldown = 0.1f;
}

void Ball::OnCollideWithBorder(bool horizontal)
{
	if (collisionCooldown > 0.0f) return;

	if (horizontal)
	{
		m_DirectionX = -m_DirectionX;
	}
	else
	{
		m_DirectionY = -m_DirectionY;
	}

	collisionCooldown = 0.1f;
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

void Ball::Update(float deltaTime)
{
	if (collisionCooldown > 0)
		collisionCooldown -= deltaTime;

	SetX(m_PosX + (deltaTime * m_Speed * m_DirectionX));
	SetY(m_PosY + (deltaTime * m_Speed * m_DirectionY));
}
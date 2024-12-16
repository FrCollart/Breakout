#include "Ball.h"

Ball::Ball()
{
}

Ball::~Ball()
{
}

void Ball::Update(float deltatime)
{
	m_PosX += deltatime * m_Speed * m_DirectionX;
	m_PosY += deltatime * m_Speed * m_DirectionY;
}

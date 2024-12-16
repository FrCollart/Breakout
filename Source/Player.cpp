#include "Player.h"

void Player::Move()
{
	m_PosX += m_Speed * m_DirectionX;
}

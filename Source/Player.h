#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player() :Entity(), m_Speed(10.0f), m_DirectionX(0.0f) {};
	~Player() {};
	void Move();

private:
	float m_Speed;
	float m_DirectionX;
};

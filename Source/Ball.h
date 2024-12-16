#pragma once
#include "Entity.h"

class Ball : public Entity
{
public:
	Ball();
	~Ball();

	void Update(float deltaTime);

private:
	float m_Speed;
	float m_DirectionX;
	float m_DirectionY;
};
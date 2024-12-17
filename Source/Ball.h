#pragma once
#include "Entity.h"

class Ball : public Entity
{
public:
	Ball();
	Ball(float size);
	Ball(float posX, float posY, float size);
	~Ball();

	void Update(float deltaTime) override;

	void SetSpritePos(float newX, float newY) override;

private:
	float m_Speed;
	float m_DirectionX;
	float m_DirectionY;
	float m_Size;
};
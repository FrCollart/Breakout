#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	~Player() {};
	void Move();

	float GetDirection();
	float GetSpeed();
	void SetDirection(float direction);
	void SetSpritePos(float PosX, float PosY) override;
	void Update(float deltaTime) override;

private:
	float m_Speed;
	float m_DirectionX;
};

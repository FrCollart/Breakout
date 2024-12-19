#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	Player();
	Player(float posX, float posY);
	~Player() {};

	float GetDirection() const { return m_DirectionX; }
	float GetSpeed() const { return m_Speed; }
	float GetWidth() const { return m_Width; }
	float GetHeight() const { return m_Height; }

	void SetDirection(float direction);
	void SetSpritePos(float PosX, float PosY) override;

	void OnCollide(Entity& other) override;

	void Update(float deltaTime) override;

private:
	float m_Speed;
	float m_DirectionX;

	float m_Width = 0.0f;
	float m_Height = 0.0f;
};

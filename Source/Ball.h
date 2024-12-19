#pragma once

#include "Entity.h"

#include <memory>

class Ball : public Entity
{
public:
	Ball();
	Ball(float size);
	Ball(float posX, float posY, float size);
	~Ball();

	float GetSize() const { return m_Size; }

	void SetSpeed(float speed);
	void SetDirectionX(float x);
	void SetDirectionY(float y);
	void FreeTheBall();

	bool IsBallFree();

	void SetSpritePos(float newX, float newY) override;
	void OnCollide(Entity& other) override;
	void OnCollideWithBorder(bool horizontal);

	void Update(float deltaTime) override;

private:
	float m_Speed;
	float m_DirectionX;
	float m_DirectionY;
	float m_Size;

	bool m_FollowPlayer = true;
};
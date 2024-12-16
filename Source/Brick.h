#pragma once

#include "Entity.h"
#include "GameConsts.h"

class Brick : public Entity
{
public:
	Brick() : Entity(), m_Width(DEFAULT_BRICK_WIDTH), m_Height(DEFAULT_BRICK_HEIGHT), m_IsReachable(false) {}
	Brick(float x, float y) : Entity(x, y), m_Width(DEFAULT_BRICK_WIDTH), m_Height(DEFAULT_BRICK_HEIGHT), m_IsReachable(false) {}
	Brick(float x, float y, float width, float height) : Entity(x, y), m_Width(width), m_Height(height), m_IsReachable(false) {}
	~Brick() {}

private:
	float m_Width = 0.0f;
	float m_Height = 0.0f;

	bool m_IsReachable = false;
};

#pragma once

#include "Entity.h"
#include "GameConsts.h"
#include "RewardManager.h"

class Brick : public Entity
{
public:
	Brick() : Entity(), m_Width(DEFAULT_BRICK_WIDTH), m_Height(DEFAULT_BRICK_HEIGHT), m_IsReachable(false) {}
	Brick(float x, float y) : Entity(x, y), m_Width(DEFAULT_BRICK_WIDTH), m_Height(DEFAULT_BRICK_HEIGHT), m_IsReachable(false) 
	{ 
		//LoadTexture(TEXTUREBALL);
		SetSpritePos(x, y);
	}
	Brick(float x, float y, float width, float height) : Entity(x, y), m_Width(width), m_Height(height), m_IsReachable(false)
	{
		//LoadTexture(TEXTUREBALL);
		sf::RectangleShape rectangle(sf::Vector2f(m_Width, m_Height));
		rectangle.setFillColor(sf::Color::Red);
		m_Sprite = std::make_shared<sf::RectangleShape>(rectangle);

		SetSpritePos(x, y);
	}
	~Brick() {}

	float GetWidth() const { return m_Width; }
	float GetHeight() const { return m_Height; }

	void SetSpritePos(float newX, float newY) override;
	void OnCollide(Entity& other) override;

	void Update(float deltaTime) override;

private:
	float m_Width = 0.0f;
	float m_Height = 0.0f;

	bool m_IsReachable = false;
};

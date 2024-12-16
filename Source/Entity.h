#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

class Entity
{
public:
	Entity(float posX, float posY);
	Entity();
	~Entity();

	float GetX() const;
	float GetY() const;
	std::weak_ptr<sf::Drawable> GetSprite();

protected:
	float m_PosX;
	float m_PosY;
	std::shared_ptr<sf::Drawable> m_Sprite = nullptr;
};


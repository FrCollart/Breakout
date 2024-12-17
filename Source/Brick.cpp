#include "Brick.h"

void Brick::SetSpritePos(float newX, float newY)
{
	auto sprite = std::dynamic_pointer_cast<sf::RectangleShape>(m_Sprite);
	if (!sprite)
	{
		return;
	}
	sprite->setPosition(newX, newY);
}

void Brick::Update(float deltaTime)
{
}

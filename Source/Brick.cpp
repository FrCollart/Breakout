#include "Brick.h"

void Brick::SetSpritePos(float newX, float newY)
{
	auto sprite = std::dynamic_pointer_cast<sf::RectangleShape>(m_Sprite);
	if (!sprite)
	{
		return;
	}
	sprite->setPosition(newX - m_Width, newY - m_Height);
}

void Brick::Update(float deltaTime)
{
}

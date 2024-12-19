#include "Brick.h"

#include "EntityManager.h"
#include "GameManager.h"

void Brick::SetSpritePos(float newX, float newY)
{
	auto sprite = std::dynamic_pointer_cast<sf::RectangleShape>(m_Sprite);
	if (!sprite)
	{
		return;
	}
	sprite->setPosition(newX, newY);
}

void Brick::OnCollide(Entity& other)
{
	(void)other;
	GameManager::GetInstance().CheckGameStatus();
}

void Brick::Update(float deltaTime)
{

}

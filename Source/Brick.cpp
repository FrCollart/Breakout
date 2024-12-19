#include "Brick.h"

#include "EntityManager.h"

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
	RewardManager::GetInstance().CanAddBonusBall();
	RewardManager::GetInstance().AddPlayerPoint(1);
	// Do nothing
	(void)other;
}

void Brick::Update(float deltaTime)
{
}
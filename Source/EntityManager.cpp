#include "EntityManager.h"
#include "Player.h"

EntityManager& EntityManager::GetInstance()
{
	static EntityManager instance;
	return instance;
}

void EntityManager::AddEntity(std::shared_ptr<class Entity> entity)
{
	m_Entities.emplace_back(std::move(entity));
}

void EntityManager::RemoveEntity(std::shared_ptr<class Entity> entity)
{
	m_Entities.erase(std::remove(m_Entities.begin(), m_Entities.end(), entity), m_Entities.end());
}

std::weak_ptr<Player> EntityManager::GetPlayer() const
{
	return m_Player;
}

void EntityManager::SetPlayer(std::shared_ptr<Player> player)
{
	m_Player = std::move(player);
}

#include "EntityManager.h"

EntityManager& EntityManager::GetInstance()
{
	static EntityManager instance;
	return instance;
}

void EntityManager::AddEntity(std::shared_ptr<class Entity> entity)
{
	m_Entities.push_back(std::move(entity));
}

void EntityManager::RemoveEntity(std::shared_ptr<class Entity> entity)
{
	m_Entities.erase(std::remove(m_Entities.begin(), m_Entities.end(), entity), m_Entities.end());
}

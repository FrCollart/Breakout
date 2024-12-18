#include "EntityManager.h"

EntityManager& EntityManager::GetInstance()
{
	static EntityManager instance;
	return instance;
}

std::vector<std::shared_ptr<Entity>> EntityManager::GetAllEntities()
{
    std::vector<std::shared_ptr<Entity>> allEntities;

    for (const auto& [type, entities] : m_Entities)
    {
        allEntities.insert(allEntities.end(), entities.begin(), entities.end());
    }

    return allEntities;
}

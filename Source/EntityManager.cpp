#include "EntityManager.h"

EntityManager& EntityManager::GetInstance()
{
	static EntityManager instance;
	return instance;
}

void EntityManager::RemoveEntity(std::shared_ptr<Entity> entity)
{
    for (auto& [type, entities] : m_Entities)
    {
        auto& entityVector = entities;
        auto it = std::find(entityVector.begin(), entityVector.end(), entity);
        if (it != entityVector.end())
        {
            entityVector.erase(it);

            if (entityVector.empty())
            {
                m_Entities.erase(type);
            }

            return;
        }
    }
}

void EntityManager::ClearEntities()
{
	m_Entities.clear();
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

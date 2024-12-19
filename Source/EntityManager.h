#pragma once

#include <map>
#include <memory>
#include <typeindex>
#include <vector>

#include "Entity.h"

template <typename T>
concept IsEntity = std::is_base_of<Entity, T>::value;

class EntityManager
{
public:
	static EntityManager& GetInstance();

	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;

	template<IsEntity T>
	void AddEntity(std::shared_ptr<T> entity);

	void RemoveEntity(std::shared_ptr<Entity> entity);

	template <IsEntity T>
	// Not optimized, consider using GetEntitiesRawByType instead
	std::vector<std::shared_ptr<T>> GetEntitiesByType();

	template <IsEntity T>
	// To use when type is not needed
	const std::vector<std::shared_ptr<Entity>>& GetEntitiesRawByType();

	std::vector<std::shared_ptr<Entity>> GetAllEntities();

private:
	// Private Constructor because of Singleton pattern
	EntityManager() = default;
	~EntityManager() = default;

	// Map of entities by type
	std::map<std::type_index, std::vector<std::shared_ptr<Entity>>> m_Entities;
};

template<IsEntity T>
inline void EntityManager::AddEntity(std::shared_ptr<T> entity)
{
	m_Entities[typeid(T)].emplace_back(std::move(entity));
}

template<IsEntity T>
inline std::vector<std::shared_ptr<T>> EntityManager::GetEntitiesByType()
{
	std::vector<std::shared_ptr<T>> result;
	auto it = m_Entities.find(typeid(T));
	if (it != m_Entities.end())
	{
		for (const auto& entity : it->second)
		{
			result.emplace_back(std::static_pointer_cast<T>(entity));
		}
	}
	return result;
}

template<IsEntity T>
inline const std::vector<std::shared_ptr<Entity>>& EntityManager::GetEntitiesRawByType()
{
	auto it = m_Entities.find(typeid(T));
	if (it != m_Entities.end())
	{
		return it->second;
	}

	static const std::vector<std::shared_ptr<Entity>> empty;
	return empty;
}

#pragma once

#include <vector>
#include <memory>

class EntityManager
{
public:
	static EntityManager& GetInstance();

	EntityManager(const EntityManager&) = delete;
	EntityManager& operator=(const EntityManager&) = delete;

	void AddEntity(std::shared_ptr<class Entity> entity);
	void RemoveEntity(std::shared_ptr<class Entity> entity);

	const std::vector<std::shared_ptr<Entity>>& GetEntities() const { return m_Entities; }

private:
	// Private Constructor because of Singleton pattern
	EntityManager() = default;
	~EntityManager() = default;

	std::vector<std::shared_ptr<class Entity>> m_Entities;
};


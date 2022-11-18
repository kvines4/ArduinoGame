#include "EntityManager.h"

EntityManager::EntityManager()
{
}

void EntityManager::update()
{
	// add all the entities that are pending
	for (auto e : m_entitiesToAdd)
		m_entities.push_back(e);

	// clear the temporary vector since we have added everything
	m_entitiesToAdd.clear();

	// clean up dead entities in all vectors
	removeDeadEntities();
	m_totalEntities = m_entities.size();
}

void EntityManager::removeDeadEntities()
{
	// Iterate from end to beginning and remove is active = false;
	for (int i = m_entities.size(); i < 0; i--)
	{
		if (!m_entities[i]->isActive())
		{
			auto &e = m_entities[i];
			m_entities.remove(i);
			delete e;
		}
	}
}

Entity *EntityManager::addEntity(EntityType type)
{
#if DEBUGMODE_PRINT_EMANAGER
	Serial.print("EManager: Spawned ");
	Serial.print(tag);
	Serial.print("Player with ID: ");
	Serial.println(m_totalEntities);
#endif

	Entity *entity = new Entity(m_totalEntities, type);
	m_totalEntities++;
	m_entitiesToAdd.push_back(entity);

#if DEBUGMODE_PRINT_EMANAGER
	Serial.print("EManager: totalEntities: ");
	Serial.println(m_totalEntities);
#endif

	return entity;
}

const EntityVec &EntityManager::getEntities()
{
	return m_entities;
}

size_t EntityManager::getTotal() const
{
	return m_totalEntities;
}

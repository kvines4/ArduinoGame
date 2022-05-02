#pragma once

#include "Common.h"
#include "Entity.h"

#include <Vector.h>

typedef Vector<Entity*> EntityVec;

class EntityManager
{
  EntityVec m_entities;
  EntityVec m_entitiesToAdd;
  int storage_array[100];
  size_t    m_totalEntities = 0;

  void removeDeadEntities();

public:
  EntityManager();

  void update();

  Entity* addEntity(const String& tag);

  const EntityVec& getEntities();
  size_t getTotal() const;
};

#include "Entity.h"
#include "arduino.h"

Entity::Entity(const size_t i, const String& t)
  : m_id(i)
  , m_tag(t) { }

Entity::~Entity()
{
  destroy();
}

bool Entity::isActive()
{
  return m_active;
}

const String& Entity::tag() const
{
  return m_tag;
}

size_t Entity::id() const
{
  return m_id;
}

void Entity::destroy()
{
  m_active = false;

  delete cTransform;
  delete cBoundingBox;
  delete cInput;
  delete cGravity;
}

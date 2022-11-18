#include "Entity.h"
#include "arduino.h"

Entity::Entity(const size_t i, EntityType t)
	: m_id(i), m_type(t) {}

Entity::~Entity()
{
	destroy();
}

bool Entity::isActive()
{
	return m_active;
}

EntityType Entity::type() const
{
	return m_type;
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
	delete cState;
	delete cAnimation;
}

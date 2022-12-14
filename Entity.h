#pragma once

#include "arduino.h"
#include "Components.h"

enum EntityType {
	Player,
	Tile,
	Enemy
};

class Entity
{
private:
	friend class EntityManager;

	Entity(const size_t id, EntityType type);
	~Entity();

	bool		m_active = true;
	size_t		m_id	 = 0;
	EntityType	m_type;

public:
	// component pointers
	CTransform	 *cTransform   = nullptr;
	CBoundingBox *cBoundingBox = nullptr;
	CInput		 *cInput	   = nullptr;
	CGravity	 *cGravity	   = nullptr;
	CState		 *cState	   = nullptr;
	CAnimation	 *cAnimation   = nullptr;

	// private member access functions
	bool isActive();
	EntityType type() const;
	size_t id() const;
	void destroy();
};

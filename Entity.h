#pragma once

#include "arduino.h"
#include "Components.h"

class Entity
{
private:
	friend class EntityManager;

	Entity(const size_t id, const String &tag);
	~Entity();

	bool m_active = true;
	size_t m_id = 0;
	String m_tag = "Default";

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
	const String &tag() const;
	size_t id() const;
	void destroy();
};

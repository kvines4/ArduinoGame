#pragma once

#include "Vec2.h"

#include <Arduino.h>

class Action
{
	String m_name;
	String m_type; // START/END 
	Vec2 m_pos = Vec2(0, 0);

public:
	Action();
	Action(const String& name, Vec2 pos);
	Action(const String& name, const String& type);

	const String& name() const;
	const String& type() const;
};
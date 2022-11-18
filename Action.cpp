#include "Action.h"

Action::Action()
{

}

Action::Action(const String& name, Vec2 pos)
	: m_name(name)
	, m_pos(pos)
{

}

Action::Action(const String& name, const String& type)
	: m_name(name)
	, m_type(type)
{

}

const String& Action::name() const
{
	return m_name;
}

const String& Action::type() const
{
	return m_type;
}
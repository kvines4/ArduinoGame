#include "Animation.h"

#include "Graphics.h"

Animation::Animation()
{

}

Animation::Animation(animationType type, const uint16_t** spriteArray)
	: Animation(type, spriteArray, 1, 0)
{

}

Animation::Animation(animationType type, const uint16_t **spriteArray, size_t frameCount, size_t speed)
	: m_type(type)
	, m_spriteArray(spriteArray)
	, m_frameCount(frameCount)
	, m_speed(speed)
{

}

// updates the animation to show the next frame, depending on its speed.
// animation loops when it reaches the end.
// return whether an update happened or not
bool Animation::update()
{
	if (m_speed <= 0) return false;
	m_currentFrame++;
	return true;
}

const Vec2& Animation::getSize() const
{
	return m_size;
}

const uint16_t* Animation::getSprite()
{
	int frame = ((m_currentFrame / m_speed) % m_frameCount);
	return m_spriteArray[frame];
}

bool Animation::hasEnded() const
{
	return m_currentFrame == (m_frameCount-1) * m_speed;
}

animationType Animation::getType()
{
	return m_type;
}
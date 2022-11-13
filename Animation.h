#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Animation
{
	size_t	m_frameCount   = 1;		   // total number of frames of animation
	size_t	m_currentFrame = 0;		   // the current frame of animation being played
	size_t	m_speed		   = 0;		   // the speed to play this animation
	Vec2	m_size		   = { 1, 1 }; // size of the animation frame
	String	m_name		   = "none";
	
	const uint16_t** m_spriteArray = nullptr;

public:

	Animation();
	Animation(const String& name, const uint16_t** spriteArray);
	Animation(const String& name, const uint16_t** spriteArray, size_t frameCount, size_t speed);

	bool update();
	bool hasEnded() const;
	const Vec2& getSize() const;
	const uint16_t* getSprite();
	const String& getName();
};
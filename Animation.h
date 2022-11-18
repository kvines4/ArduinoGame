#pragma once

#include "Graphics.h"
#include "Vec2.h"

enum animationType {
	JumpRight,
	JumpLeft,
	RunRight,
	RunLeft,
	StandRight,
	StandLeft,
};

class Animation
{
	size_t			m_frameCount	= 1;		// total number of frames of animation
	size_t			m_currentFrame	= 0;		// the current frame of animation being played
	size_t			m_speed			= 0;		// the speed to play this animation
	Vec2			m_size			= { 1, 1 };	// size of the animation frame
	animationType	m_type;
	
	const uint16_t** m_spriteArray = nullptr;

public:

	Animation();
	Animation(animationType type, const uint16_t** spriteArray);
	Animation(animationType type, const uint16_t** spriteArray, size_t frameCount, size_t speed);

	bool update();
	bool hasEnded() const;
	const Vec2& getSize() const;
	const uint16_t* getSprite();
	animationType getType();
};
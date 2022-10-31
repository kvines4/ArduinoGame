#line 1 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\Animation.h"

// #pragma once

// #include "Vector.h"

// #include "Vec2.h"

// class Animation
// {
// 	size_t	m_frameCount   = 1;		   // total number of frames of animation
// 	size_t	m_currentFrame = 0;		   // the current frame of animation being played
// 	size_t	m_speed		   = 0;		   // the speed to play this animation
// 	Vec2	m_size		   = { 1, 1 }; // size of the animation frame
	
// 	const uint16_t* m_sprite;

// public:

// 	Animation();
// 	// Animation(const uint16_t (*spriteArray)[256]);
// 	Animation(const uint16_t spriteArray[][256], size_t frameCount, size_t speed);

// 	void update();
// 	bool hasEnded() const;
// 	const Vec2& getSize() const;
// 	const uint16_t* getSprite();
// };
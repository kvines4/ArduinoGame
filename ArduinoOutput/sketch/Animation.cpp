#line 1 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\Animation.cpp"
// #include "Animation.h"

// #include "Graphics.h"

// Animation::Animation()
// {

// }

// // Animation::Animation(const uint16_t (*spriteArray)[256])
// // 	: Animation(spriteArray, 1, 0)
// // {

// // }

// Animation::Animation(const uint16_t spriteArray[1][256], size_t frameCount, size_t speed)
//     //: m_spriteArray(spriteArray)
//     // , m_frameCount(frameCount)
//     // , m_speed(speed)
// {

// }

// // updates the animation to show the next frame, depending on its speed
// // animation loops when it reaches the end
// void Animation::update()
// {
// 	if (m_speed <= 0) return;
// 	m_currentFrame++;
// }

// const Vec2& Animation::getSize() const
// {
// 	return m_size;
// }

// const uint16_t* Animation::getSprite()
// {
// 	return Graphics::playerWalkLeft[0];
// 	//return &m_spriteArray[((m_currentFrame / m_speed) % m_frameCount)];
// }

// bool Animation::hasEnded() const
// {
// 	return m_currentFrame == (m_frameCount-1) * m_speed;
// }
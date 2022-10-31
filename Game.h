#pragma once

#include "Entity.h"
#include "EntityManager.h"
#include "Common.h"
#include "Vec2.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

// Button Pins
#define LEFT_BUTTON  4
#define RIGHT_BUTTON 3
#define JUMP_BUTTON  2

// SSD1331 Pins
#define SCLK 13 // SCL // 13 is serial clock on pro mini
#define MOSI 11 // SDA // 11 is mosi on pro mini
#define RST  8  // RES
#define DC   9  // DC
#define CS   10 // CS // 10 is slave select on pro mini

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define PLAYER_SPEED   2
#define PLAYER_JUMP    -7
#define PLAYER_GRAVITY 1

class Game
{
private:
	bool m_running = true;

	EntityManager m_entityManager;
	Entity *m_player = nullptr;

	Adafruit_SSD1331 m_display = Adafruit_SSD1331(&SPI, CS, DC, RST);
	uint8_t m_height = 64;
	uint8_t m_width = 96;

	const uint8_t m_GAME_PERIOD = 16;
	unsigned long m_frameStartTime;
	unsigned long m_frameCurrentTime;
	unsigned long m_fpsLastCheckTime;
	unsigned long m_fpsCurrentTime;
	unsigned long m_frameCount;
	unsigned int m_fps;

	unsigned long m_animLastCheckTime;
	unsigned long m_animCurrentTime;
	unsigned long m_animframeCount;
	unsigned int m_ANIM_RATE = 120;
	unsigned int m_spriteIndex;
	Vec2 m_spriteSize = {16, 16};

	void fps(unsigned int seconds);

	void init();
	void update();

	void sMovement();
	void sUserInput();
	void sCollision();
	void sRender();

	void spawnPlayer();

public:
	Game();
	void run();
};

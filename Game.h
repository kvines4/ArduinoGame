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

#define PLAYER_SPEED   3
#define PLAYER_JUMP    -5
#define PLAYER_GRAVITY 0.5
#define FRAME_INTERVAL 16 //16.666ms for 60FPS 33.333 for 30FPS

class Game
{
private:
	bool m_running = true;

	EntityManager m_entityManager;
	Entity *m_player = nullptr;

	Adafruit_SSD1331 m_display = Adafruit_SSD1331(&SPI, CS, DC, RST);
	uint8_t m_height = 64;
	uint8_t m_width = 96;

	unsigned long m_frameStartTime;
	unsigned long m_frameCurrentTime;
	unsigned long m_fpsLastCheckTime;
	unsigned long m_fpsCurrentTime;
	unsigned long m_frameCount;
	unsigned int m_fps = 0;

	bool m_playerAnimUpdated = false;
	Vec2 m_spriteSize = {16, 16};

	void fps(unsigned int seconds);

	void init();
	void update();

	void sMovement();
	void sUserInput();
	void sCollision();
	void sAnimation();
	void sRender();

	void spawnPlayer();

public:
	Game();
	void run();
};

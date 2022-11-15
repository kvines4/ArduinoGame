#pragma once

#include "Entity.h"
#include "EntityManager.h"
#include "Common.h"
#include "Vec2.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

// 74HC165 Shift Register pins
#define SR_74HC165_LOAD 		 2	// PL pin 1
#define SR_74HC165_CLOCK_ENABLE	 5	//CE pin 15
#define SR_74HC165_DATA_IN		 4	// Q7 pin 7
#define SR_74HC165_CLOCK_IN		 3	// CP pin 2

// SSD1331 Pins
#define SSD1331_SCLK 13 // SCL // 13 is serial clock on pro mini
#define SSD1331_MOSI 11 // SDA // 11 is SSD1331_MOSI on pro mini
#define SSD1331_CS   10 // SSD1331_CS  // 10 is slave select on pro mini
#define SSD1331_DC   9  // DC
#define SSD1331_RST  8  // RES

// Game Values
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

	Adafruit_SSD1331 m_display = Adafruit_SSD1331(&SPI, SSD1331_CS, SSD1331_DC, SSD1331_RST);
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
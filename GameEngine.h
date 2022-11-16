#pragma once

#include "Game.h"

// 74HC165 Shift Register pins
#define SR_74HC165_LOAD 		 2	// PL pin 1
#define SR_74HC165_CLOCK_IN		 3	// CP pin 2
#define SR_74HC165_DATA_IN		 4	// Q7 pin 7
#define SR_74HC165_CLOCK_ENABLE	 5	//CE pin 15

// SSD1331 Pins
#define SSD1331_SCLK 13 // SCL // 13 is serial clock on pro mini
#define SSD1331_MOSI 11 // SDA // 11 is SSD1331_MOSI on pro mini
#define SSD1331_CS   10 // SSD1331_CS  // 10 is slave select on pro mini
#define SSD1331_DC   9  // DC
#define SSD1331_RST  8  // RES

struct Button_State {
	bool is_down;
	bool changed;
};

enum {
	BUTTON_LEFT,
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_RIGHT,
	BUTTON_A,
	BUTTON_B,
	BUTTON_START,
	BUTTON_SELECT,

	BUTTON_COUNT, // should be the last item
};

struct Input {
	Button_State buttons[BUTTON_COUNT];
};

class GameEngine
{
protected:

	Game* m_game;
	bool m_running = true;

	Adafruit_SSD1331 m_display = Adafruit_SSD1331(&SPI, SSD1331_CS, SSD1331_DC, SSD1331_RST);
	const uint8_t DISPLAY_HEIGHT = 64;
	const uint8_t DISPLAY_WIDTH= 96;

	unsigned long m_frameStartTime;
	unsigned long m_frameCurrentTime;
	unsigned long m_fpsLastCheckTime;
	unsigned long m_fpsCurrentTime;
	unsigned long m_frameCount;
	unsigned int m_fps = 0;
	
	void init();
	void update();

	void sUserInput();

	void fps(unsigned int seconds);

public:

	GameEngine();

	Input m_input;

	void run();

	uint8_t displayWidth();
	uint8_t displayHeight();

	Adafruit_SSD1331& display();

};
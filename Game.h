#pragma once

#include "Entity.h"
#include "EntityManager.h"
#include "Common.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

// Button Pins
#define LEFT_BUTTON  4
#define RIGHT_BUTTON 3
#define JUMP_BUTTON  2

// SSD1331 Pins
#define SCLK 13 // SCL
#define MOSI 11 // SDA
#define RST  9  // RES
#define DC   8  // DC
#define CS   10 // CS

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
  const uint8_t m_BALL_RATE = 16;
  unsigned long m_ballUpdate;
  bool m_running = true;

  Adafruit_SSD1331 m_display = Adafruit_SSD1331(&SPI, CS, DC, RST);
  uint8_t m_height = 64;
  uint8_t m_width  = 96;

  unsigned long lastMillis;
  unsigned long frameCount;
  unsigned int  framesPerSecond;
  void fps(unsigned int seconds);
  
  EntityManager m_entityManager;

  Entity* m_player = nullptr;
  
  
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

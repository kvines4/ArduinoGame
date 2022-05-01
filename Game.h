#pragma once
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

class Game
{
private:
  Adafruit_SSD1331 m_display    = Adafruit_SSD1331(&SPI, CS, DC, RST);
  uint8_t m_height = 64;
  uint8_t m_width  = 96;
  
  const uint8_t m_BALL_RATE = 40;

  bool m_resetBall = false;
  unsigned long m_ballUpdate;
  
  float m_playerSpeed    = 2;
  float m_playerJump     = -7;
  float m_playerMaxSpeed = 8;
  float m_playerGravity  = 1;
  float m_ballPosX       = 48;
  float m_ballPosY       = 32;
  float m_ballPrevPosX   = 48;
  float m_ballPrevPosY   = 32;
  float m_ballVelX       = 1;
  float m_ballVelY       = 1;
  bool m_grounded        = false;

  void init();

  void sMovement();
  void sUserInput();
  void sCollision();
  void sRender();

  void spawnPlayer();
public:
  bool leftState;
  bool rightState;
  bool jumpState;

  Game();

  void update();
};

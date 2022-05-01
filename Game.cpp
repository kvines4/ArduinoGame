#include "Game.h"

#include "Graphics.h"

#include <SPI.h>
#include <Wire.h>

Game::Game()
{
  init();
}

void Game::init()
{
  pinMode(LEFT_BUTTON,  INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(JUMP_BUTTON,  INPUT_PULLUP);

  // show splash screen
  m_display.begin();
  m_display.fillScreen(BLACK);
  
  m_display.setCursor(10, 13);
  m_display.setTextColor(RED);
  m_display.setTextSize(2);
  m_display.print("Ball");
    
  m_display.drawBitmap(10, 25, game, 75, 26, RED);
  delay(2000);
  
  m_display.fillScreen(BLACK);
  
  m_ballUpdate = millis();
}

void Game::update()
{
  unsigned long time = millis();
    
  if (time > m_ballUpdate) 
  {
    sUserInput();
    sMovement();
    sCollision();
    sRender();
  }
}

void Game::sUserInput()
{
  // get button states
  leftState  = (digitalRead(LEFT_BUTTON)  == HIGH);
  rightState = (digitalRead(RIGHT_BUTTON) == HIGH);
  jumpState  = (digitalRead(JUMP_BUTTON)  == HIGH);
}

void Game::sMovement()
{
  //float m_ballPrevVelX = m_ballVelX;
  //float m_ballPrevVelY = m_ballVelY;
  float m_ballInputSpeedX = 0;
  float m_ballInputSpeedY = m_ballVelY;

  if (m_ballPosY > m_height) { m_grounded = true; }

  // check input
  if (leftState)               { m_ballInputSpeedX -= m_playerSpeed; }
  if (rightState)              { m_ballInputSpeedX += m_playerSpeed; }
  if (jumpState && m_grounded) { m_ballInputSpeedY = m_playerJump;   }
  if (!jumpState)              
  {
    if (m_ballVelY < 0) 
    {
      m_ballVelY = 0;
      m_ballInputSpeedY = m_ballVelY;
    }
  }

  // calculate new velocity
  m_ballVelX = m_ballInputSpeedX;
  m_ballVelY = m_ballInputSpeedY + m_playerGravity;

  // move ball
  m_ballPrevPosX = m_ballPosX;
  m_ballPrevPosY = m_ballPosY;
  m_ballPosX += m_ballVelX;
  m_ballPosY += m_ballVelY;
}

void Game::sCollision()
{
      m_grounded = false;
    // Check if we hit the walls
    if (m_ballPosX < 0)           { m_ballPosX = 0; m_ballVelX = 0; }
    if (m_ballPosX >= m_width-1)  { m_ballPosX = m_width-1; m_ballVelX = 0;  }
    if (m_ballPosY > m_height-1) 
    {
      m_ballPosY = m_height-1;
      m_ballVelY = 0;
      m_grounded = true;
    }
}

void Game::sRender()
{
  // redraw ball
  m_display.drawPixel(m_ballPrevPosX, m_ballPrevPosY, BLACK);
  m_display.drawPixel(m_ballPosX, m_ballPosY, WHITE);

  m_ballUpdate += m_BALL_RATE;
}

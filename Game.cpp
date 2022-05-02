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
#if DEBUGMODE
  Serial.println("Game: Init");
#endif

  pinMode(LEFT_BUTTON,  INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);
  pinMode(JUMP_BUTTON,  INPUT_PULLUP);

  m_display.begin();

  // show splash screen
  m_display.fillScreen(BLACK);
  m_display.setCursor(10, 13);
  m_display.setTextColor(RED);
  m_display.setTextSize(2);
  m_display.print("Ball");
  m_display.drawBitmap(10, 25, game, 75, 26, RED);
    
  delay(2000);
  m_display.fillScreen(BLACK);

  spawnPlayer();

  m_ballUpdate = millis();
}

void Game::spawnPlayer()
{
#if DEBUGMODE
  Serial.println("Game: Spawn Player");
#endif
  delete m_player;
  m_player = new Entity(0, "player");
  m_player->cTransform = new CTransform({ 48, 32},
                                        { 0, 0 });
  m_player->cBoundingBox = new CBoundingBox({ 1, 1 });
  m_player->cGravity     = new CGravity(1);
  m_player->cInput       = new CInput();
}

void Game::run()
{
#if DEBUGMODE
  Serial.println("Game: Run");
#endif
  while(m_running)
  {
    update();
  }
}

void Game::update()
{
#if DEBUGMODE
  Serial.println("Game: Update");
#endif
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
  auto& pInput = m_player->cInput;
  
  pInput->left  = (digitalRead(LEFT_BUTTON)  == HIGH);
  pInput->right = (digitalRead(RIGHT_BUTTON) == HIGH);
  pInput->jump  = (digitalRead(JUMP_BUTTON)  == HIGH);

#if DEBUGMODE
  Serial.print("Left: ");
  Serial.print(pInput->left);
  Serial.print(" Right: ");
  Serial.print(pInput->right);
  Serial.print(" Jump: ");
  Serial.println(pInput->jump);
#endif
}

void Game::sMovement()
{
  auto& pTransform = m_player->cTransform;
  auto& pInput = m_player->cInput;
  auto& pGravity = m_player->cGravity;
  
  Vec2 playerInputSpeed = {0.0f, pTransform->velocity.y};

  // check input
  if (pInput->left)                       { playerInputSpeed.x -= PLAYER_SPEED; }
  if (pInput->right)                      { playerInputSpeed.x += PLAYER_SPEED; }
  if (pInput->jump && pGravity->grounded) { playerInputSpeed.y  = PLAYER_JUMP;  }
  if (!pInput->jump)              
  {
    // fall as soon as jump button is released
    if (pTransform->velocity.y < 0) 
    {
      pTransform->velocity.y = 0;
      playerInputSpeed.y     = 0;
    }
  }

  // calculate new velocity
  pTransform->velocity = playerInputSpeed;
  pTransform->velocity.y += pGravity->gravity;

  // move ball
  pTransform->prevPos = pTransform->pos;
  pTransform->pos += pTransform->velocity;
}

void Game::sCollision()
{
  auto& pTransform = m_player->cTransform;
  auto& pGravity = m_player->cGravity;
  
  pGravity->grounded = false;
  // Check if we hit the walls
  if (pTransform->pos.x < 0)           { pTransform->pos.x = 0; pTransform->velocity.x = 0; }
  if (pTransform->pos.x >= m_width-1)  { pTransform->pos.x = m_width-1; pTransform->velocity.x = 0; }
  if (pTransform->pos.y >  m_height-1) 
  {
    pTransform->pos.y = m_height-1;
    pTransform->velocity.y = 0;
    pGravity->grounded = true;
  }
}

void Game::sRender()
{
  auto& pTransform = m_player->cTransform;
  
  // redraw ball
  m_display.drawPixel(pTransform->prevPos.x, pTransform->prevPos.y, BLACK);
  m_display.drawPixel(pTransform->pos.x, pTransform->pos.y, WHITE);

  m_ballUpdate += m_BALL_RATE;
}

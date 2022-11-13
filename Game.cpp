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
	Serial.println("Game:     Init");
#endif

	SPI.begin();

	pinMode(LEFT_BUTTON,  INPUT_PULLUP);
	pinMode(RIGHT_BUTTON, INPUT_PULLUP);
	pinMode(JUMP_BUTTON,  INPUT_PULLUP);

	// show splash screen
	m_display.begin();
	m_display.fillScreen(BLACK);
	m_display.setCursor(6, 13);
	m_display.setTextColor(RED);
	m_display.setTextSize(2);
	m_display.print("Arduino");
	m_display.drawBitmap(10, 25, Graphics::gameLogo, 75, 26, RED);
	delay(2000);
	m_display.fillScreen(BLACK);

	// init game
	m_entityManager = EntityManager();
	spawnPlayer();
	m_frameStartTime = millis();
}

void Game::spawnPlayer()
{
#if DEBUGMODE
	Serial.println("Game:     Spawn Player");
#endif

	if (m_player)
	{
		m_player->destroy();
	}
	m_player = m_entityManager.addEntity("player");
	m_player->cTransform = new CTransform({48, 32}, {0 , 0});
	m_player->cBoundingBox = new CBoundingBox({1, 1});
	m_player->cGravity = new CGravity(PLAYER_GRAVITY);
	m_player->cInput = new CInput();
	m_player->cState = new CState();
	m_player->cAnimation = new CAnimation();
	m_player->cAnimation->animation = Animation("Run", Graphics::playerRunLeft, 4, 2);
}

void Game::run()
{
#if DEBUGMODE
	Serial.println("Game:     Run");
#endif

	while (m_running)
	{
		update();
	}
}

/// millis() returns the number of milliseconds passed since the Arduino board began.
/// Each call we check if enough milliseconds have passed before doing the next frame.
/// This should keep the frame rate consistent.
void Game::update()
{
	m_frameCurrentTime = millis();

	m_entityManager.update();

	if (m_frameCurrentTime - m_frameStartTime >= FRAME_INTERVAL)
	{
		sUserInput();
		sMovement();
		sCollision();
		sAnimation();
		sRender();

		fps(1);

		m_frameStartTime = m_frameCurrentTime;
	}
}

void Game::sUserInput()
{
	auto &pInput = m_player->cInput;

	pInput->left  = (digitalRead(LEFT_BUTTON)  == HIGH);
	pInput->right = (digitalRead(RIGHT_BUTTON) == HIGH);
	pInput->jump  = (digitalRead(JUMP_BUTTON)  == HIGH);

#if DEBUGMODE_PRINT_INPUTS
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
	auto &pTransform = m_player->cTransform;
	auto &pInput     = m_player->cInput;
	auto &pGravity   = m_player->cGravity;

	Vec2 playerInputSpeed = { 0.0f, pTransform->velocity.y };

	// check input
	if (pInput->left)  { playerInputSpeed.x -= PLAYER_SPEED; }
	if (pInput->right) { playerInputSpeed.x += PLAYER_SPEED; }
	if (pInput->jump && pGravity->grounded) { playerInputSpeed.y = PLAYER_JUMP; }
	if (!pInput->jump)
	{
		// fall as soon as jump button is released
		if (pTransform->velocity.y < 0)
		{
			pTransform->velocity.y = 0;
			playerInputSpeed.y = 0;
		}
	}

	// calculate new velocity
	pTransform->velocity = playerInputSpeed;
	pTransform->velocity.y += pGravity->gravity;

	// move player
	pTransform->prevPos = pTransform->pos;
	pTransform->pos += pTransform->velocity;

	if(pTransform->velocity.x > 0) 
		pTransform->facingRight = true;
	else if(pTransform->velocity.x < 0) 
		pTransform->facingRight = false;

	// TODO: MOVE OTHER ENTITIES

	// move entities
	// for (Entity entity : m_entityManager.getEntities())
	// {
	// 	auto& transform = entity.getComponent<CTransform>();

	// 	if (entity.hasComponent<CGravity>())
	// 	{
	// 		transform.velocity.y += entity.getComponent<CGravity>().gravity;
	// 	}

	// 	transform.prevPos = transform.pos;
	// 	transform.pos += transform.velocity;
	// }
}

void Game::sCollision()
{
	auto &pTransform = m_player->cTransform;
	auto &pGravity	 = m_player->cGravity;
	auto &pState	 = m_player->cState;

	pState->state = "air";
	pGravity->grounded = false;
	// Check if we hit the left wall
	if (pTransform->pos.x < 0)
	{
		pTransform->pos.x = 0;
		pTransform->velocity.x = 0;
	}
	// Check if we hit the right wall
	if (pTransform->pos.x > m_width - m_spriteSize.x)
	{
		pTransform->pos.x = m_width -  m_spriteSize.x;
		pTransform->velocity.x = 0;
	}
	// Check if we hit the floor
	if (pTransform->pos.y > m_height - m_spriteSize.y)
	{
		pState->state = "ground";
		pTransform->pos.y = m_height -  m_spriteSize.y;
		pTransform->velocity.y = 0;
		pGravity->grounded = true;
	}

#if DEBUGMODE_PRINT_STATE
	Serial.print("Game:     Player State: ");
	Serial.println(pState->state);
#endif
}

void Game::sAnimation()
{
	m_playerAnimUpdated = false;

	auto &pState	 = m_player->cState;
	auto &pAnimation = m_player->cAnimation;
	auto &pTransform = m_player->cTransform;

	// set player animation based on state and input
	if (pState->state == "air")
	{
		if(pTransform->facingRight == true)
		{
			if (pAnimation->animation.getName() != "JumpRight")
			{
#if DEBUGMODE_PRINT_ANIM
				Serial.println("Game:     Changed Animation: JumpRight");
#endif
				m_player->cAnimation->animation = Animation("JumpRight", Graphics::playerJumpRight);
				m_playerAnimUpdated = true;
			}
		}
		else
		{
			if(pAnimation->animation.getName() != "JumpLeft")
			{
#if DEBUGMODE_PRINT_ANIM
				Serial.println("Game:     Changed Animation: JumpLeft");
#endif
				m_player->cAnimation->animation = Animation("JumpLeft", Graphics::playerJumpLeft);
				m_playerAnimUpdated = true;
			}
		}

	}
	else if (pState->state == "ground")
	{
		auto& pInput = m_player->cInput;
		if ((pInput->left || pInput->right) && !(pInput->left && pInput->right))
		{
			if(pTransform->facingRight == true)
			{
				if (pAnimation->animation.getName() != "RunRight")
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: RunRight");
#endif
					m_player->cAnimation->animation = Animation("RunRight", Graphics::playerRunRight, 4, 2);
					m_playerAnimUpdated = true;
				}
			}
			else
			{
				if (pAnimation->animation.getName() != "RunLeft")
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: RunLeft");
#endif
					m_player->cAnimation->animation = Animation("RunLeft", Graphics::playerRunLeft, 4, 2);
					m_playerAnimUpdated = true;
				}
			}
		}
		else
		{
			if(pTransform->facingRight == true)
			{
				if (pAnimation->animation.getName() != "StandRight")
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: StandRight");
#endif
					m_player->cAnimation->animation = Animation("StandRight", Graphics::playerStandRight);
					m_playerAnimUpdated = true;
				}
			}
			else
			{
				if (pAnimation->animation.getName() != "StandLeft")
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: StandLeft");
#endif
					m_player->cAnimation->animation = Animation("StandLeft", Graphics::playerStandLeft);
					m_playerAnimUpdated = true;
				}
			}
		}
	}

	if(m_player->cAnimation->animation.update()) m_playerAnimUpdated = true;
}

void Game::sRender()
{

	auto &pTransform = m_player->cTransform;
	auto &pAnimation = m_player->cAnimation;

	// only redraw the player when they have moved or animated
	if (pTransform->pos.x != pTransform->prevPos.x ||
		pTransform->pos.y != pTransform->prevPos.y || m_playerAnimUpdated)
	{
		Vec2 diff = pTransform->prevPos - pTransform->pos;
		// black out old pixels based on the position difference between frames
		// TODO: Have a 'background layer' to redraw from instead of black
		if (diff.x < 0)
		{
			m_display.fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y,
							   abs(diff.x-1.5),
							   m_spriteSize.y,
							   BLACK);
		}
		else if (diff.x > 0)
		{
			m_display.fillRect(pTransform->prevPos.x + m_spriteSize.x - diff.x,
							   pTransform->prevPos.y,
							   abs(diff.x+1.5),
							   m_spriteSize.y,
							   BLACK);
		}
		if (diff.y < 0)
		{
			m_display.fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y,
							   m_spriteSize.x,
							   abs(diff.y-1.5),
							   BLACK);
		}
		else if (diff.y > 0)
		{
			m_display.fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y + m_spriteSize.y - diff.y,
							   m_spriteSize.x,
							   abs(diff.y+1.5),
							   BLACK);
		}

		m_display.drawRGBBitmap(pTransform->pos.x,
								pTransform->pos.y,
								pAnimation->animation.getSprite(),
								m_spriteSize.x,
								m_spriteSize.y);
	}
}

/// @brief Increment frame count each call. Display's current FPS after small delay.
/// @param seconds How many seconds between FPS checks.
void Game::fps(unsigned int seconds)
{
	if(seconds < 1) seconds = 1;
	m_frameCount++;
	m_fpsCurrentTime = millis();
	if ((m_fpsCurrentTime - m_fpsLastCheckTime) >= (seconds * 1000))
	{
		m_fps = (m_frameCount / seconds);
		m_frameCount = 0;
		m_fpsLastCheckTime = m_fpsCurrentTime;

		m_display.fillRect(0, 0, 42, 8, BLACK);
		m_display.setCursor(0, 0);
		m_display.setTextColor(WHITE);
		m_display.setTextSize(1);
		m_display.print(m_fps);

#if DEBUGMODE_PRINT_FPS
		Serial.print("FPS: ");
		Serial.println(m_fps);
#endif
	}
}

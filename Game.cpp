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
	m_player->cGravity = new CGravity(1);
	m_player->cInput = new CInput();
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

	if (m_frameCurrentTime - m_frameStartTime >= m_GAME_PERIOD)
	{
		sUserInput();
		sMovement();
		sCollision();
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
	pGravity->grounded = false;
	// Check if we hit the left wall
	if (pTransform->pos.x < 0)
	{
		pTransform->pos.x = 0;
		pTransform->velocity.x = 0;
	}
	// Check if we hit the right wall
	if (pTransform->pos.x > m_width - 16)
	{
		pTransform->pos.x = m_width - 16;
		pTransform->velocity.x = 0;
	}
	// Check if we hit the floor
	if (pTransform->pos.y > m_height - 16)
	{
		pTransform->pos.y = m_height - 16;
		pTransform->velocity.y = 0;
		pGravity->grounded = true;
	}
}

void Game::sRender()
{
	bool animationUpdate = false;
	m_animframeCount++;
	m_animCurrentTime = millis();
	if ((m_animCurrentTime - m_animLastCheckTime) >= m_ANIM_RATE)
	{
		m_spriteIndex++;
		if (m_spriteIndex >= 4) m_spriteIndex = 0;
		animationUpdate = true;

		m_animframeCount = 0;
		m_animLastCheckTime = m_animCurrentTime;
	}

	auto &pTransform = m_player->cTransform;
	//auto &pAnimation = m_player->cAnimation;

	// only redraw the player when they have moved
	if (pTransform->pos.x != pTransform->prevPos.x ||
		pTransform->pos.y != pTransform->prevPos.y)// || animationUpdate)
	{
		Vec2 diff = pTransform->prevPos - pTransform->pos;
		// black out old pixels based on the position difference between frames
		if (diff.x < 0)
		{
			m_display.fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y,
							   abs(diff.x),
							   m_spriteSize.y,
							   BLACK);
		}
		else if (diff.x > 0)
		{
			m_display.fillRect(pTransform->prevPos.x + m_spriteSize.x - diff.x,
							   pTransform->prevPos.y,
							   abs(diff.x),
							   m_spriteSize.y,
							   BLACK);
		}
		if (diff.y < 0)
		{
			m_display.fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y,
							   m_spriteSize.x,
							   abs(diff.y),
							   BLACK);
		}
		else if (diff.y > 0)
		{
			m_display.fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y + m_spriteSize.y - diff.y,
							   m_spriteSize.x,
							   abs(diff.y),
							   BLACK);
		}

		m_display.drawRGBBitmap(pTransform->pos.x,
								pTransform->pos.y,
								Graphics::playerWalkRight[m_spriteIndex],
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

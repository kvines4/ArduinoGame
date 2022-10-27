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

	pinMode(LEFT_BUTTON, INPUT_PULLUP);
	pinMode(RIGHT_BUTTON, INPUT_PULLUP);
	pinMode(JUMP_BUTTON, INPUT_PULLUP);

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

	m_entityManager = EntityManager();
	spawnPlayer();

	m_ballUpdate = millis();
}

void Game::spawnPlayer()
{
#if DEBUGMODE
	Serial.println("Game: Spawn Player");
#endif

	if (m_player)
	{
		m_player->destroy();
	}

	m_player = m_entityManager.addEntity("player");

	m_player->cTransform = new CTransform({48, 32},
	                                      {0 , 0});
	m_player->cBoundingBox = new CBoundingBox({1, 1});
	m_player->cGravity = new CGravity(1);
	m_player->cInput = new CInput();
}

void Game::run()
{
#if DEBUGMODE
	Serial.println("Game: Run");
#endif

	// animationTest();

	while (m_running)
	{
		update();
	}
}

void Game::update()
{
	unsigned long time = millis();

	m_entityManager.update();

	if (time > m_ballUpdate)
	{
		sUserInput();
		sMovement();
		sCollision();
		sRender();

		fps(1);
	}
}

void Game::sUserInput()
{
	auto &pInput = m_player->cInput;

	pInput->left  = (digitalRead(LEFT_BUTTON)  == HIGH);
	pInput->right = (digitalRead(RIGHT_BUTTON) == HIGH);
	pInput->jump  = (digitalRead(JUMP_BUTTON)  == HIGH);

	//#if DEBUGMODE
	//  Serial.print("Left: ");
	//  Serial.print(pInput->left);
	//  Serial.print(" Right: ");
	//  Serial.print(pInput->right);
	//  Serial.print(" Jump: ");
	//  Serial.println(pInput->jump);
	//#endif
}

void Game::sMovement()
{
	auto &pTransform = m_player->cTransform;
	auto &pInput     = m_player->cInput;
	auto &pGravity   = m_player->cGravity;

	Vec2 playerInputSpeed = {0.0f, pTransform->velocity.y};

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
}

void Game::sCollision()
{
	auto &pTransform = m_player->cTransform;
	auto &pGravity = m_player->cGravity;

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
	// TODO: Create Sprite Manager
	const uint16_t(*ptr1)[256] = &walk01;
	const uint16_t(*ptr2)[256] = &walk02;
	const uint16_t(*ptr3)[256] = &walk03;
	const uint16_t(*ptr4)[256] = &walk04;

	const uint16_t(*storage[4])[256] = {ptr1, ptr2, ptr3, ptr4};

	size_t index = 0; // sprite index
	// TODO: create animation system that can increment the index for us.

	unsigned long animUpdate = millis();
	uint8_t animRate = 100;
	Vec2 spriteSize = {16, 16};

	auto &pInput = m_player->cInput;
	auto &pTransform = m_player->cTransform;

	// only redraw the player when they have moved
	if (pTransform->pos.x != pTransform->prevPos.x ||
		pTransform->pos.y != pTransform->prevPos.y)
	{
		Vec2 diff = pTransform->prevPos - pTransform->pos;
		// black out old pixels based on the position difference between frames
		if (diff.x < 0)
		{
			m_display.fillRect(pTransform->prevPos.x, pTransform->prevPos.y, abs(diff.x), spriteSize.y, BLACK);
		}
		else if (diff.x > 0)
		{
			m_display.fillRect(pTransform->prevPos.x + spriteSize.x - diff.x, pTransform->prevPos.y, abs(diff.x), spriteSize.y, BLACK);
		}
		if (diff.y < 0)
		{
			m_display.fillRect(pTransform->prevPos.x, pTransform->prevPos.y, spriteSize.x, abs(diff.y), BLACK);
		}
		else if (diff.y > 0)
		{
			m_display.fillRect(pTransform->prevPos.x, pTransform->prevPos.y + spriteSize.y - diff.y, spriteSize.x, abs(diff.y), BLACK);
		}

		m_display.drawRGBBitmap(pTransform->pos.x, pTransform->pos.y, *(storage[index]), spriteSize.x, spriteSize.y);
	}

	fps(1);
	m_ballUpdate += m_BALL_RATE;
}

void Game::fps(unsigned int seconds)
{
	frameCount++;
	if ((millis() - lastMillis) > (seconds * 1000))
	{
		framesPerSecond = (frameCount / seconds);
		frameCount = 0;
		lastMillis = millis();

		m_display.fillRect(0, 0, 42, 8, BLACK);
		m_display.setCursor(0, 0);
		m_display.setTextColor(WHITE);
		m_display.setTextSize(1);
		m_display.print(framesPerSecond);
	}
}

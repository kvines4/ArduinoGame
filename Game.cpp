#include "Game.h"

#include "GameEngine.h"
#include "Graphics.h"

Game::Game(GameEngine* gameEngine)
	: m_gameEngine(gameEngine)
{
	init();
}

void Game::init()
{
#if DEBUGMODE_PRINT_FUNCS
	Serial.println("Game:     Init");
#endif
	// show splash screen
	m_gameEngine->display().begin();
	m_gameEngine->display().fillScreen(BLACK);
	m_gameEngine->display().setCursor(6, 13);
	m_gameEngine->display().setTextColor(RED);
	m_gameEngine->display().setTextSize(2);
	m_gameEngine->display().print(F("Arduino"));
	m_gameEngine->display().drawBitmap(10, 25, Graphics::gameLogo, 75, 26, RED);
	delay(2000);
	m_gameEngine->display().fillScreen(BLACK);

	// init game
	m_entityManager = EntityManager();
	spawnPlayer();
}

void Game::spawnPlayer()
{
#if DEBUGMODE_PRINT_FUNCS
	Serial.println("Game:     Spawn Player");
#endif

	if (m_player)
	{
		m_player->destroy();
	}
	m_player = m_entityManager.addEntity(F("player"));
	m_player->cTransform = new CTransform({48, 32}, {0 , 0});
	m_player->cBoundingBox = new CBoundingBox({1, 1});
	m_player->cGravity = new CGravity(PLAYER_GRAVITY);
	m_player->cInput = new CInput();
	m_player->cState = new CState();
	m_player->cAnimation = new CAnimation();
	m_player->cAnimation->animation = Animation(F("Run"), Graphics::playerRunLeft, 4, 2);
}

/// millis() returns the number of milliseconds passed since the Arduino board began.
/// Each call we check if enough milliseconds have passed before doing the next frame.
/// This should keep the frame rate consistent.
void Game::update()
{
	m_entityManager.update();
	sUserInput();
	sMovement();
	sCollision();
	sAnimation();
}

void Game::sUserInput()
{
	//TODO: replace this with an input action system
	auto &pInput = m_player->cInput;

	pInput->left  = m_gameEngine->m_input.buttons[BUTTON_LEFT].is_down;
	pInput->right = m_gameEngine->m_input.buttons[BUTTON_RIGHT].is_down;
	pInput->jump  = m_gameEngine->m_input.buttons[BUTTON_A].is_down;

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

	pState->state = F("air");
	pGravity->grounded = false;
	// Check if we hit the left wall
	if (pTransform->pos.x < 0)
	{
		pTransform->pos.x = 0;
		pTransform->velocity.x = 0;
	}
	// Check if we hit the right wall
	if (pTransform->pos.x > m_gameEngine->displayWidth() - SPRITE_SIZE.x)
	{
		pTransform->pos.x = m_gameEngine->displayWidth() -  SPRITE_SIZE.x;
		pTransform->velocity.x = 0;
	}
	// Check if we hit the floor
	if (pTransform->pos.y > m_gameEngine->displayHeight() - SPRITE_SIZE.y)
	{
		pState->state = F("ground");
		pTransform->pos.y = m_gameEngine->displayHeight() -  SPRITE_SIZE.y;
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
	if (pState->state == F("air"))
	{
		if(pTransform->facingRight == true)
		{
			if (pAnimation->animation.getName() != F("JumpRight"))
			{
#if DEBUGMODE_PRINT_ANIM
				Serial.println("Game:     Changed Animation: JumpRight");
#endif
				m_player->cAnimation->animation = Animation(F("JumpRight"), Graphics::playerJumpRight);
				m_playerAnimUpdated = true;
			}
		}
		else
		{
			if(pAnimation->animation.getName() != F("JumpLeft"))
			{
#if DEBUGMODE_PRINT_ANIM
				Serial.println("Game:     Changed Animation: JumpLeft");
#endif
				m_player->cAnimation->animation = Animation(F("JumpLeft"), Graphics::playerJumpLeft);
				m_playerAnimUpdated = true;
			}
		}

	}
	else if (pState->state == F("ground"))
	{
		auto& pInput = m_player->cInput;
		if ((pInput->left || pInput->right) && !(pInput->left && pInput->right))
		{
			if(pTransform->facingRight == true)
			{
				if (pAnimation->animation.getName() != F("RunRight"))
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: RunRight");
#endif
					m_player->cAnimation->animation = Animation(F("RunRight"), Graphics::playerRunRight, 4, 2);
					m_playerAnimUpdated = true;
				}
			}
			else
			{
				if (pAnimation->animation.getName() != F("RunLeft"))
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: RunLeft");
#endif
					m_player->cAnimation->animation = Animation(F("RunLeft"), Graphics::playerRunLeft, 4, 2);
					m_playerAnimUpdated = true;
				}
			}
		}
		else
		{
			if(pTransform->facingRight == true)
			{
				if (pAnimation->animation.getName() != F("StandRight"))
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: StandRight");
#endif
					m_player->cAnimation->animation = Animation(F("StandRight"), Graphics::playerStandRight);
					m_playerAnimUpdated = true;
				}
			}
			else
			{
				if (pAnimation->animation.getName() != F("StandLeft"))
				{
#if DEBUGMODE_PRINT_ANIM
					Serial.println("Game:     Changed Animation: StandLeft");
#endif
					m_player->cAnimation->animation = Animation(F("StandLeft"), Graphics::playerStandLeft);
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
			m_gameEngine->display().fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y,
							   abs(diff.x-1.5),
							   SPRITE_SIZE.y,
							   BLACK);
		}
		else if (diff.x > 0)
		{
			m_gameEngine->display().fillRect(pTransform->prevPos.x + SPRITE_SIZE.x - diff.x,
							   pTransform->prevPos.y,
							   abs(diff.x+1.5),
							   SPRITE_SIZE.y,
							   BLACK);
		}
		if (diff.y < 0)
		{
			m_gameEngine->display().fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y,
							   SPRITE_SIZE.x,
							   abs(diff.y-1.5),
							   BLACK);
		}
		else if (diff.y > 0)
		{
			m_gameEngine->display().fillRect(pTransform->prevPos.x,
							   pTransform->prevPos.y + SPRITE_SIZE.y - diff.y,
							   SPRITE_SIZE.x,
							   abs(diff.y+1.5),
							   BLACK);
		}

		m_gameEngine->display().drawRGBBitmap(pTransform->pos.x,
								pTransform->pos.y,
								pAnimation->animation.getSprite(),
								SPRITE_SIZE.x,
								SPRITE_SIZE.y);
	}
}
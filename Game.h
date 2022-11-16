#pragma once

#include "Entity.h"
#include "EntityManager.h"
#include "Common.h"
#include "Vec2.h"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>

// Game Values
#define PLAYER_SPEED   3
#define PLAYER_JUMP    -5
#define PLAYER_GRAVITY 0.5
#define FRAME_INTERVAL 16 //16.666ms for 60FPS 33.333 for 30FPS

class GameEngine;

class Game
{
private:
	bool m_running = true;

	GameEngine* m_gameEngine;
	EntityManager m_entityManager;
	Entity *m_player = nullptr;

	bool m_playerAnimUpdated = false;
	const Vec2 SPRITE_SIZE = {16, 16};

	void init();

	void spawnPlayer();

	void sMovement();
	void sUserInput();
	void sCollision();
	void sAnimation();

public:
	Game(GameEngine* gameEngine);
	void update();
	void sRender();
};
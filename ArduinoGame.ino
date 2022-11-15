#include <Arduino.h>
#include "Game.h"
#include "Common.h"

Game *game;

int main(void)
{
	init();

#if DEBUGMODE
	Serial.begin(9600);
#endif

	// to restart the game we can just exit the game loop
	for (;;)
	{
		game = new Game();
		game->run();
	}

	return 0;
}

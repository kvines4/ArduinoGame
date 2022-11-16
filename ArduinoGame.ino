#include <Arduino.h>
#include "GameEngine.h"
#include "Common.h"

GameEngine* g;

int main(void)
{
	init();

#if DEBUGMODE
	Serial.begin(9600);
#endif

	// to restart the game we can just exit the game loop
	for (;;)
	{
		g = new GameEngine();
		g->run();
	}

	return 0;
}
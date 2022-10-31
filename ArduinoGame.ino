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
#if DEBUGMODE
	// Flash on board LED when powering on so I know this code is running
	digitalWrite(LED_BUILTIN, HIGH);
	delay(300);
	digitalWrite(LED_BUILTIN, LOW);
	delay(100);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(300);
	digitalWrite(LED_BUILTIN, LOW);
	delay(100);
	digitalWrite(LED_BUILTIN, HIGH);
	delay(300);
	digitalWrite(LED_BUILTIN, LOW);
	delay(100);
#endif

		game = new Game();
		game->run();
	}

	return 0;
}

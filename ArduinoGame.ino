#include <Arduino.h>
#include "Game.h"
#include "Common.h"

Game* game;

int main(void)
{
  init();

#if DEBUGMODE
  Serial.begin(9600);
  Serial.println("Arduino: Setup");
#endif

  for (;;) {
    game = new Game();
    game->run();
  }

  return 0;
}

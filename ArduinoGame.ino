#include "Game.h"

Game* game;

void setup()
{
  game = new Game();
  
  //Serial.begin(9600);
  //Serial.println("Setup");
}

void loop()
{
  game->update();
}

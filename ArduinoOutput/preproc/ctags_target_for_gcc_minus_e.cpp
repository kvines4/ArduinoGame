# 1 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\ArduinoGame.ino"
# 2 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\ArduinoGame.ino" 2
# 3 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\ArduinoGame.ino" 2


Game *game;

int main(void)
{
 init();


 Serial.begin(9600);


 // to restart the game we can just exit the game loop
 for (;;)
 {

 // Flash on board LED when powering on so I know this code is running
 digitalWrite(13, 0x1);
 delay(300);
 digitalWrite(13, 0x0);
 delay(100);
 digitalWrite(13, 0x1);
 delay(300);
 digitalWrite(13, 0x0);
 delay(100);
 digitalWrite(13, 0x1);
 delay(300);
 digitalWrite(13, 0x0);
 delay(100);


  game = new Game();
  game->run();
 }

 return 0;
}

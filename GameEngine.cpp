#include "GameEngine.h"

#include <SPI.h>
#include <Wire.h>

GameEngine::GameEngine()
{
	init();
}

// DIRECT PIN MANIPULATION
// D – for digital pins seven to zero (bank D)
// B – for digital pins thirteen to eight (bank B)
// C – for analogue pins five to zero (bank C)
// Register C can control analogue pins seven to zero if using an Arduino with the TQFP style of ATmega328, (such as the Nano or Pro Mini).

void GameEngine::init()
{
#if DEBUGMODE_PRINT_FUNCS
	Serial.println("Engine:   Init");
#endif

	SPI.begin();

	// Setup 74HC165 connections
	DDRD |= (1 << SR_74HC165_LOAD) | (1 << SR_74HC165_CLOCK_IN) | (1 << SR_74HC165_CLOCK_ENABLE);	// pinMode(SRCLOCK_ENABLE, OUTPUT); //(SR_74HC165_LOAD & SR_74HC165_CLOCK_IN as well)
	DDRD &= ~(1 << SR_74HC165_DATA_IN);																// pinMode(SR_74HC165_DATA_IN, INPUT);
	
	m_game = new Game(this);
	m_frameStartTime = millis();
}

uint8_t GameEngine::displayWidth()
{
	return DISPLAY_WIDTH;
}

uint8_t GameEngine::displayHeight()
{
	return DISPLAY_HEIGHT;
}

Adafruit_SSD1331& GameEngine::display()
{
	return m_display;
}

void GameEngine::run()
{
#if DEBUGMODE_PRINT_FUNCS
	Serial.println("Engine:   Run");
#endif

	while (m_running)
	{
		update();
	}
}

void GameEngine::update()
{
	m_frameCurrentTime = millis();
	
	if (m_frameCurrentTime - m_frameStartTime >= FRAME_INTERVAL)
	{
		sUserInput();
		m_game->update();
		m_game->sRender();

#if DEBUGMODE_PRINT_FPS
		fps(1);
#endif
		m_frameStartTime = m_frameCurrentTime;
	}	
}

void GameEngine::sUserInput()
{
	// Write pulse to SR74HC165_LOAD pin
	PORTD &= ~(1 << SR_74HC165_LOAD);																	// digitalWrite(SR_74HC165_LOAD, LOW);
	delayMicroseconds(5);
	PORTD |= 1 << SR_74HC165_LOAD;																		// digitalWrite(SR_74HC165_LOAD, HIGH);
	delayMicroseconds(5);

	// Get data from 74HC165
	PORTD |= 1 << SR_74HC165_CLOCK_IN;																	// digitalWrite(SR_74HC165_CLOCK_IN, HIGH);
	PORTD &= ~(1 << SR_74HC165_CLOCK_ENABLE);															// digitalWrite(SR_74HC165_CLOCK_ENABLE, LOW);
	
	// Shift in all 8 bits																				// byte incoming = shiftIn(SR_74HC165_DATA_IN, SR_74HC165_CLOCK_IN, LSBFIRST);
	byte incoming = 0b00000000;
	for (uint8_t m = 1; m > 0; m <<= 1) {
		PORTD |= 1 << SR_74HC165_CLOCK_IN;																// digitalWrite(SR_74HC165_CLOCK_IN, HIGH);

		// using some macros Read in PIND and mask to get just the DATA_IN pin. If HIGH bitshift.
		if ((*portInputRegister(digitalPinToPort(SR_74HC165_DATA_IN)) & (1 << SR_74HC165_DATA_IN)) > 0)
			incoming |= m;
			
		PORTD &= ~(1 << SR_74HC165_CLOCK_IN);															// digitalWrite(SR_74HC165_CLOCK_IN, LOW);
	}
	PORTD |= 1 << SR_74HC165_CLOCK_ENABLE;																// digitalWrite(SR_74HC165_CLOCK_ENABLE, HIGH);

	// In our Inputs array, reset all button state changed values at start of frame
	for (int i = 0; i < BUTTON_COUNT; i++) {
		m_input.buttons[i].changed = false;
	}

	#define process_button(b)\
	{\
		bool is_down = bitRead(~incoming, b); \
		m_input.buttons[b].changed = (is_down != m_input.buttons[b].is_down);\
		m_input.buttons[b].is_down = is_down;\
	}\

	process_button(BUTTON_LEFT)
	process_button(BUTTON_UP)
	process_button(BUTTON_DOWN)
	process_button(BUTTON_RIGHT)
	process_button(BUTTON_A)
	process_button(BUTTON_B)
	process_button(BUTTON_START)
	process_button(BUTTON_SELECT)

#if DEBUGMODE_PRINT_SR_INPUTS
	Serial.print(m_input.buttons[7].is_down);
	Serial.print(m_input.buttons[6].is_down);
	Serial.print(m_input.buttons[5].is_down);
	Serial.print(m_input.buttons[4].is_down);
	Serial.print(m_input.buttons[3].is_down);
	Serial.print(m_input.buttons[2].is_down);
	Serial.print(m_input.buttons[1].is_down);
	Serial.println(m_input.buttons[0].is_down);

	Serial.println(incoming, BIN);
	Serial.println("___________");
#endif

// for each input
// check if state is either just pressed or just released
// call doaction in game

}

/// @brief Increment frame count each call. Display's current FPS after small delay.
/// @param seconds How many seconds between FPS checks.
void GameEngine::fps(unsigned int seconds)
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
	}
}
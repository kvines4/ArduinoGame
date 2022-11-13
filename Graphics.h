#pragma once

#include "Vector.h"

// Color definitions
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

// Tool for generating rgb uint16_t arrays
// https://sourceforge.net/projects/lcd-image-converter/files/latest/download
// Click Options, Conversion > Select ColorR5G6B5 from the list
// Click the Image tab and set Block Size to 16bit

// unsigned char is for drawBitmap (one color)
// uint16_t is for drawRGBBitmap (RGB)

namespace Graphics
{
	namespace {
		// hiding the raw sprites in the anonymous namespace and only exposing the sprite arrays
		static const uint16_t playerStandRight01[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerStandLeft01[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerJumpRight01[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0x0000, 0x0000,
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x7980, 0x7980, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x7980, 0x7980, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerJumpLeft01[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x7980, 0x7980, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x7980, 0x7980, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunRight01[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunRight02[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunRight03[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunRight04[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x7980, 0x7980, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunLeft01[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunLeft02[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunLeft03[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f, 
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
		};

		static const uint16_t playerRunLeft04[] PROGMEM = {
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0xe8e4, 0xe8e4, 0xffff, 0xffff, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x008f, 0x008f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x7980, 0x7980, 0xff4f, 0xff4f, 0xff4f, 0xff4f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f, 
			0xff4f, 0xff4f, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0x008f, 0x008f, 0xe8e4, 0xe8e4, 0xff4f, 0xff4f, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x008f, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000, 
			0x0000, 0x0000, 0x0000, 0x0000, 0x38a0, 0x38a0, 0x0000, 0x0000, 0x0000, 0x0000, 0x7980, 0x7980, 0x0000, 0x0000, 0x0000, 0x0000
		};
	}

	static const unsigned char gameLogo[] PROGMEM = {
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0x80,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc3, 0xff, 0x80,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xc3, 0xff, 0x80,
		0x0, 0x0, 0x0, 0x0, 0x3, 0xe0, 0xf, 0xc3, 0xe0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x7, 0xf0, 0x1f, 0xc1, 0xe0, 0x0,
		0x0, 0x0, 0x0, 0xf8, 0x7, 0xf0, 0x1f, 0xc1, 0xe0, 0x0,
		0x0, 0xfc, 0x1, 0xfc, 0x7, 0xf8, 0x1f, 0xc1, 0xe0, 0x0,
		0x7, 0xfc, 0x1, 0xfc, 0x3, 0xf8, 0x1f, 0xe1, 0xff, 0x80,
		0x1f, 0xfc, 0x1, 0xde, 0x3, 0xbc, 0x3d, 0xe1, 0xff, 0x80,
		0x3f, 0xfe, 0x1, 0xde, 0x3, 0xbc, 0x39, 0xe1, 0xff, 0x80,
		0x7e, 0x0, 0x3, 0xdf, 0x3, 0xde, 0x39, 0xe1, 0xfc, 0x0,
		0x7c, 0x0, 0x3, 0xcf, 0x3, 0xde, 0x39, 0xe1, 0xe0, 0x0,
		0xf8, 0x0, 0x3, 0xcf, 0x3, 0xcf, 0x39, 0xe1, 0xf0, 0x0,
		0xf8, 0x0, 0x3, 0x87, 0x83, 0xcf, 0x79, 0xe0, 0xf0, 0x0,
		0xf0, 0x7f, 0x7, 0x87, 0x83, 0xc7, 0xf1, 0xe0, 0xf0, 0xe0,
		0xf0, 0xff, 0x7, 0x83, 0xc3, 0xc7, 0xf1, 0xe0, 0xff, 0xe0,
		0xf0, 0xff, 0x7, 0xff, 0xc1, 0xc3, 0xf1, 0xf0, 0xff, 0xe0,
		0xf0, 0xff, 0x7, 0xff, 0xe1, 0xc3, 0xf0, 0xf0, 0xff, 0xe0,
		0xf8, 0xf, 0xf, 0xff, 0xe1, 0xc1, 0xe0, 0xf0, 0xe0, 0x0,
		0xf8, 0xf, 0x8f, 0x1, 0xf1, 0xe1, 0xe0, 0xf0, 0x0, 0x0,
		0x7c, 0xf, 0x8f, 0x0, 0xf1, 0xe1, 0xe0, 0x0, 0x0, 0x0,
		0x7f, 0x1f, 0x8f, 0x0, 0xf9, 0xc0, 0x0, 0x0, 0x0, 0x0,
		0x3f, 0xff, 0x9f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x1f, 0xff, 0x1f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x7, 0xfc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	};

	static const uint16_t* playerStandRight[] = { playerStandRight01 };
	static const uint16_t* playerStandLeft[]  = { playerStandLeft01 };
	static const uint16_t* playerJumpRight[]  = { playerJumpRight01 };
	static const uint16_t* playerJumpLeft[]   = { playerJumpLeft01 };
	static const uint16_t* playerRunRight[]   = { playerRunRight01, playerRunRight02, playerRunRight03, playerRunRight04 };
	static const uint16_t* playerRunLeft[]    = { playerRunLeft01, playerRunLeft02, playerRunLeft03, playerRunLeft04 };
};
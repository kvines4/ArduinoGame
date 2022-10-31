#pragma once

#include "Vector.h"

// Tool for generating rgb uint16_t arrays
// https://sourceforge.net/projects/lcd-image-converter/files/latest/download
// Click Options, Conversion > Select ColorR5G6B5 from the list
// Click the Image tab and set Block Size to 16bit

// unsigned char is for drawBitmap (one color)
// uint16_t is for drawRGBBitmap (RGB)

typedef unsigned char Sprite[];
typedef uint16_t SpriteRGB[];
typedef const uint16_t* SpriteArrayRGB[];

namespace Graphics
{
	namespace {
		// hiding the raw sprites in the anonymous namespace and only exposing the sprite arrays
		static const SpriteRGB playerStand01 PROGMEM = {
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

		static const SpriteRGB playerJumpRight01 PROGMEM = {
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

		static const SpriteRGB playerWalkRight01 PROGMEM = {
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

		static const SpriteRGB playerWalkRight02 PROGMEM = {
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

		static const SpriteRGB playerWalkRight03 PROGMEM = {
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

		static const SpriteRGB playerWalkRight04 PROGMEM = {
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

		static const SpriteRGB playerWalkLeft01 PROGMEM = {
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

		static const SpriteRGB playerWalkLeft02 PROGMEM = {
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

		static const SpriteRGB playerWalkLeft03 PROGMEM = {
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

		static const SpriteRGB playerWalkLeft04 PROGMEM = {
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

	static const Sprite gameLogo PROGMEM = {
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

	static SpriteArrayRGB playerStand		= { playerStand01 };
	static SpriteArrayRGB playerJumpRight	= { playerJumpRight01 };
	static SpriteArrayRGB playerWalkRight	= { playerWalkRight01, playerWalkRight02, playerWalkRight03, playerWalkRight04 };
	static SpriteArrayRGB playerWalkLeft	= { playerWalkLeft01, playerWalkLeft02, playerWalkLeft03, playerWalkLeft04 };
};
#line 1 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\Vec2.h"
#pragma once

#include "Common.h"

class Vec2
{
public:
	float x = 0;
	float y = 0;

	Vec2();
	Vec2(float xin, float yin);

	bool operator==(const Vec2 &rhs) const;
	bool operator!=(const Vec2 &rhs) const;

	Vec2 operator+(const Vec2 &rhs) const;
	Vec2 operator-(const Vec2 &rhs) const;
	Vec2 operator/(const float val) const;
	Vec2 operator*(const float val) const;

	Vec2 &operator+=(const Vec2 &rhs);
	Vec2 &operator-=(const Vec2 &rhs);
	Vec2 &operator*=(const float val);
	Vec2 &operator/=(const float val);

	// float dist(const Vec2& rhs) const;
};

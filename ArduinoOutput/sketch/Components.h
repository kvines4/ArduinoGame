#line 1 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\Components.h"
#pragma once

#include "Animation.h"
#include "Vec2.h"
#include "Common.h"

class CTransform
{
public:
	Vec2 pos = {0.0, 0.0};
	Vec2 prevPos = {0.0, 0.0};
	Vec2 velocity = {0.0, 0.0};

	CTransform(const Vec2 &p, const Vec2 &v)
		: pos(p), velocity(v) {}
};

class CBoundingBox
{
public:
	Vec2 size;
	Vec2 halfSize;
	CBoundingBox() {}
	CBoundingBox(const Vec2 &s)
		: size(s), halfSize(s / 2) {}
};

class CInput
{
public:
	bool jump = false;
	bool left = false;
	bool right = false;

	CInput() {}
};

class CGravity
{
public:
	float gravity = 0;
	bool grounded = false;
	CGravity() {}
	CGravity(float g) : gravity(g) {}
};

class CState
{
public:
	String state = "air";
	CState() {}
	CState(const String& s) : state(s) {}
};

// class CAnimation
// {
// public:
// 	Animation animation;
// 	CAnimation() {}
// 	CAnimation(const Animation& animation)
// 		: animation(animation) {}
// };
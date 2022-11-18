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
	bool facingRight = true;

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
	bool jump	 = false;
	bool canJump = false;
	bool left	 = false;
	bool right	 = false;

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

enum stateType {
	Air,
	Ground
};

class CState
{
public:
	stateType state;
	CState() {}
	CState(stateType s) : state(s) {}
};

class CAnimation
{
public:
	Animation animation;
	CAnimation() {}
	CAnimation(const Animation& animation)
		: animation(animation) {}
};
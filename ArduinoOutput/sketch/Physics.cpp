#line 1 "c:\\Users\\kvines4\\source\\repos\\Personal\\Arduino\\ArduinoGame\\Physics.cpp"
// #include "Physics.h"

// #include "Components.h"
// #include "Entity.h"

// //float Physics::DEGTORAD = 0.017453f;

// Vec2 Physics::GetOverlap(Entity a, Entity b)
// {
// 	// both entities require a bounding box to collide
// 	if (!a->cBoundingBox() || !b->cBoundingBox()) { return Vec2(0, 0); }

// 	// get the (x,y) distances between the two bounding boxes
// 	Vec2 delta = (a->cTransform().pos - b->cTransform().pos).abs();

// 	// calculate the vertical and horizontal overlaps
// 	Vec2 boxSize = (a->cBoundingBox().halfSize + b->cBoundingBox().halfSize); 

// 	// return if overlapping in both x&y axis, otherwise return 0
// 	return Vec2(boxSize.x - delta.x, boxSize.y - delta.y);
// }

// Vec2 Physics::GetPreviousOverlap(Entity a, Entity b)
// {
// 	// both entities require a bounding box to collide
// 	if (!a.hasComponent<CBoundingBox>() || !b.hasComponent<CBoundingBox>()) { return Vec2(0, 0); }

// 	// get the (x,y) distances between the two bounding boxes
// 	Vec2 delta = (a->cTransform().prevPos - b->cTransform().prevPos).abs();

// 	// calculate the vertical and horizontal overlaps
// 	Vec2 boxSize = (a->cBoundingBox().halfSize + b->cBoundingBox().halfSize);

// 	// return if overlapping in both x&y axis, otherwise return 0
// 	return Vec2(boxSize.x - delta.x, boxSize.y - delta.y);
// }

// bool Physics::IsInside(const Vec2& pos, Entity e)
// {
// 	// if the entity doesn't have an animation, we can't be 'inside' it
// 	if (!e.hasComponent<CAnimation>()) { return false; }

// 	auto halfSize = e->cAnimation>().animation.getSize() / 2;
	
// 	// determine the delta vector (distance) between both entities
// 	Vec2 delta = (e->cTransform>().pos - pos).abs();

// 	// uf the click is within the x and y bounds of the halfsize, we're inside
// 	return (delta.x <= halfSize.x) && (delta.y <= halfSize.y);
// }

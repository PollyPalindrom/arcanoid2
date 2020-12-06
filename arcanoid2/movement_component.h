#pragma once
#include "vec2.h"
#include "i_component.h"
class MovementComponent : public IComponent {
public:
	Vec2 speed;
	Vec2 direction;
	explicit MovementComponent(const Vec2& speed, const Vec2& dir = ZeroVec2) : speed(speed), direction(dir) {}
};
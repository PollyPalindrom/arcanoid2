#pragma once
#include "vec2.h"
#include "i_component.h"

class TransformComponent : public IComponent {
public:
	Vec2 position;
	explicit TransformComponent(const Vec2& position) : position(position) {}
};
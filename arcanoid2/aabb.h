#pragma once
#include "vec2.h"
#include <ostream>
class AABB {
public:
    const Vec2 min; // ������� ����� ����
	const Vec2 max; // ������ ������ ����

	AABB(const Vec2& min, const Vec2& max) : min(min), max(max) {}

	Vec2 Center() const;

	friend std::ostream& operator<<(std::ostream& os, const AABB& aabb);
};
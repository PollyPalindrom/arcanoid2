#pragma once
#include "i_component.h"

class BrickComponent : public IComponent {
public:
	int hp = 1;
	explicit BrickComponent(int hp = 1) :hp(hp) {}
};
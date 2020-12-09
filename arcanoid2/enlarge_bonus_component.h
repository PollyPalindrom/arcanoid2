#pragma once
#include "i_component.h"
#include <string>
#include "entity.h"
class EnlargeBonusComponent : public IComponent {
public:
	int power;
	explicit EnlargeBonusComponent(int power): power(power){}
};
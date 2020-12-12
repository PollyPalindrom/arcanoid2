#pragma once
#include "i_component.h"
#include <string>
#include "entity.h"
class ResizeBonusComponent : public IComponent {
public:
	double power;
	explicit ResizeBonusComponent(double power): power(power){}
};
#pragma once
#include "i_component.h"
#include "vec2.h"
class MultiBallBonusComponent: public IComponent{
public:
	int multi;
	MultiBallBonusComponent(int multi) : multi(multi) {};
};
#pragma once
#include "buttons.h"
#include "i_component.h"
class PlayerControlComponent : public IComponent {
public:
	double border_size = 6;
	Button left = Button::KEY_LEFT;
	Button right = Button::KEY_RIGHT;
	Button up = Button::KEY_UP;
	Button down = Button::KEY_DOWN;
};
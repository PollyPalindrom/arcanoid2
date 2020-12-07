#pragma once
#include "i_component.h"
#include "vec2.h"
//физичность
class RigidBodyComponent : public IComponent {
public:
	double mass = 1.0;
	bool is_kinematic = true;
};
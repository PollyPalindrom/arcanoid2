#pragma once
#include "i_system.h"
#include "entity.h"
class PhysicsSystem : public ISystem {
public:
	void Update(Context& ctx, Entity* entity) override;
	bool Filter(Entity* entity) const override;
};
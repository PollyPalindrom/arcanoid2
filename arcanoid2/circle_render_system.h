#pragma once
#include "i_system.h"
#include <memory>

class CircleRenderSystem : public ISystem {
protected:
	void Update(Context& ctx, Entity* entity) override;
	bool Filter(Entity* entity) const override;
};
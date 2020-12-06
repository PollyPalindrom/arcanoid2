#pragma once
#include "i_system.h"
#include "entity.h"

class TextureRenderSystem : public ISystem {
protected:
	void Update(Context& ctx, Entity* entity) override;
	bool Filter(Entity* entity) const override;
};
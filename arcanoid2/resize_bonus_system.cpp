#include "resize_bonus_system.h"
#include "resize_bonus_component.h"
#include "rect_collider_component.h"
#include <iostream>
#include "rectangle_render_component.h"
void ApplyBonus(Entity* entity, ResizeBonusComponent* bc) {
	auto render = entity->Get<RectangleRenderComponent>();
	auto box = entity->Get<RectColliderComponent>();
	box->size.x *= bc->power;
	render->size.x *= bc->power;
}
bool ResizeBonusSystem::Filter(Entity* entity) const
{
	return entity->Contains<ResizeBonusComponent>() && entity->Contains<RectColliderComponent>();
}

void ResizeBonusSystem::Update(Context& ctx, Entity* entity)
{
	auto bc = entity->Get<ResizeBonusComponent>();
	auto rc = entity->Get<RectColliderComponent>();
	for (auto& collision : rc->GetCollisions()) {
		if (collision.entity->GetTag() != "platform") continue;
		rc->is_sleeping = true;
		ApplyBonus(collision.entity, bc.get());
	}
}

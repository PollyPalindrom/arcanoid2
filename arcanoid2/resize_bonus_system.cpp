#include "resize_bonus_system.h"
#include "resize_bonus_component.h"
#include "rect_collider_component.h"
#include <iostream>
#include "rectangle_render_component.h"
#include "audio_component.h"
void ApplyBonus(Entity* entity, Entity* bonus) {
	auto bc = bonus->Get<ResizeBonusComponent>();
	auto render = entity->Get<RectangleRenderComponent>();
	auto box = entity->Get<RectColliderComponent>();
	if ((box->size.x < 84 && bc->power==1.25)|| (box->size.x>10 && bc->power==0.5)) {
		box->size.x *= bc->power;
		render->size.x *= bc->power;
	}
	bonus->Get<AudioComponent>()->Play();

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
		if (collision.entity->GetTag() != 'p') continue;
		rc->is_sleeping = true;
		ApplyBonus(collision.entity, entity);
	}
}

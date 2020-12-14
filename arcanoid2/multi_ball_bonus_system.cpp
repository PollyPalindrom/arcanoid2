#include "multi_ball_bonus_system.h"
#include "resize_bonus_component.h"
#include "rect_collider_component.h"
#include"multi_ball_bonus_component.h"
#include "rectangle_render_component.h"
#include "ball.h"
#include "transform_component.h"
#include "entity_manager.h"
#include "movement_component.h"
void ApplyBonus( MultiBallBonusComponent *bc,EntityManager*entityManager, Entity*platform) {
	auto ball = entityManager->Findbytag('b');
	auto pos= ball->Get<TransformComponent>()->position;
	auto dir = ball->Get<MovementComponent>()->direction;
	for (int i = 1; i < bc->multi; i++) {
		CreateBall2(entityManager,pos,Vec2(-1,1)*dir);
	}
}
void MultiBallBonusSystem::Update(Context& ctx, Entity* entity)
{
	auto bc = entity->Get<MultiBallBonusComponent>();
	auto rc = entity->Get<RectColliderComponent>();
	for (auto& collision : rc->GetCollisions()) {
		if (collision.entity->GetTag() != 'p') continue;
		rc->is_sleeping = true;
		ApplyBonus(bc.get(),GetEntityManager(),collision.entity);
	}
}

bool MultiBallBonusSystem::Filter(Entity* entity) const
{
	return entity->Contains<MultiBallBonusComponent>() && entity->Contains<RectColliderComponent>();
}

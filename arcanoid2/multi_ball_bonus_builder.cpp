#include "multi_ball_bonus_builder.h"
#include "palette.h"
#include "transform_component.h"
#include "rect_collider_component.h"
#include "movement_component.h"
#include "multi_ball_bonus_component.h"
#include "rectangle_render_component.h"

void MultiBallBonusBuiilder::Build(EntityManager* entityManager, Vec2 pos)
{
    auto bonus = entityManager->CreateEntity();
    auto size = Vec2(13, 6);
    auto speed = Vec2(200, 200);
    auto dir = DownVec2;
    auto color = PALETTE[9];
    bonus->Add<TransformComponent>(pos);
    bonus->Add<RectColliderComponent>(size);
    bonus->Add<MovementComponent>(speed, dir);
    bonus->Add<MultiBallBonusComponent>(2);
    bonus->Add<RectangleRenderComponent>(size, color, true);
}

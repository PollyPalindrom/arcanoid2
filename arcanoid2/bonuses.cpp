#include "bonuses.h"
#include "entity.h"
#include "transform_component.h"
#include "rect_collider_component.h"
#include "movement_component.h"
#include "resize_bonus_component.h"
#include "palette.h"
#include "rectangle_render_component.h"
void CreateBonus(const Vec2& pos, double power, EntityManager*entityManager) {
    auto bonus = entityManager->CreateEntity();
    auto size = Vec2(10, 10);
    auto speed = Vec2(200, 200);
    auto dir = DownVec2;
    bonus->Add<TransformComponent>(pos);
    bonus->Add<RectColliderComponent>(size);
    bonus->Add<MovementComponent>(speed, dir);
    bonus->Add<ResizeBonusComponent>(power);
    bonus->Add<RectangleRenderComponent>(size, PALETTE[11], true);
}

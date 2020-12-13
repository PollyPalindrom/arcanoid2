#include "brick.h"
#include "transform_component.h"
#include "rectangle_render_component.h"
#include "rect_collider_component.h"
#include "brick_component.h"
#include "palette.h"
void CreateBrick(EntityManager*entityManager,const Vec2& pos, const Vec2& size) {
    auto brick = entityManager->CreateEntity();
    brick->SetTag("brick");
    brick->Add<TransformComponent>(pos);
    brick->Add<RectangleRenderComponent>(size, PALETTE[15]);
    brick->Add<RectColliderComponent>(size);
    brick->Add<BrickComponent>();
}
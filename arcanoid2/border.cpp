#include "border.h"
#include "transform_component.h"
#include "palette.h"
#include "rectangle_render_component.h"
#include "rect_collider_component.h"
void CreateBorder(EntityManager*entityManager,const Vec2& size, const Vec2& pos) {
    auto border = entityManager->CreateEntity();
    border->Add<TransformComponent>(pos);
    border->Add<RectangleRenderComponent>(size, PALETTE[13]);
    border->Add<RectColliderComponent>(size);
}
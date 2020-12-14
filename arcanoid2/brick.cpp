#include "brick.h"
#include "transform_component.h"
#include "rectangle_render_component.h"
#include "rect_collider_component.h"
#include "brick_component.h"
#include "palette.h"
RGBA ColorHP(int hp) {
    if (hp == 1) return RGBA{ 255,204,170,255 };
    else if (hp == 2) return RGBA{ 200,160,110,255 };
    else return RGBA{131,118,156,255};
}
void CreateBrick(EntityManager*entityManager,const Vec2& pos, const Vec2& size, int hp) {
    auto brick = entityManager->CreateEntity();
    brick->SetTag('r');
    brick->Add<TransformComponent>(pos);
    brick->Add<RectangleRenderComponent>(size, ColorHP(hp));
    brick->Add<RectColliderComponent>(size);
    brick->Add<BrickComponent>(hp);
}
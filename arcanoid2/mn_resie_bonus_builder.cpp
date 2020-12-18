#include "mn_resie_bonus_builder.h"
#include "palette.h"
#include "transform_component.h"
#include "rect_collider_component.h"
#include "movement_component.h"
#include "resize_bonus_component.h"
#include "rectangle_render_component.h"
#include <ctime>
#include "nextnum.h"
#include "audio_component.h"
void MnResizeBonusBuiilder::Build(EntityManager* entityManager, Vec2 pos)
{
    double power=0.5;
    auto bonus = entityManager->CreateEntity();
    auto size = Vec2(13, 6);
    auto speed = Vec2(200, 200);
    auto dir = DownVec2;
    auto color = PALETTE[11];
    if (power < 1) color = PALETTE[8];
    bonus->Add<AudioComponent>("bonus", false);
    bonus->Add<TransformComponent>(pos);
    bonus->Add<RectColliderComponent>(size);
    bonus->Add<MovementComponent>(speed, dir);
    bonus->Add<ResizeBonusComponent>(power);
    bonus->Add<RectangleRenderComponent>(size, color, true);
}

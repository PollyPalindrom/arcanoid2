#include "input.h"
#include "time.h"
#include "drawing.h"
#include "player_control_system.h"
#include "transform_component.h"
#include "player_control_component.h"
#include "movement_component.h"
#include <iostream>
#include "rect_collider_component.h"
void PlayerControlSystem::Update(Context& ctx, Entity* entity) {
    auto tc = entity->Get<TransformComponent>();
    auto pcc = entity->Get<PlayerControlComponent>();
    auto mc = entity->Get<MovementComponent>();
    auto rcc = entity->Get<RectColliderComponent>();
    mc->direction = ZeroVec2;

    if (IsPressed(ctx, pcc->left) && tc->position.x > pcc->border_size) {
        mc->direction = LeftVec2;
    }

    if (IsPressed(ctx, pcc->right) && tc->position.x < GetDisplayWidth(ctx) - rcc->GetSize().x - pcc->border_size) {
        mc->direction = RightVec2;
    }
}
bool PlayerControlSystem::Filter(Entity* entity) const {
        return entity->Contains<PlayerControlComponent>()
            && entity->Contains<PlayerControlComponent>()&&
            entity->Contains<MovementComponent>() && entity->Contains<RectColliderComponent>();
}

#pragma once
#include "i_system.h"
#include "transform_component.h"
#include "rect_collider_component.h"
class CollisionSystem : public ISystem {
protected:
    void OnUpdate(Context& ctx) override;
    void Update(Context& ctx, Entity* entity) override;
    bool Filter(Entity* entity) const override {
        return entity->Contains<TransformComponent>() && entity->Contains<RectColliderComponent>();
    }
};
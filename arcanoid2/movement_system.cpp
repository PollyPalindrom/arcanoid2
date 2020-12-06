#include "movement_system.h"
#include "movement_component.h"
#include "transform_component.h"
#include "time.h"
#include "entity.h"
bool MovementSystem::Filter(Entity* entity) const {
    return entity->Contains<TransformComponent>()
        && entity->Contains<MovementComponent>();
}
void MovementSystem::Update(Context& ctx, Entity* entity) {
    auto tc = entity->Get<TransformComponent>();
    auto mc = entity->Get<MovementComponent>();

    tc->position += mc->direction * mc->speed * GetDelta(ctx);
}
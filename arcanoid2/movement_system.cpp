#include "movement_system.h"
#include "movement_component.h"
#include "transform_component.h"
#include "time.h"
#include "entity.h"
#include <time.h>
bool MovementSystem::Filter(Entity* entity) const {
    return entity->Contains<TransformComponent>()
        && entity->Contains<MovementComponent>();
}
void MovementSystem::Update(Context& ctx, Entity* entity) {
    double dt;
    dt = GetDelta(ctx);
    if (dt > 0.03) dt = 0.03;
    auto tc = entity->Get<TransformComponent>();
    auto mc = entity->Get<MovementComponent>();
    tc->position += mc->direction * mc->speed*dt;
}
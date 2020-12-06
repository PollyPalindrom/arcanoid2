#include "physics_system.h"
#include "rigid_body_component.h"
#include "transform_component.h"
#include "rect_collider_component.h"

bool PhysicsSystem::Filter(Entity* entity) const {
    return entity->Contains<TransformComponent>()
        && entity->Contains<RectColliderComponent>()
        && entity->Contains<RigidBodyComponent>();
}
void PhysicsSystem::Update(Context& ctx, Entity* entity) {
    auto tc = entity->Get<TransformComponent>();
    auto cc = entity->Get<RectColliderComponent>();
    auto rc = entity->Get<RigidBodyComponent>();

    if (!rc->is_kinematic) { return; } // the object is static, we cannot move it
    Vec2 v(0, 0);
    for (const auto& collision : cc->GetCollisions()) {
        // TODO: somehow calculate the force to move
        v += collision.manifold.normal * collision.manifold.penetration;
    }

    tc->position += v;
}
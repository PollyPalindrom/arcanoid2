#include "collision_system.h"
#include "colliders.h"
#include "manifold.h"
#include "entity_manager.h"
#include <iostream>
//берёт объекты, которые обладают свойствами коллайдера и позиции.
void CollisionSystem::Update(Context& ctx, Entity* entity) {
    auto tc = entity->Get<TransformComponent>();
    auto cc = entity->Get<RectColliderComponent>();
    auto box = cc->GetAABB(tc->position);
    // с кем ещё объект пересекается проверяет. Если это не сам объект, то производится пересечение
    if (cc->is_sleeping) return;
    GetEntityManager()->ForEach([cc, box, entity](Entity* e) {
        if (!e->Contains<RectColliderComponent>() || e->GetId() == entity->GetId()) { return; }
        auto tc2 = e->Get<TransformComponent>();
        auto cc2 = e->Get<RectColliderComponent>();
        auto box2 = cc2->GetAABB(tc2->position);

        auto manifold = Intersection(box, box2);
        if (manifold.intersecting) {
            cc->Collide(e, manifold);
        }
        });
}
void CollisionSystem::OnUpdate(Context& ctx) {
    GetEntityManager()->ForEach([](Entity* e) {
        if (e->Contains<RectColliderComponent>()) {
            e->Get<RectColliderComponent>()->Clear();
        }
        });
}
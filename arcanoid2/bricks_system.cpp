#include "bricks_system.h"
#include "brick_component.h"
#include "rect_collider_component.h"
#include "ball_component.h"
#include "entity_manager.h"
#include "counter.h"
#include <iostream>

bool BricksSystem::Filter(Entity* entity) const {
    return entity->Contains<BrickComponent>() && entity->Contains<RectColliderComponent>();
}
void BricksSystem::Update(Context& ctx, Entity* entity) {
    auto bc = entity->Get<BrickComponent>();
    auto rc = entity->Get<RectColliderComponent>();

    for (const auto& collision : rc->GetCollisions()) {
        if (collision.entity->Contains<BallComponent>()) {
            to_delete.push_back(entity->GetId());
        }
    }
}
void BricksSystem::OnPostUpdate(Context& ctx) {
    for (auto id : to_delete) {
        GetEntityManager()->DeleteEntity(id);
    }
    to_delete.clear();
    Counter<BrickComponent> counter;
    GetEntityManager()->ForEachMutable(counter);
    if (counter.get() == 0) {
        std::cout << "Game Win" << std::endl;
        sceneManager->SetScene(3);
    }
}
BricksSystem::BricksSystem(SceneManager* sceneManager) : sceneManager(sceneManager) {}

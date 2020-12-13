#include "ball_control_system.h"
#include "ball_component.h"
#include "transform_component.h"
#include "movement_component.h"
#include "rigid_body_component.h"
#include "rect_collider_component.h"
#include "numbers.h"
#include <iostream>
#include "entity_manager.h"
#include "drawing.h"
#include "lifecycle.h"
#include "counter.h"
#include "platform_component.h"
//проверка всех коллизий шарика со всеми объектами. В зависимости от нормали отправляем в противоположном направлении. Он края платформы-хитро
void BallControlSystem::Update(Context& ctx, Entity* entity) {
    auto tc = entity->Get<TransformComponent>();
    auto mc = entity->Get<MovementComponent>();
    auto rc = entity->Get<RigidBodyComponent>();
    auto cc = entity->Get<RectColliderComponent>();

    if (cc->AnyCollisions()) {
        for (const auto& collision : cc->GetCollisions()) {
            auto v = collision.manifold.normal;
            if (v.x > 0 || v.x < 0) {
                mc->direction.x *= -1;
            }
            if (v.y > 0 || v.y < 0) {
                mc->direction.y *= -1;
            }
            if (collision.entity->Contains<PlatformComponent>()) {
                auto rc_p = collision.entity->Get<RectColliderComponent>();
                auto width = rc_p->GetSize().x / 3.5;
                if (std::abs(collision.manifold.vec.x) > width) {
                    mc->direction.x *= -1;
                }
            }
        }
    }
}
bool BallControlSystem::Filter(Entity* entity) const {
    return entity->Contains<BallComponent>()
        && entity->Contains<TransformComponent>()
        && entity->Contains<MovementComponent>()
        && entity->Contains<RectColliderComponent>()
        && entity->Contains<RigidBodyComponent>();
}
void BallControlSystem::OnUpdate(Context& ctx) {
    Counter<BallComponent> counter;
    GetEntityManager()->ForEachMutable(counter);
    if (counter.get() == 0) {
        std::cout << "Game Over" << std::endl;
        sceneManager->SetScene("game_over");
    }
}
BallControlSystem::BallControlSystem(SceneManager* sceneManager) : sceneManager(sceneManager) {}

#include "platform.h"
#include "movement_component.h"
#include "transform_component.h"
#include "rect_collider_component.h"
#include "palette.h"
#include "rectangle_render_component.h"
#include "player_control_component.h"
#include "platform_component.h"
#include "audio_component.h"
void CreatePlatform(EntityManager* entityManager, const Vec2& platform_pos, const Vec2& platform_size) {
    auto platform_speed = 290;
    auto platform = entityManager->CreateEntity();
    platform->SetTag('p');
    platform->Add<PlayerControlComponent>();
    platform->Add<PlatformComponent>();
    platform->Add<MovementComponent>(Vec2(platform_speed, 0));
    platform->Add<TransformComponent>(platform_pos);
    platform->Add<RectColliderComponent>(platform_size);
    platform->Add<RectangleRenderComponent>(platform_size, PALETTE[10], true);
}
void CreateMusic(EntityManager* entityManager, const std::string name) {
    auto music = entityManager->CreateEntity();
    music->SetTag('m');
    music->Add<AudioComponent>(name,true,-1);
    music->Get<AudioComponent>()->Play();
}
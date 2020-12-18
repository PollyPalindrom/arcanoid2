#include "ball.h"
#include "engine.h"
#include "game_scene.h"
#include "entity_manager.h"
#include "rect_collider_component.h"
#include "transform_component.h"
#include "palette.h"
#include "circle_render_component.h"
#include "movement_component.h"
#include "ball_component.h"
#include "rigid_body_component.h"
#include "audio_component.h"
void CreateBall(EntityManager*entityManager,const Vec2& platform_pos, const Vec2& platform_size) {
    auto br = 3.0;
    auto ball_pos = Vec2(platform_pos.x + platform_size.x / 2 - br / 2, platform_pos.y - br);
    CreateBall2(entityManager, ball_pos, Vec2(1,-1).Normalize());
}
void CreateBall2(EntityManager* entityManager, const Vec2& ball_pos, const Vec2 dir) {
    auto br = 3.0;
    auto ball_speed = 180.0;
    auto ball_size = Vec2(br, br);
    auto ball = entityManager->CreateEntity();
    ball->SetTag('b');
    ball->Add<AudioComponent>("hit", false,0);
    ball->Add<TransformComponent>(ball_pos);
    ball->Add<RectColliderComponent>(ball_size);
    ball->Add<MovementComponent>(Vec2(ball_speed, ball_speed), dir);
    ball->Add<CircleRenderComponent>(br, PALETTE[5], true);
    ball->Add<BallComponent>();
    ball->Add<RigidBodyComponent>();
}
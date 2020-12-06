#include "game_scene.h"
#include "ball_control_system.h"
#include "bricks_system.h"
#include "circle_render_system.h"
#include "collision_system.h"
#include "movement_system.h"
#include "physics_system.h"
#include "player_control_system.h"
#include "rectangle_render_system.h"
#include "texture_render_system.h"

void GameScene::InitSystems() {
    engine->GetSystemManager()
        ->AddSystem<CollisionSystem>()
        ->AddSystem<PlayerControlSystem>()
        ->AddSystem<BallControlSystem>(GetSceneManager())
        ->AddSystem<PhysicsSystem>()
        ->AddSystem<MovementSystem>()
        ->AddSystem<BricksSystem>(GetSceneManager())
        ->AddSystem<CircleRenderSystem>()
        ->AddSystem<TextureRenderSystem>()
        ->AddSystem<RectangleRenderSystem>();
}
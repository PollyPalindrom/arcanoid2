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
#include "shredder_system.h"
#include "resize_bonus_system.h"
//регестрация систем
void GameScene::InitSystems() {
    engine->GetSystemManager()
        ->AddSystem<CollisionSystem>()//обработка столкновений
        ->AddSystem<PlayerControlSystem>()//обработка управления
        ->AddSystem<BallControlSystem>(GetSceneManager())//управление шариком
        ->AddSystem<PhysicsSystem>()//обработка физики 
        ->AddSystem<MovementSystem>()
        ->AddSystem<ShredderSystem>()
        ->AddSystem<ResizeBonusSystem>()
        ->AddSystem<BricksSystem>(GetSceneManager())
        ->AddSystem<CircleRenderSystem>()
        ->AddSystem<TextureRenderSystem>()
        ->AddSystem<RectangleRenderSystem>();
}
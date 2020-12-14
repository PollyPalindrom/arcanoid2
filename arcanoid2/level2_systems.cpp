#include "level2_creator.h"
#include "engine.h"
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
#include "scene.h"
#include "multi_ball_bonus_system.h"
//����������� ������
void Level2Creator::InitSystems() {
    engine->GetSystemManager()
        ->AddSystem<CollisionSystem>()//��������� ������������
        ->AddSystem<PlayerControlSystem>()//��������� ����������
        ->AddSystem<BallControlSystem>(sceneManager)//���������� �������
        ->AddSystem<PhysicsSystem>()//��������� ������ 
        ->AddSystem<MovementSystem>()
        ->AddSystem<ShredderSystem>()
        ->AddSystem<ResizeBonusSystem>()
        ->AddSystem<MultiBallBonusSystem>()
        ->AddSystem<BricksSystem>(sceneManager)
        ->AddSystem<CircleRenderSystem>()
        ->AddSystem<TextureRenderSystem>()
        ->AddSystem<RectangleRenderSystem>();
}
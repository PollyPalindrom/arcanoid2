#include "level1_creator.h"
#include "drawing.h"
#include "game_scene.h"
#include "transform_component.h"
#include "palette.h"
#include "rectangle_render_component.h"
#include "rect_collider_component.h"
#include "brick_component.h"
#include "platform.h"
#include "ball.h"
#include "brick.h"
#include "border.h"
void Level1Creator::InitEntities() {
    auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16.0) / 2, GetDisplayHeight(ctx) - 20.0);
    auto platform_size = Vec2(42, 7);

    CreatePlatform(engine->GetEntityManager(),platform_pos, platform_size);
    CreateBall(engine->GetEntityManager(),platform_pos, platform_size);

    CreateBricks();
    CreateBorders();
    CreateMusic(engine->GetEntityManager(),"music1");
}
void Level1Creator::CreateBricks() {

    for (int i = 0; i < 13; i++) {
        for (int j = 1; j < 4; j++) {
            auto size = Vec2(15, 8);
            auto hp = 1;
            CreateBrick(engine->GetEntityManager(), Vec2(8 + i * (size.x + 1), 12 + j * (size.y + 1)), size, hp);
        }
    }
}

void Level1Creator::CreateBorders() {
    CreateBorder(engine->GetEntityManager(), Vec2(GetDisplayWidth(ctx), 6), Vec2(0, 0));  // top
    CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(0, 0));                         // left
    CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(GetDisplayWidth(ctx) - 6, 0));  // right
}



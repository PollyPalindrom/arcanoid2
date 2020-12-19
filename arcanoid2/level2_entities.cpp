#include "level2_creator.h"
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
void Level2Creator::InitEntities() {
    auto platform_pos = Vec2((GetDisplayWidth(ctx) - 16.0) / 2, GetDisplayHeight(ctx) - 20.0);
    auto platform_size = Vec2(42, 7);

    CreatePlatform(engine->GetEntityManager(), platform_pos, platform_size);
    CreateBall(engine->GetEntityManager(), platform_pos, platform_size);
    CreateBall(engine->GetEntityManager(), platform_pos+Vec2(0,-10), platform_size);
    CreateBricks();
    CreateBorders();
    CreateMusic(engine->GetEntityManager(), "music1");
}
void Level2Creator::CreateBricks() {

    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 13; j++) {
            if (i > j)  continue;
            auto size = Vec2(15, 8);
            int hp = 1;
            if (j == 12) hp == 2;
            CreateBrick(engine->GetEntityManager(), Vec2(8 + i * (size.x + 1), 12 + j * (size.y + 1)), size, hp);
        }
    }
}
void Level2Creator::CreateBorders() {
    CreateBorder(engine->GetEntityManager(), Vec2(GetDisplayWidth(ctx), 6), Vec2(0, 0));  // top
    CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(0, 0));                         // left
    CreateBorder(engine->GetEntityManager(), Vec2(6, GetDisplayHeight(ctx)), Vec2(GetDisplayWidth(ctx) - 6, 0));  // right
}



#include "arcanoid1.h"
void Arcanoid::OnCreate(Context& ctx) {
    platform = new Platform(GetDisplayWidth(ctx) / 2 - 24, GetDisplayHeight(ctx) - 10, 48, 6, 300);
    balls.push_back(new Ball(platform->x + platform->width / 2 - 2, platform->y - 4, 4, 150, platform, bricks));
    float brick_width = 16, brick_height = 8;
    for (int i = 0; i < 15; i++) {
        for (int j = 1; j < 4; j++) {
            RGBA color = PALETTE[i * j % PALETTE_LEN];
            bricks.push_back(new Brick(brick_width * i, brick_height * j, brick_width, brick_height, color));
        }
    }
}
void Arcanoid::OnRender(Context& ctx) {
    if (color != nullptr) {
        DrawClearScreen(ctx, *color);
        return;
    }
    HandlePause(ctx);
    if (pause) return;
    DrawClearScreen(ctx, RGBA{ 29, 43, 83, 255 });
    platform->DrawPlatform(ctx);
    platform->MovePlatform(ctx);
    auto aliveballs = 0;
    for (auto& ball : balls) {
        if (ball->IsShouldDestroy()) continue;
        ball->DrawBall(ctx);
        ball->MoveBall(ctx);
        aliveballs++;
    }
    for (auto& brick : bricks) {
        if (!brick->IsDestroyed())brick->DrawBrick(ctx);
    }
    if (aliveballs < 1) Win();
    if (aliveballs == 0) Lose();
}
void Arcanoid::HandlePause(Context& ctx) {
    if (IsPressed(ctx, Button::KEY_SPACE) && pause) pause = false;
}
void Arcanoid::Lose() {
    color = new RGBA{ 255,255,0,0 };
}
void Arcanoid::Win() {
    color = new RGBA{ 0,255,0,0 };
}
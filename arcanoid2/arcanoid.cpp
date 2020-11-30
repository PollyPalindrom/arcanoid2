#include"animation.h"
#include "application_listener.h"
#include "buttons.h"
#include "color.h"
#include "drawing.h"
#include "import_sprites.h"
#include "input.h"
#include "lifecycle.h"
#include "log.h"
#include "palette.h"
#include "sound.h"
#include "text.h"
#include"time.h"
#include "whycpp.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include <vector>

struct Rectangle {
    float left, right, bottom, top;
    Rectangle(float left, float right,float top, float bottom): left(left), right(right),top(top), bottom(bottom){}
};
bool IsInside(float value, float min, float max) {
    return value >= min && value <= max;
}
bool IsIntersect(Rectangle& rect1, Rectangle& rect2) {
    bool x = IsInside(rect1.left, rect2.left, rect2.right) || IsInside(rect2.left, rect1.left, rect1.right);
    bool y = IsInside(rect1.top, rect2.bottom, rect2.top) || IsInside(rect2.top, rect1.bottom, rect1.top);
    return x && y;
}
class Platform
{
public:
    
    float x, y, width, height, speed_x;
    RGBA const color = RGBA{ 255, 163, 0, 255 };
    Platform(float x, float y, float width, float height, float speed_x) : x(x), y(y), width(width), height(height), speed_x(speed_x){}
    void DrawPlatform(Context& ctx) {
        DrawRectFill(ctx, x, y, width, height, color);
    }
    void MovePlatform(Context& ctx) {
        if (IsPressed(ctx, Button::KEY_LEFT)&& x>0) {
            x -= speed_x*GetDelta(ctx);
        }
        if (IsPressed(ctx, Button::KEY_RIGHT)&& x<GetDisplayWidth(ctx)-width) {
            x += speed_x * GetDelta(ctx);
        }
    }
};
class Brick {
public:
    float x, y, width, height;
    const RGBA color;
    int hp = 1;
    Brick(float x, float y, float width, float height, const RGBA& color) : x(x), y(y), width(width), height(height), color(color) {}
    void DrawBrick(Context& ctx) {
        DrawRectFill(ctx, x + 1, y + 1, width - 2, height - 2, color);
    }
    Rectangle Rect() const{
        return { x, x + width,y + height , y};
    }
    void Damage() {
        hp--;
    }
    bool IsDestroyed() const{
        return hp <= 0;
    }
};
class Ball {
    void ApplyMovement(Context& ctx) {
        x += speed_x * GetDelta(ctx);
        y += speed_y * GetDelta(ctx);
    }
    void CheckDestroy(Context& ctx) {
        if (y > GetDisplayHeight(ctx)) {
            ShouldDestroy = true;
        }
    }
    void CheckBorderCollisions(Context& ctx, float x_, float y_) {
        if (x_ <= 0 || x_ >= GetDisplayWidth(ctx)) speed_x *= -1;
        if (y_ <= 0) speed_y *= -1;
    }
    void CheckPlatformCillision(Context& ctx, float x_, float y_) {
        Rectangle br = { x_,x_ + radius,y_ + radius,y_ };
        Rectangle pr = { platform->x, platform->x + platform->width, platform->y + platform->height, platform->y };
        if (IsIntersect(br, pr)) speed_y *= -1;
    }
    void CheckBrickCollision(Context& ctx,float x_, float y_) {
        for (auto& brick : bricks) {
            if (brick->IsDestroyed()) continue;
            Rectangle ball_rect = { x_,x_ + radius,y_ + radius,y_ };
            Rectangle brick_rect = brick->Rect();
            if (IsIntersect(ball_rect, brick_rect)) {
                brick->Damage();
                speed_y *= -1;
            }
        }
    }
public:
    bool ShouldDestroy = false;
    float x, y, radius, speed_x, speed_y;
    const Platform* platform = nullptr;
    const std::vector<Brick*> &bricks;
    RGBA const color = RGBA{ 171, 82, 54, 255 };
    Ball(float x, float y, float radius, float speed, const Platform* platform, const std::vector<Brick*>& bricks) : x(x), y(y), radius(radius), speed_x(speed), speed_y(speed), platform(platform),bricks(bricks) {}
    void DrawBall(Context& ctx) {
        DrawRectFill(ctx, x, y, radius, radius, color);
    }
    void MoveBall(Context& ctx) {
        auto dx = speed_x * GetDelta(ctx);
        auto dy = speed_y * GetDelta(ctx);
        float x_ = dx + x;
        float y_ = dy + y;
        CheckBorderCollisions(ctx, x_, y_);
        CheckPlatformCillision(ctx, x_, y_);
        CheckBrickCollision(ctx, x_, y_);
        ApplyMovement(ctx);
        CheckDestroy(ctx);
    }
    bool IsShouldDestroy () {
        return ShouldDestroy;
    }
};
class Arcanoid : public ApplicationListener {
    Platform* platform=nullptr;
    Ball* ball = nullptr;
    std::vector<Ball*> balls;
    std::vector<Brick*> bricks;
    bool pause = true;
    RGBA* color = nullptr;
 public:
     void OnCreate(Context& ctx) override {
         platform = new Platform(GetDisplayWidth(ctx)/2-24,GetDisplayHeight(ctx) -10, 48, 6,300);
         balls.push_back(new Ball(platform->x + platform->width / 2 - 2, platform->y - 4, 4, 150, platform, bricks));
         float brick_width = 16, brick_height = 8;
         for (int i = 0; i < 15; i++) {
             for (int j = 1; j < 4; j++) {
                 RGBA color = PALETTE[i * j % PALETTE_LEN];
                 bricks.push_back(new Brick(brick_width * i, brick_height * j, brick_width, brick_height, color));
             }
         }
     }
     void OnRender(Context& ctx) override {
         /*if (balls[0]->IsShouldDestroy()) {
             DrawClearScreen(ctx, PALETTE[2]);
             return;
         }*/
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
     void HandlePause(Context&ctx) {
         if (IsPressed(ctx, Button::KEY_SPACE) && pause) pause = false;
     }
     void Win() {
         color = new RGBA{ 0,255,0,0 };
     }
     void Lose() {
         color = new RGBA{ 255,255,0,0 };
     }
};

int main() {
  SetLogLevel(LogLevel::DEBUG);
  RunApp<Arcanoid>(ApplicationConfig(256, 144, "Arcanoid", true));
  return 0;
}
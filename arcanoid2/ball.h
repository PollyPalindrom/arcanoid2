#pragma once
#include "time.h"
#include "rectangle.h"
#include "drawing.h"
#include "animation.h"
#include "platform.h"
#include "brick.h"
class Ball {
    void ApplyMovement(Context& ctx);
    void CheckDestroy(Context& ctx);
    void CheckBorderCollisions(Context& ctx, float x_, float y_);
    void CheckPlatformCillision(Context& ctx, float x_, float y_);
    void CheckBrickCollision(Context& ctx, float x_, float y_);
public:
    bool ShouldDestroy = false;
    float x, y, radius, speed_x, speed_y;
    const Platform* platform = nullptr;
    const std::vector<Brick*>& bricks;
    RGBA const color = RGBA{ 171, 82, 54, 255 };
    Ball(float x, float y, float radius, float speed, const Platform* platform, const std::vector<Brick*>& bricks) : x(x), y(y), radius(radius), speed_x(speed), speed_y(speed), platform(platform), bricks(bricks) {}
    void DrawBall(Context& ctx);
    void MoveBall(Context& ctx);
    bool IsShouldDestroy();
};


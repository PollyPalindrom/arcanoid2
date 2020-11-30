#pragma once
#include "animation.h"
#include "drawing.h"
#include "rectangle.h"
class Brick {
public:
    float x, y, width, height;
    const RGBA color;
    int hp = 1;
    Brick(float x, float y, float width, float height, const RGBA& color) : x(x), y(y), width(width), height(height), color(color) {}
    void DrawBrick(Context& ctx);
    Rectangle Rect() const;
    void Damage();
    bool IsDestroyed() const;
};


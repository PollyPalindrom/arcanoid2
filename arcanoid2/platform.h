#pragma once
#include"animation.h"
#include "application_listener.h"
#include "buttons.h"
#include "color.h"
#include "drawing.h"
#include "input.h"
#include "lifecycle.h"
#include "palette.h"
#include "text.h"
#include"time.h"
#include "whycpp.h"
#include <cmath>
#include <iostream>
#include <vector>
class Platform
{
public:
    float x, y, width, height, speed_x;
    RGBA const color = RGBA{ 255, 163, 0, 255 };
    Platform(float x, float y, float width, float height, float speed_x) : x(x), y(y), width(width), height(height), speed_x(speed_x) {}
    void DrawPlatform(Context& ctx);
    void MovePlatform(Context& ctx);
};

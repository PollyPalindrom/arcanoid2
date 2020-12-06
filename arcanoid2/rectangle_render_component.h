#pragma once
#include "i_component.h"
#include "color.h"
#include "vec2.h"
class RectangleRenderComponent : public IComponent {
public:
    Vec2 size;
    RGBA color;
    bool filled;

    explicit RectangleRenderComponent(const Vec2& size, const RGBA& color, bool filled = true)
        : size(size), color(color), filled(filled) {}
};
#include "platform.h"
void Platform::DrawPlatform(Context& ctx) {
    DrawRectFill(ctx, x, y, width, height, color);
}
void Platform::MovePlatform(Context& ctx) {
    if (IsPressed(ctx, Button::KEY_LEFT) && x > 0) {
        x -= speed_x * GetDelta(ctx);
    }
    if (IsPressed(ctx, Button::KEY_RIGHT) && x < GetDisplayWidth(ctx) - width) {
        x += speed_x * GetDelta(ctx);
    }
}
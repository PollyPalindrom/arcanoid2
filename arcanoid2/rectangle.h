#pragma once
struct Rectangle {
    float left, right, bottom, top;
    Rectangle(float left, float right, float top, float bottom) : left(left), right(right), top(top), bottom(bottom) {}
};
bool IsInside(float value, float min, float max);
bool IsIntersect(Rectangle& rect1, Rectangle& rect2);


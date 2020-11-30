#include "rectangle.h"
bool IsInside(float value, float min, float max) {
    return value >= min && value <= max;
}
bool IsIntersect(Rectangle& rect1, Rectangle& rect2) {
    bool x = IsInside(rect1.left, rect2.left, rect2.right) || IsInside(rect2.left, rect1.left, rect1.right);
    bool y = IsInside(rect1.top, rect2.bottom, rect2.top) || IsInside(rect2.top, rect1.bottom, rect1.top);
    return x && y;
}
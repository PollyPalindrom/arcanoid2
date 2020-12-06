#include "drawing.h"
#include "rectangle_render_system.h"
#include "rectangle_render_component.h"
#include "transform_component.h"
#include "entity.h"
void RectangleRenderSystem::Update(Context& ctx, Entity* entity) {
    auto rect = entity->Get<RectangleRenderComponent>();
    auto transform = entity->Get<TransformComponent>();

    if (rect->filled) {
        DrawRectFill(ctx, transform->position.x, transform->position.y, rect->size.x, rect->size.y, rect->color);
    }
    else {
        DrawRect(ctx, transform->position.x, transform->position.y, rect->size.x, rect->size.y, rect->color);
    }
}
bool RectangleRenderSystem::Filter(Entity* entity) const {
        return entity->Contains<RectangleRenderComponent>() && entity->Contains<TransformComponent>();
    }
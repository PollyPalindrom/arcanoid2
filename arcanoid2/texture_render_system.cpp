#include "texture_render_system.h"
#include "transform_component.h"
#include "texture_component.h"
#include "drawing.h"

void TextureRenderSystem::Update(Context& ctx, Entity* entity) {
    auto texture = entity->Get<TextureComponent>();
    auto transform = entity->Get<TransformComponent>();

    for (int x = 0; x < texture->width; x++) {
        for (int y = 0; y < texture->height; y++) {
            SetPixel(ctx, transform->position.x + x, transform->position.y + y, texture->Get(x, y));
        }
    }
}
bool TextureRenderSystem::Filter(Entity* entity) const {
        return entity->Contains<TextureComponent>() && entity->Contains<TransformComponent>();
    }
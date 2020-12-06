#include "fail_scene.h"
#include "palette.h"
#include "drawing.h"
#include "text.h"
#include "buttons.h"
#include "input.h"
#include "scene_manager.h"
#include "ecs_scene.h"
void FailScene::OnCreate() {}
void FailScene::OnUpdate() {
    DrawClearScreen(ctx, PALETTE[8]);
    auto x = 1;
    auto y = GetDisplayHeight(ctx) / 2;
    Print(ctx, "GAME OVER\nSPACE TO RESTART", x, y, PALETTE[7], 2);
    if (IsClicked(ctx, Button::KEY_SPACE)) {
        GetSceneManager()->SetScene(0);
    }
}
void FailScene::OnDispose() {}
FailScene::FailScene(Context& ctx) :ECSScene(ctx),ctx(ctx) {}
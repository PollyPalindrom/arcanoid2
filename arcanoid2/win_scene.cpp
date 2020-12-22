#include "win_scene.h"
#include "palette.h"
#include "drawing.h"
#include "text.h"
#include "buttons.h"
#include "input.h"
#include "scene_manager.h"
#include "lifecycle.h"
void WinScene::OnUpdate() {
    DrawClearScreen(ctx, PALETTE[11]);
    auto x = 1;
    auto y = GetDisplayHeight(ctx) / 2;
    Print(ctx, "!!WIN!!\nSPACE TO RESTART\nOR ESC to EXIT", x, y, PALETTE[0], 2);

    if (IsClicked(ctx, Button::KEY_SPACE)) {
        GetSceneManager()->SetScene(0);
    }
    if (IsClicked(ctx, Button::KEY_ESCAPE)) {
        ExitApp(ctx);
    }
}
WinScene::WinScene(Context& ctx) :ECSScene(ctx) , ctx(ctx) {}
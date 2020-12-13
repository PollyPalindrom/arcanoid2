#include "Arcanoid1.h"
#include "game_scene.h"
#include "title_scene.h"
#include "fail_scene.h"
#include "win_scene.h"
#include "engine.h"
#include "level1_creator.h"
#include "level2_creator.h"
#include "next_level_scene.h"
#include "level3_creator.h"
using namespace std;
void Arcanoid1::OnCreate(Context& ctx) {
    scene_manager.Add<TitleScene>("title",ctx);
    scene_manager.Add<GameScene<Level1Creator>>("level1",ctx);
    scene_manager.Add<NextLevelScene>("next_level_2", ctx);
    scene_manager.Add<GameScene<Level2Creator>>("level2",ctx);
    scene_manager.Add<NextLevelScene>("next_level_3", ctx);
    scene_manager.Add<GameScene<Level3Creator>>("level3",ctx);
    scene_manager.Add<WinScene>("game_win",ctx);
    scene_manager.Add<FailScene>("game_over",ctx);
    scene_manager.SetScene(0);
}
void Arcanoid1::OnRender(Context& ctx) {
    scene_manager.OnUpdate();
}
void Arcanoid1::OnDispose(Context& ctx) {
    scene_manager.OnDispose();
}
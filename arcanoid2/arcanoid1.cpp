#include "Arcanoid1.h"
#include "game_scene.h"
#include "title_scene.h"
#include "fail_scene.h"
#include "win_scene.h"
#include "engine.h"
using namespace std;

void Arcanoid1::OnCreate(Context& ctx) {
    scene_manager.Add<TitleScene>(ctx);
    scene_manager.Add<GameScene>(ctx);
    scene_manager.Add<FailScene>(ctx);
    scene_manager.Add<WinScene>(ctx);
    scene_manager.SetScene(0);
}
void Arcanoid1::OnRender(Context& ctx) {
    scene_manager.OnUpdate();
}
void Arcanoid1::OnDispose(Context& ctx) {
    scene_manager.OnDispose();
}
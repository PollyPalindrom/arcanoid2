#pragma once
#include "scene.h""
#include "engine.h"
#include "ecs_scene.h"
#include "vec2.h"
#include "level_creator.h"
#include <memory>
#include "game_scene.h"
#include "palette.h"
#include "drawing.h"
#include "level_creator.h"
#include "level1_creator.h"
template<typename LevelCreator>
class GameScene : public ECSScene {
	Context& ctx;
	std::unique_ptr<LevelCreator> levelcreator;
public:
	GameScene(Context& ctx) : ECSScene(ctx), ctx(ctx) {
		levelcreator = std::make_unique<LevelCreator>(engine.get(), ctx, GetSceneManager());
	}
	~GameScene() override=default;
	void OnCreate() override{
		levelcreator->Init();
	}
	void OnUpdate() override{
		DrawClearScreen(ctx, PALETTE[1]);
		engine->Update(ctx);
	}
	void OnDispose() override{
		levelcreator->Dispose();
	}
};
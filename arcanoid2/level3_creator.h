#pragma once
#include "level_creator.h"
#include "vec2.h"
class Level3Creator : public LevelCreator {
	void InitSystems();
	void InitEntities();
	void CreateBricks();
	void CreateBorders();
public:
	Level3Creator(Engine* engine, Context& ctx, SceneManager* sceneManager) :LevelCreator(engine, ctx, sceneManager) {}
	void Init() override;
	void Dispose() override;
};

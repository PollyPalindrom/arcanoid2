#pragma once
#include "engine.h"
#include "scene_manager.h"
class LevelCreator {
protected:
	Engine* engine;
	Context& ctx;
	SceneManager* sceneManager;
public:
	LevelCreator(Engine *engine, Context &ctx, SceneManager*sceneManager):engine(engine), ctx(ctx), sceneManager(sceneManager){}
	virtual ~LevelCreator()=default;
	virtual void Init() = 0;
	virtual void Dispose() = 0;
};
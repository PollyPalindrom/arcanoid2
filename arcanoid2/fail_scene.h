#pragma once
#include "ecs_scene.h"
class FailScene : public ECSScene {
	Engine engine;
	Context& ctx;
public:
	explicit FailScene(Context& ctx);
	void OnUpdate() override;
	void OnCreate() override {}
	void OnDispose() override {}
};
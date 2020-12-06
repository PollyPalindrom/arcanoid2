#pragma once
#include "ecs_scene.h"
class FailScene : public ECSScene {
	Engine engine;
	Context& ctx;
public:
	explicit FailScene(Context& ctx);
	void OnCreate() override;
	void OnUpdate() override;
	void OnDispose() override;
};
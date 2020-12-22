#pragma once
#include "ecs_scene.h"
class TitleScene : public ECSScene {
	Engine engine;
	Context& ctx;
public:
	explicit TitleScene(Context& ctx);
	void OnUpdate() override;
	void OnCreate() override {}
	void OnDispose() override {}
};
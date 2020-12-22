#pragma once
#include "ecs_scene.h"

class WinScene : public ECSScene {
	Engine engine;
	Context& ctx;
public:
	explicit WinScene(Context& ctx);
	void OnUpdate() override;
	void OnCreate() override {}
	void OnDispose() override {}
};
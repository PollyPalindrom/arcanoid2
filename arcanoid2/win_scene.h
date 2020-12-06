#pragma once
#include "ecs_scene.h"

class WinScene : public ECSScene {
	Engine engine;
	Context& ctx;
public:
	explicit WinScene(Context& ctx);
	void OnCreate() override;
	void OnUpdate() override;
	void OnDispose() override;
};
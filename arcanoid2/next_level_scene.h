#pragma once
#pragma once
#include "ecs_scene.h"
class NextLevelScene : public ECSScene {
	Engine engine;
	Context& ctx;
public:
	explicit NextLevelScene(Context& ctx);
	void OnCreate() override;
	void OnUpdate() override;
	void OnDispose() override;
};
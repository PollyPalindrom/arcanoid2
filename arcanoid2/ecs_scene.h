#pragma once
#include "engine.h"
#include "scene.h"
#include <memory>

class ECSScene : public IScene {
public:
	explicit ECSScene(Context& ctx);

protected:
	std::unique_ptr<Engine> engine;
	Context& ctx;
};
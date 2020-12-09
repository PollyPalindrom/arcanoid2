#pragma once
#include "i_system.h"
#include <vector>
#include "scene_manager.h"
class BallControlSystem : public ISystem {
	std::vector<size_t> to_delete;
	SceneManager* sceneManager;
public:
	explicit BallControlSystem(SceneManager* sceneManager);
protected:
	void OnUpdate(Context& ctx) override;
	void Update(Context& ctx, Entity* entity) override;
	bool Filter(Entity* entity) const override;
};
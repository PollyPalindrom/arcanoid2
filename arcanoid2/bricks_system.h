#pragma once
#include "i_system.h"
#include <vector>
#include "scene_manager.h"
class BricksSystem : public ISystem {
	std::vector<size_t> to_delete{};
	SceneManager* sceneManager;
public:
	explicit BricksSystem(SceneManager* sceneManager);
protected:
	bool Filter(Entity* entity) const override;
	void Update(Context& ctx, Entity* entity) override;
	void OnPostUpdate(Context& ctx) override;
};
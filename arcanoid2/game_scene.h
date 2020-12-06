#pragma once
#include "scene.h""
#include "engine.h"
#include "ecs_scene.h"
#include "vec2.h"
class GameScene : public ECSScene {
	Context& ctx;
	void CreateBrick(const Vec2& pos, const Vec2& size);
	void CreateBorder(const Vec2& size, const Vec2& pos);
	void CreatePlatform(const Vec2& platform_pos, const Vec2& platform_size);
	void CreateBall(const Vec2& platform_pos, const Vec2& platform_size);
	void CreateBricks();
	void CreateBorders();
	void InitSystems();
	void InitEntities();
public:
	explicit GameScene(Context& ctx);
	void OnCreate() override;
	void OnUpdate() override;
	void OnDispose() override;
};
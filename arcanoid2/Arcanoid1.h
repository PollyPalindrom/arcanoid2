#pragma once
#include "application_listener.h"
#include "engine.h"
#include "scene_manager.h"
#include <memory>
// класс, который реализует библиотечный интерфейс
class Arcanoid1: public ApplicationListener
{
	SceneManager scene_manager;
public:
	void OnCreate(Context& ctx) override;
	void OnRender(Context& ctx) override;
	void OnDispose(Context& ctx) override;
};


#pragma once
#include "entity_manager.h"
#include "vec2.h"
#include <vector>
#include <memory>
#include "i_bonus_creator.h"
#include "resize_bonus_builder.h"
#include "multi_ball_bonus_builder.h"
#include "nextnum.h"
class BonusSpawner {
public: 
	Random r;
	std::vector<std::unique_ptr<IBonusCreator>> builder;
public:
	BonusSpawner();
	void Spawn(EntityManager*entityManager,const Vec2&pos);
};
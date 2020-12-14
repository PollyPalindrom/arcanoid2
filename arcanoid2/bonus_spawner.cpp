#include "bonus_spawner.h"
#include <ctime>
#include <iostream>
#include <random>
#include "nextnum.h"
#include "mn_resie_bonus_builder.h"
#include "pl_resize_bonus_builder.h"
BonusSpawner::BonusSpawner(){
	builder.push_back(std::make_unique<MnResizeBonusBuiilder>());
	builder.push_back(std::make_unique<PlResizeBonusBuiilder>());
	builder.push_back(std::make_unique<MultiBallBonusBuiilder>());
}
void BonusSpawner::Spawn(EntityManager* entityManager,const Vec2& pos)
{
	auto t =r.Nextnum(-5, builder.size());
	std::cout << t << endl;
	if (t < 0) return;
	builder.at(t)->Build(entityManager, pos);
}

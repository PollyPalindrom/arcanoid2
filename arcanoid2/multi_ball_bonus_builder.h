#pragma once
#include"i_bonus_creator.h"
class MultiBallBonusBuiilder :public IBonusCreator {
	void Build(EntityManager* entityManager, Vec2 pos)override;
public:
	MultiBallBonusBuiilder() {};
};
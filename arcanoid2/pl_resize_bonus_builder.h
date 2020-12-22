#pragma once
#include"i_bonus_creator.h"
#include"nextnum.h"
class PlResizeBonusBuiilder :public IBonusCreator {
public:
	void Build(EntityManager* entityManager, Vec2 pos)override;
};
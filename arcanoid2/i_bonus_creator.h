#pragma once
#include "entity_manager.h"
#include "vec2.h"
class IBonusCreator {
public:
	virtual ~IBonusCreator() = default;
	virtual void Build(EntityManager* entityManager, Vec2 pos)=0;
};
#include "entity_manager.h"
#include "vec2.h"
#include "color.h"
#pragma once
RGBA ColorHP(int hp);
void CreateBrick(EntityManager*entityManager,const Vec2& pos, const Vec2& size, int hp=1);

#include "level4_creator.h"

void Level4Creator::Init()
{
	InitEntities();
	InitSystems();
}

void Level4Creator::Dispose()
{
	engine->GetEntityManager()->RemoveEntities();
	engine->GetSystemManager()->RemoveSystems();
}
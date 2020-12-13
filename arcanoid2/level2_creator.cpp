#include "level2_creator.h"

void Level2Creator::Init()
{
	InitEntities();
	InitSystems();
}

void Level2Creator::Dispose()
{
	engine->GetEntityManager()->RemoveEntities();
	engine->GetSystemManager()->RemoveSystems();
}
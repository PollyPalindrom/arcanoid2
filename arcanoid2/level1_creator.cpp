#include "level1_creator.h"

void Level1Creator::Init()
{
	InitEntities();
	InitSystems();
}

void Level1Creator::Dispose()
{
	engine->GetEntityManager()->RemoveEntities();
	engine->GetSystemManager()->RemoveSystems();
}
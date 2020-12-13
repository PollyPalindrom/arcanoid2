#include "level3_creator.h"

void Level3Creator::Init()
{
	InitEntities();
	InitSystems();
}

void Level3Creator::Dispose()
{
	engine->GetEntityManager()->RemoveEntities();
	engine->GetSystemManager()->RemoveSystems();
}
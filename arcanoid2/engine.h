#pragma once
#include "entity_manager.h"
#include "system_manager.h"
#include <vector>
#include <memory>
class Context;
class Engine {
private:
    std::unique_ptr<EntityManager> entityManager;
    std::unique_ptr<SystemManager> systemManager;

public:
    explicit Engine();
    void Update(Context& ctx);
    EntityManager* GetEntityManager();
    SystemManager* GetSystemManager();
};

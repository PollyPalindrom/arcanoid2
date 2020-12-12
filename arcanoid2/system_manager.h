#pragma once
#include "i_system.h"
#include <memory>
#include <vector>

class SystemManager {
    std::vector<std::unique_ptr<ISystem>> systems;
    EntityManager* entityManager;

public:
    explicit SystemManager(EntityManager* entityManager) : entityManager(entityManager) {}

    template<typename System, typename... Args>
    SystemManager* AddSystem(Args &&... args) {// принмает на вход аргументы(переменное число). Ёто оаргументы конструктора системы, которую мы хотим создать 
        auto system = new System(std::forward<Args>(args)...);//создание экземпл€ра класса
        system->entityManager = entityManager;// складывваетс€ в список
        systems.push_back(std::unique_ptr<System>(system));// оборачиваетс€ в уникальный указатель
        return this;
    }

    void Update(Context& ctx);
    void RemoveSystems();
    virtual ~SystemManager();
};
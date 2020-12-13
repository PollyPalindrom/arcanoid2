#pragma once
#include <map>
#include <memory>
#include "i_component.h"
#include <set>
#include <string>
#include <typeindex>
//������-������ � ����
class Entity {
    friend class EntityManager;
    std::map<std::type_index, std::shared_ptr<IComponent>> components;
    char tag='a';
    size_t id;
public:
    void SetTag(const char& tag_) {
        tag = tag_;
    }
    char GetTag() const {
        return tag;
    } 
    template<typename Component>
    std::shared_ptr<Component> Get() const {
        auto c = components.at(typeid(Component));
        return std::dynamic_pointer_cast<Component>(c);
    }
    template<typename Component, typename... Args>
    void Add(Args &&... args) {
        components[typeid(Component)] = std::make_shared<Component>(std::forward<Args>(args)...);
    }
    template<typename Component>
    void Add(std::shared_ptr<Component> component) {
        components[typeid(Component)] = component;
    }
    template<typename Component>
    bool Contains() const {
        return components.count(typeid(Component)) != 0;
    }
    size_t GetId() const {
        return id;
    }
    bool operator<(const Entity& rhs) const {
        return id < rhs.id;
    }
    bool operator>(const Entity& rhs) const {
        return rhs < *this;
    }
    bool operator<=(const Entity& rhs) const {
        return !(rhs < *this);
    }
    bool operator>=(const Entity& rhs) const {
        return !(*this < rhs);
    }
    virtual ~Entity() {
        components.clear();
    }
};

#include "scene_manager.h"
#include "scene.h"
#include <iostream>
#include "error.h"
//обёртка для работы со сценами. необходима для перемещения между сценами
void SceneManager::OnUpdate() {
    try {
        if (scenes.size() > current_scene) {
            if (first_start) {
                first_start = false;
                scenes.at(current_scene)->OnCreate();
                prev_scene = current_scene;
            }
            else if (prev_scene != current_scene) {
                scenes.at(prev_scene)->OnDispose();
                prev_scene = current_scene;
                scenes.at(current_scene)->OnCreate();
            }
            scenes.at(current_scene)->OnUpdate();
        }
        else {
            throw 1;
        }
    }
    catch (int i)
    {
        Exception ex(i);
        ex.Print();
        return;
    }
}
void SceneManager::OnDispose() {
    for (auto& scene : scenes) {
        scene->OnDispose();
    }
    scenes.clear();
}
void SceneManager::SetScene(size_t id) {
    if (id < scenes.size()) {
        prev_scene = current_scene;
        current_scene = id;
    }
}
void SceneManager::NextScene() {
    current_scene++;
    if (current_scene >= scenes.size()) {
        current_scene = 0;
    }
}

void SceneManager::SetScene(const std::string &name)
{
    try {
        if (named_scenes.count(name) == 0) {
            SetScene(0);
            throw 2;
            return;
        }
    }
    catch(int i){
        Exception ex(i);
        ex.Print();
        return;
    }
    auto id = named_scenes.at(name);
    SetScene(id);
}

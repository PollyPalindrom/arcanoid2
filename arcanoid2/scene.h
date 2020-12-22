#pragma once
#include <memory>
//�������� ���� �����, ����� ����� ������, ��������� �. ��� ��������� ����� ��������
class SceneManager;

class IScene {
    friend class SceneManager;
    SceneManager* sceneManager;
public:
    SceneManager* GetSceneManager() const;
    virtual void OnUpdate() {}
    virtual void OnCreate() {}
    virtual void OnDispose() {}
    virtual ~IScene() = default;
};
#ifndef MANAGER_SCENE_HPP
#define MANAGER_SCENE_HPP

#include "manager_base.hpp"
#include "scene.hpp"

class SceneManager : public BaseManager
{
public:
    SceneManager();

    std::shared_ptr<Scene> GetScene();
    void SetCurrentCamera(std::string name);
    std::shared_ptr<Camera> GetCurrentCamera();

private:
    std::shared_ptr<Scene> scene;
    std::shared_ptr<Camera> current_camera_;
};

#endif
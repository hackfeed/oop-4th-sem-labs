#include "manager_scene.hpp"

#include "exception_scene.hpp"

SceneManager::SceneManager()
    : scene(new Scene()) {}

std::shared_ptr<Scene> SceneManager::GetScene()
{
    return scene;
}

void SceneManager::SetCurrentCamera(std::string name)
{
    current_camera_ = std::dynamic_pointer_cast<Camera>(scene->getObject(name));
}

std::shared_ptr<Camera> SceneManager::GetCurrentCamera()
{
    time_t t_time = time(NULL);
    if (!current_camera_)
    {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return current_camera_;
}

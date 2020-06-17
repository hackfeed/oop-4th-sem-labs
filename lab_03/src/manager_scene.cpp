#include "manager_scene.hpp"

#include "exception_scene.hpp"

SceneManager::SceneManager()
    : scene(new Scene()) {}

std::shared_ptr<Scene> SceneManager::getScene()
{
    return scene;
}

void SceneManager::setCurrentCamera(std::string name)
{
    current_camera = std::dynamic_pointer_cast<Camera>(scene->getObject(name));
}

std::shared_ptr<Camera> SceneManager::getCurrentCamera()
{
    time_t t_time = time(NULL);
    if (!current_camera)
    {
        throw CameraError(__FILE__, typeid(*this).name(), __LINE__, ctime(&t_time));
    }
    return current_camera;
}

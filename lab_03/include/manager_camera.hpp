#ifndef MANAGER_CAMERA_HPP
#define MANAGER_CAMERA_HPP

#include "manager_base.hpp"
#include "scene.hpp"

class CameraManager : public BaseManager
{
public:
    void Bend(std::shared_ptr<Camera> camera, double angle);
    void Roll(std::shared_ptr<Camera> camera, double angle);
    void Pitch(std::shared_ptr<Camera> camera, double angle);
};

#endif
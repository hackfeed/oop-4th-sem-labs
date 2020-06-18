#include "manager_camera.hpp"

#include "math.h"
void CameraManager::Bend(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->getZAngle();
    camera->setZAngle(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::Roll(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->getXAngle();
    camera->setXAngle(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::Pitch(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->getYAngle();
    camera->setYAngle(angle / 180.0 * M_PI + cur_angle);
}

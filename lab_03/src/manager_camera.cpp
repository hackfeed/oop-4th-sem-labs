#include "manager_camera.hpp"

#include "math.h"
void CameraManager::yaw(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->getZAngle();
    camera->setZAngle(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::roll(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->getXAngle();
    camera->setXAngle(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::pitch(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->getYAngle();
    camera->setYAngle(angle / 180.0 * M_PI + cur_angle);
}

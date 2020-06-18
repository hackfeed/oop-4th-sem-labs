#include "manager_camera.hpp"

#include "math.h"
void CameraManager::Bend(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->GetZAng();
    camera->SetZAng(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::Roll(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->GetXAng();
    camera->SetXAng(angle / 180.0 * M_PI + cur_angle);
}

void CameraManager::Pitch(std::shared_ptr<Camera> camera, double angle)
{
    double cur_angle = camera->GetYAng();
    camera->SetYAng(angle / 180.0 * M_PI + cur_angle);
}

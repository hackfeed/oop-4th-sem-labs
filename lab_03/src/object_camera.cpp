#include "object_camera.hpp"

Camera::Camera(std::string name)
{
    position = Point<double>(0, 0, 300);
    this->name_ = name;
    this->x_angle = 0;
    this->y_angle = 0;
    this->z_angle = 0;
}

const Point<double> &Camera::GetPosition() const
{
    return position;
}

void Camera::SetPosition(const Point<double> &position)
{
    this->position = position;
}

double Camera::GetXAng() const
{
    return x_angle;
}

void Camera::SetXAng(double x_angle)
{
    this->x_angle = x_angle;
}

double Camera::GetYAng() const
{
    return y_angle;
}

void Camera::SetYAng(double y_angle)
{
    this->y_angle = y_angle;
}

void Camera::SetZAng(double z_angle)
{
    this->z_angle = z_angle;
}

double Camera::GetZAng() const
{
    return z_angle;
}

void Camera::Transform(const std::shared_ptr<Matrix<double>> mtr)
{
    position.Transform(mtr);
}

void Camera::Accept(std::shared_ptr<Visitor> visitor)
{
    visitor->Visit(*this);
}

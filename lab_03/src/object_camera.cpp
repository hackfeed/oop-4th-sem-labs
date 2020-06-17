#include "object_camera.hpp"

Camera::Camera(std::string name)
{
    this->_name = name;
    position = Point<double>(0, 0, 300);
    this->x_angle = 0;
    this->y_angle = 0;
    this->z_angle = 0;
}

const Point<double> &Camera::getPosition() const
{
    return position;
}

void Camera::setPosition(const Point<double> &position)
{
    this->position = position;
}

double Camera::getXAngle() const
{
    return x_angle;
}

void Camera::setXAngle(double x_angle)
{
    this->x_angle = x_angle;
}

double Camera::getYAngle() const
{
    return y_angle;
}

void Camera::setYAngle(double y_angle)
{
    this->y_angle = y_angle;
}

void Camera::setZAngle(double z_angle)
{
    this->z_angle = z_angle;
}

double Camera::getZAngle() const
{
    return z_angle;
}

void Camera::transform(const std::shared_ptr<matrix<double>> mtr)
{
    position.transform(mtr);
}

void Camera::accept(std::shared_ptr<Visitor> visitor)
{
    visitor->visit(*this);
}

#include "point.h"

#define PI 3.1415
#include <QDebug>

point::point()
{
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

point::point(const double x, const double y, const double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

point::point(const point &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

point& point::operator=(const point& point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;

    return *this;
}

point::point(const point &&point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    point.~point();
}

point& point::operator=(point &&point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
    point.~point();

    return *this;
}

double point::get_x() const
{
    return this->x;
}

double point::get_y() const
{
    return this->y;
}

double point::get_z() const
{
    return this->z;
}

void point::set_x(double const &x)
{
    this->x = x;
}

void point::set_y(double const &y)
{
    this->y = y;
}

void point::set_z(double const &z)
{
    this->z = z;
}

void point::move(const double dx, const double dy, const double dz)
{
    this->x += dx;
    this->y += dy;
    this->z += dz;
}

void point::scale(const double kx, const double ky, const double kz)
{
    this->x *= kx;
    this->y *= ky;
    this->z *= kz;
}

void point::turn(const double ox, const double oy, const double oz)
{
    this->turn_x(ox);
    this->turn_y(oy);
    this->turn_z(oz);
}

void point::turn_x(const double &ox)
{
    const double temp_y = this->y;
    this->y = y + cos(ox * PI / 180) + z * sin(ox * PI / 180);
    this->z = -temp_y * sin(ox * PI / 180) + z * cos(ox * PI / 180);
}

void point::turn_y(const double &oy)
{
    const double temp_x = this->x;
    this->x = x * cos(oy * PI / 180) + z * sin(oy * PI / 180);
    this->z = -temp_x * sin(oy * PI / 180) + z * cos(oy * PI / 180);
}

void point::turn_z(const double &oz)
{
    const double temp_x = this->x;
    this->x = x * cos(oz * PI / 180) + y * sin(oz * PI / 180);
    this->y = -temp_x * sin(oz * PI / 180) + y * cos(oz * PI / 180);
}

#ifndef POINT_H
#define POINT_H

#include <math.h>

class point
{
public:
    point();
    point(const double x, const double y, const double z);

    point(const point &point);
    point& operator=(const point &point);

    point(const point &&point);
    point& operator=(point &&point);

    ~point() = default;

    double get_x() const;
    double get_y() const;
    double get_z() const;

    void set_x(double const &x);
    void set_y(double const &y);
    void set_z(double const &z);

    void move (const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void turn (const double ox, const double oy, const double oz);

    void turn_x(const double &ox);
    void turn_y(const double &oy);
    void turn_z(const double &oz);

private:
    double x;
    double y;
    double z;
};

#endif

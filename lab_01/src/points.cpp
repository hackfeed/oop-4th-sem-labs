#include "points.h"

point_t init_point(const double x, const double y, const double z)
{
    point_t point;
    point.x = x;
    point.y = y;
    point.z = z;

    return point;
}

ppoint_t init_proj_point(const double x, const double y)
{
    ppoint_t point;
    point.x = x;
    point.y = y;

    return point;
}

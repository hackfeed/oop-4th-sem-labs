#ifndef _POINTS_H_
#define _POINTS_H_

struct projection_point
{
    double x, y;
};
using ppoint_t = struct projection_point;

struct point
{
    double x, y, z;
};
using point_t = struct point;

point_t init_point(const double x = 0, const double y = 0, const double z = 0);
ppoint_t init_proj_point(const double x = 0, const double y = 0);

#endif

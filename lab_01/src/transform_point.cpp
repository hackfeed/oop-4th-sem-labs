#include "transform_point.h"
#include <cstdio>

void move_point(point_t &point, const transform_t &dp)
{
    point.x += dp.x;
    point.y += dp.y;
    point.z += dp.z;
}

err_t scale_point(point_t &point, const double sf, const point_t &cp)
{
    if (fabs(sf) < DBL_EPSILON)
    {
        return DATA_ERROR;
    }

    point.x = ((point.x - cp.x) * sf) + cp.x;
    point.y = ((point.y - cp.y) * sf) + cp.y;
    point.z = ((point.z - cp.z) * sf) + cp.z;

    return OK;
}

static void x_rotate(point_t &tmp, point_t &point, const transform_t &ap, const point_t &cp)
{
    tmp.x = point.x;
    tmp.y = ((point.y - cp.y) * cos(ap.x) - (point.z - cp.z) * sin(ap.x)) + cp.y;
    tmp.z = ((point.y - cp.y) * sin(ap.x) + (point.z - cp.z) * cos(ap.x)) + cp.z;
}

static void y_rotate(point_t &tmp, point_t &point, const transform_t &ap, const point_t &cp)
{
    tmp.y = point.y;
    tmp.x = ((point.x - cp.x) * cos(ap.y) + (point.z - cp.z) * sin(ap.y)) + cp.x;
    tmp.z = (-(point.x - cp.x) * sin(ap.y) + (point.z - cp.z) * cos(ap.y)) + cp.z;
}

static void z_rotate(point_t &tmp, point_t &point, const transform_t &ap, const point_t &cp)
{
    tmp.z = point.z;
    tmp.x = ((point.x - cp.x) * cos(ap.z) - (point.y - cp.y) * sin(ap.z)) + cp.x;
    tmp.y = ((point.x - cp.x) * sin(ap.z) + (point.y - cp.y) * cos(ap.z)) + cp.y;
}

static void assign_point(point_t &point, point_t &point_to_assign)
{
    point = point_to_assign;
}

void rotate_point(point_t &point, const transform_t &ap, const point_t &cp)
{
    point_t tmp = init_point();

    if (fabs(ap.x) > DBL_EPSILON)
    {
        x_rotate(tmp, point, ap, cp);
    }
    if (fabs(ap.y) > DBL_EPSILON)
    {
        y_rotate(tmp, point, ap, cp);
    }
    if (fabs(ap.z) > DBL_EPSILON)
    {
        z_rotate(tmp, point, ap, cp);
    }

    assign_point(point, tmp);
}

transform_t init_transform(const double x, const double y, const double z)
{
    transform_t transformation;
    transformation.x = x;
    transformation.y = y;
    transformation.z = z;

    return transformation;
}

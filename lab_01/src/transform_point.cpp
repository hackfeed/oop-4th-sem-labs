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
    err_t rc = OK;
    if (fabs(sf) < DBL_EPSILON)
    {
        rc = DATA_ERROR;
    }

    if (!rc)
    {
        point.x = ((point.x - cp.x) * sf) + cp.x;
        point.y = ((point.y - cp.y) * sf) + cp.y;
        point.z = ((point.z - cp.z) * sf) + cp.z;
    }

    return rc;
}

void rotate_point(point_t &point, const transform_t &ap, const point_t &cp)
{
    point_t tmp = init_point();

    if (fabs(ap.x) > DBL_EPSILON)
    {
        tmp.x = point.x;
        tmp.y = ((point.y - cp.y) * cos(ap.x) - (point.z - cp.z) * sin(ap.x)) + cp.y;
        tmp.z = ((point.y - cp.y) * sin(ap.x) + (point.z - cp.z) * cos(ap.x)) + cp.z;
    }
    if (fabs(ap.y) > DBL_EPSILON)
    {
        tmp.y = point.y;
        tmp.x = ((point.x - cp.x) * cos(ap.y) + (point.z - cp.z) * sin(ap.y)) + cp.x;
        tmp.z = (-(point.x - cp.x) * sin(ap.y) + (point.z - cp.z) * cos(ap.y)) + cp.z;
    }
    if (fabs(ap.z) > DBL_EPSILON)
    {
        tmp.z = point.z;
        tmp.x = ((point.x - cp.x) * cos(ap.z) - (point.y - cp.y) * sin(ap.z)) + cp.x;
        tmp.y = ((point.x - cp.x) * sin(ap.z) + (point.y - cp.y) * cos(ap.z)) + cp.y;
    }

    point = tmp;
}

transform_t init_transform(const double x, const double y, const double z)
{
    transform_t transformation;
    transformation.x = x;
    transformation.y = y;
    transformation.z = z;

    return transformation;
}

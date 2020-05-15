#ifndef _TRANSFORM_POINT_H_
#define _TRANSFORM_POINT_H_

#include "points.h"
#include "constants.h"

#include <cfloat>
#include <cmath>

struct transformation_data // to transform figure (here is rotate or distance and etc.)
{
    double x, y, z;
};
using transform_t = struct transformation_data;

void move_point(point_t &point, const transform_t &dp);
err_t scale_point(point_t &point, const double sf, const point_t &center);
void rotate_point(point_t &point, const transform_t &ap, const point_t &center);
transform_t init_transform(const double x = 0, const double y = 0, const double z = 0);

#endif

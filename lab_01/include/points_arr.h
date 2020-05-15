#ifndef _POINTS_ARR_H_
#define _POINTS_ARR_H_

#include "points.h"
#include <stdlib.h>
#include <gtkmm-3.0/gtkmm.h>

struct points_array
{
    point_t *arr;
    unsigned int size;
    point_t cp;
};
using parr_t = struct points_array;

struct projection_points_array
{
    ppoint_t *arr;
    unsigned int size;
};
using pparr_t = struct projection_points_array;

parr_t init_points_arr(point_t *const arr = NULL, const unsigned int size = 0);
pparr_t init_proj_points_arr(ppoint_t *const arr = NULL, const unsigned int size = 0);

#endif

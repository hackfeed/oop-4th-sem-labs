#include "points_arr.h"

parr_t init_points_arr(point_t *const arr, const unsigned int size)
{
    parr_t parr;
    parr.arr = arr;
    parr.size = size;

    return parr;
}

pparr_t init_proj_points_arr(ppoint_t *arr, unsigned int size)
{
    pparr_t pparr;
    pparr.arr = arr;
    pparr.size = size;

    return pparr;
}

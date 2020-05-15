#ifndef _IO_POINTS_H_
#define _IO_POINTS_H_

#include "constants.h"
#include "points_arr.h"

#include <cstdlib>
#include <cstdio>

err_t find_center(parr_t &points);
err_t get_points(parr_t &points, FILE *const f);
void destroy_points(parr_t &points);
void destroy_ppoints(pparr_t &points);

#endif

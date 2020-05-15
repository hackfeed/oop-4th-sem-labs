#ifndef _FIGURE_HANDLERS_H_
#define _FIGURE_HANDLERS_H_

#include "constants.h"
#include "figure.h"
#include "transform_point.h"

#include <cstdio>
#include <cfloat>


using transform_t = struct transformation_data;

err_t move_figure(parr_t &points, const transform_t &dp);
err_t scale_figure(parr_t &points, const transform_t &sp); // sf - scale factor.
err_t rotate_figure(parr_t &points, const transform_t &ap);


#endif

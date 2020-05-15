#ifndef _PROJECTION_FN_H_
#define _PROJECTION_FN_H_

#include "constants.h"
#include "figure.h"

err_t match_figure_project(fpr_t &figure_projection, const figure_t &main_figure);
err_t read_projection(pparr_t &prj_points, const parr_t &main_points);

#endif

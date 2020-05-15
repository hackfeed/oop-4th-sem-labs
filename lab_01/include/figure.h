#ifndef _FIGURE_H_
#define _FIGURE_H_

#include "links_arr.h"
#include "points_arr.h"

struct figure_projection
{
    pparr_t points;
    larr_t links;
};
using fpr_t = struct figure_projection;

struct figure
{
    parr_t points;
    larr_t links;
};
using figure_t = struct figure;

figure_t init_figure(point_t *const parr = NULL, const unsigned int psize = 0,
                     link_t *const larr = NULL, const unsigned int lsize = 0);
fpr_t init_projection(ppoint_t *const parr = NULL, const unsigned int psize = 0,
                      link_t *const larr = NULL, const unsigned int lsize = 0);

#endif

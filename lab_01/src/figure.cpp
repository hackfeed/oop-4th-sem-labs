#include "figure.h"

figure_t init_figure(point_t *const parr, const unsigned int psize, link_t *const larr,
                     const unsigned int lsize)
{
    parr_t points;
    points.arr = parr;
    points.size = psize;

    larr_t links;
    links.arr = larr;
    links.size = lsize;

    figure_t figure;
    figure.points = points;
    figure.links = links;

    return figure;
}

fpr_t init_projection(ppoint_t *const parr, const unsigned int psize,
                      link_t *const larr, const unsigned int lsize)
{
    pparr_t points;
    points.arr = parr;
    points.size = psize;

    larr_t links;
    links.arr = larr;
    links.size = lsize;

    fpr_t figure;
    figure.points = points;
    figure.links = links;

    return figure;
}

#include "draw_fn.h"
#include "draw_md.h"

err_t draw_figure(draw_data_t &data, const fpr_t &projection)
{
    pparr_t points = projection.points;
    larr_t links = projection.links;

    if (points.size <= 0 || links.size <= 0 || !links.arr || !points.arr)
    {
        return DATA_ERROR;
    }

    ppoint_t *points_array = points.arr;
    drawer_t drawer = {.drw = *data.canvas};
    for (unsigned int i = 0; i < links.size; i++)
    {
        link_t cur_link = links.arr[i];
        draw_line(drawer, points_array[cur_link.l1], points_array[cur_link.l2]);
    }

    return OK;
}

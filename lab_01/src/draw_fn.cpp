#include "draw_fn.h"

err_t draw_figure(draw_data_t &data, const fpr_t &projection)
{
    pparr_t points = projection.points;
    larr_t links = projection.links;
    err_t rc = OK;

    if (points.size <= 0 || links.size <= 0 || !links.arr || !points.arr)
    {
        rc = DATA_ERROR;
    }

    if (!rc)
    {
        ppoint_t *points_array = points.arr;
        for (unsigned int i = 0; i < links.size; i++)
        {
            link_t cur_link = links.arr[i];
            create_line(*data.canvas, points_array[cur_link.l1], points_array[cur_link.l2]);
        }
    }

    return OK;
}

#include "projection_fn.h"

static err_t point_to_proj(ppoint_t &projection, const point_t &point)
{
    err_t rc = OK;
    projection.x = point.x;
    projection.y = point.y;
    return rc;
}

static err_t match_points(pparr_t &prj_points, const parr_t &fgr_points)
{
    if (prj_points.size != fgr_points.size)
    {
        ppoint_t *tmp = (ppoint_t *)realloc(prj_points.arr,
                                            sizeof(point_t) * fgr_points.size);
        if (!tmp)
        {
            return ALLOCATION_ERROR;
        }

        prj_points.arr = tmp;
        prj_points.size = fgr_points.size;
    }
    return OK;
}

err_t match_figure_project(fpr_t &figure_projection, const figure_t &main_figure)
{
    err_t rc = match_points(figure_projection.points, main_figure.points);
    if (!rc)
    {
        figure_projection.links = main_figure.links;
    }
    return rc;
}

err_t read_projection(pparr_t &prj_points, const parr_t &main_points)
{
    err_t rc = OK;

    for (unsigned int i = 0; i < main_points.size; i++)
    {
        if ((rc = point_to_proj(prj_points.arr[i], main_points.arr[i])))
        {
            return rc;
        }
    }
    return rc;
}

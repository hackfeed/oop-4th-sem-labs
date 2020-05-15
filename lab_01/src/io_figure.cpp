#include "io_figure.h"

static err_t read_from_file(figure_t &tmp_figure, FILE *const f);

void destroy_figure(figure_t &main_figure)
{
    destroy_points(main_figure.points);
    destroy_links(main_figure.links);
}

void destroy_projection(fpr_t &projection)
{
    destroy_ppoints(projection.points);
}

err_t read_from_file(figure_t &main_figure, const char *const filename)
{
    FILE *f = fopen(filename, "r");

    err_t rc = OK;
    if (!f)
    {
        rc = FILE_ERROR;
    }

    figure_t tmp_figure = init_figure();
    if (!rc)
    {
        rc = read_from_file(tmp_figure, f);
    }

    fclose(f);

    if (!rc)
    {
        destroy_figure(main_figure);
        main_figure = tmp_figure;
    }

    return rc;
}

static err_t read_from_file(figure_t &main_figure, FILE *const f)
{
    parr_t points = init_points_arr();
    larr_t links = init_links_arr();

    err_t rc = OK;

    if (!f)
    {
        rc = FILE_ERROR;
    }

    if (!rc)
    {
        if ((rc = get_points(points, f)))
        {
            ;
        }

        else if ((rc = get_links(links, f, points.size - 1)))
        {
            destroy_points(points);
        }

        else if ((rc = find_center(points)))
        {
            destroy_points(points);
            destroy_links(links);
        }

        else
        {
            main_figure.points = points;
            main_figure.links = links;
        }
    }

    return rc;
}

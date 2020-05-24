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

static void assign_figure(figure_t &main_figure, figure_t &tmp_figure)
{
    main_figure = tmp_figure;
}

err_t read_from_file(figure_t &main_figure, const char *const filename)
{
    if (!filename)
    {
        return FILE_ERROR;
    }

    FILE *f = fopen(filename, "r");

    if (!f)
    {
        return FILE_ERROR;
    }

    figure_t tmp_figure = init_figure();
    err_t rc = read_from_file(tmp_figure, f);

    fclose(f);

    if (!rc)
    {
        destroy_figure(main_figure);
        assign_figure(main_figure, tmp_figure);
    }

    return rc;
}

static void assign_points(figure_t &main_figure, parr_t points)
{
    main_figure.points = points;
}

static void assign_links(figure_t &main_figure, larr_t links)
{
    main_figure.links = links;
}

static err_t read_from_file(figure_t &main_figure, FILE *const f)
{
    if (!f)
    {
        return FILE_ERROR;
    }

    err_t rc = OK;
    larr_t links = init_links_arr();
    parr_t points = init_points_arr();

    if ((rc = get_points(points, f)))
    {
        ;
    }

    else if ((rc = get_links(links, f, points.size - 1))) // разделить get_links и verify_links
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
        assign_points(main_figure, points);
        assign_links(main_figure, links);
    }

    return rc;
}

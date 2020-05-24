#include "cmds.h"

err_t move_command(figure_t &main_figure, const trans_data_t &data)
{
    err_t rc = move_figure(main_figure.points, data.trans_coeffs);
    return rc;
}

err_t rotate_command(figure_t &main_figure, const trans_data_t &data)
{
    err_t rc = rotate_figure(main_figure.points, data.trans_coeffs);
    return rc;
}

err_t scale_command(figure_t &main_figure, const trans_data_t &data)
{
    err_t rc = scale_figure(main_figure.points, data.trans_coeffs);
    return rc;
}

err_t get_projection(prj_data_t &data, const figure_t &main_figure)
{
    if (!data.projection)
    {
        return DATA_ERROR;
    }

    fpr_t &figure_projection = *data.projection;
    fpr_t tmp_projection = init_projection();

    err_t rc = match_figure_project(tmp_projection, main_figure);

    if (!rc)
    {
        rc = read_projection(tmp_projection.points, main_figure.points);
    }
    if (!rc)
    {
        destroy_projection(figure_projection);
        figure_projection = tmp_projection;
    }
    else
    {
        destroy_projection(tmp_projection);
    }

    return rc;
}

void destroy_all(figure_t &main_figure, prj_data_t &data)
{
    fpr_t *projection = data.projection;
    destroy_figure(main_figure);
    if (projection)
    {
        destroy_projection(*projection);
    }
}

err_t read_from_file(figure_t &figure, load_data_t &data)
{
    return read_from_file(figure, data.filename);
}

err_t draw_figure(draw_data_t &draw_data, prj_data_t &prj_data, const figure_t &main_figure)
{
    if (get_projection(prj_data, main_figure))
    {
        return DATA_ERROR;
    }

    return draw_figure(draw_data, *prj_data.projection);
}

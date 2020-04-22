#include "task_manager.h"

err_t task_manager(const event_t &event, event_data_t &data)
{
    err_t rc = OK;
    static figure_t main_figure = init_figure();

    switch (event.command)
    {
    case LOAD_DATA:
        rc = read_from_file(main_figure, data.load_data);
        break;
    case MOVE:
        rc = move_command(main_figure, data.trans_data);
        break;
    case SCALE:
        rc = scale_command(main_figure, data.trans_data);
        break;
    case ROTATE:
        rc = rotate_command(main_figure, data.trans_data);
        break;
    case UPDATE_PROJECTION:
        rc = get_projection(data.prj_data, main_figure);
        break;
    case DRAW:
        rc = draw_figure(data.draw_data, data.prj_data);
        break;
    case QUIT:
        destroy_all(main_figure, data.prj_data);
        break;
    default:
        rc = COMMAND_ERROR;
    }
    return rc;
}

event_t init_event(const char command)
{
    event_t event;
    event.command = command;

    return event;
}

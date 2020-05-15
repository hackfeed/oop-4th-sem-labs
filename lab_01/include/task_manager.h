#ifndef _TASK_MANAGER_H_
#define _TASK_MANAGER_H_

#include "codes.h"
#include "constants.h"
#include "io_figure.h"
#include "figure.h"
#include "cmds.h"
#include "draw_fn.h"
#include "eventd.h"

struct event
{
    char command;
};
using event_t = struct event;

err_t task_manager(const event_t &event, event_data_t &data);
event_t init_event(const char command = 0);

#endif

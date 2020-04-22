#include "draw_module.h"

void create_line(Cairo::RefPtr<Cairo::Context> &cr, const ppoint_t from, const ppoint_t to)
{
    cr->move_to(from.x, from.y);
    cr->line_to(to.x, to.y);
    cr->stroke();
}

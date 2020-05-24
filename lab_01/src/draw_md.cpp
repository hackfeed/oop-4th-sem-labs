#include "draw_md.h"

void draw_line(drawer_t &drawer, const ppoint_t from, const ppoint_t to)
{
    drawer.drw->move_to(from.x, from.y);
    drawer.drw->line_to(to.x, to.y);
    drawer.drw->stroke();
}

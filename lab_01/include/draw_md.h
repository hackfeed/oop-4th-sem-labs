#ifndef _DRAW_MD_
#define _DRAW_MD_

#include <gtkmm-3.0/gtkmm.h>
#include "points.h"

struct drawer
{
    Cairo::RefPtr<Cairo::Context> &drw;
};
using drawer_t = drawer;

void draw_line(drawer_t &drawer, const ppoint_t from, const ppoint_t to);

#endif

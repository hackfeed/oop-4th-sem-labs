#ifndef _DRAW_MD_
#define _DRAW_MD_

#include <gtkmm-3.0/gtkmm.h>
#include "points.h"

void create_line(Cairo::RefPtr<Cairo::Context> &cr, const ppoint_t from, const ppoint_t to);

#endif

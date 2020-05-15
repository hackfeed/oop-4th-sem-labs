#ifndef _DRAW_FN_H_
#define _DRAW_FN_H_

#include <gtkmm-3.0/gtkmm.h>
#include "eventd.h"
#include "figure.h"
#include "constants.h"
#include "draw_md.h"

err_t draw_figure(draw_data_t &data, const fpr_t &figure);

#endif

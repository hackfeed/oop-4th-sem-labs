#ifndef _IO_LINKS_H_
#define _IO_LINKS_H_

#include "links_arr.h"
#include "constants.h"

#include <cstdlib>
#include <cstdio>

err_t handle_links(larr_t &links_array, FILE *const f, const unsigned int max_index);
void destroy_links(larr_t &links);

#endif

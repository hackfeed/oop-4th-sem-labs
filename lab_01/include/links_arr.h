#ifndef _LINKS_ARR_H_
#define _LINKS_ARR_H_

#include "links.h"

struct links_array
{
    link_t *arr;
    unsigned int size;
};
using larr_t = struct links_array;

larr_t init_links_arr(link_t *const arr = 0, const unsigned int size = 0);

#endif

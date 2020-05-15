#include "links_arr.h"

larr_t init_links_arr(link_t *const arr, const unsigned int size)
{
    larr_t links_arr;
    links_arr.arr = arr;
    links_arr.size = size;

    return links_arr;
}

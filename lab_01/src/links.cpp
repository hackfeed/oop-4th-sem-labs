#include "links.h"

link_t init_link(const unsigned int l1, const unsigned int l2)
{
    link_t link;
    link.l1 = l1;
    link.l2 = l2;

    return link;
}

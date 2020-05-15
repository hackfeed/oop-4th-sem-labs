#ifndef _LINKS_H_
#define _LINKS_H_

struct link
{
    unsigned int l1;
    unsigned int l2;
};
using link_t = struct link;

link_t init_link(const unsigned int l1 = 0, const unsigned int l2 = 0);

#endif

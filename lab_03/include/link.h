#ifndef LINK_H
#define LINK_H

#include <stdlib.h>

class link
{
public:
    link() : pt1_index(0), pt2_index(0) {};
    link(const size_t &pt1, const size_t &pt2) : pt1_index(pt1), pt2_index(pt2) {};
    link(const link &_link);
    ~link() = default;

    size_t get_fst() const;
    size_t get_snd() const;

    void set_fst(const size_t &fst);
    void set_snd(const size_t &snd);

private:
    size_t pt1_index;
    size_t pt2_index;
};

#endif

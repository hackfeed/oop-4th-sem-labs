#ifndef DETAILS_H
#define DETAILS_H

#include "vector.hpp"
#include "iterator.hpp"
#include "link.h"
#include "point.h"

class details
{
public:
    details() = default;
    details(vector<point> &_points, vector<link> &_links) : points(_points), links(_links){};
    ~details() = default;

    void add_point(const point &pt);
    void add_link(const link &link);
    const vector<point> &get_points() const;
    const vector<link> &get_links() const;

    void reform(const point &move, const point &scale, const point &turn);

private:
    vector<point> points;
    vector<link> links;
};

#endif

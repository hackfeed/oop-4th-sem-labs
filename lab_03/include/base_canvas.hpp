#ifndef BASE_CANVAS_HPP
#define BASE_CANVAS_HPP

#include "point.hpp"

class BaseCanvas
{
public:
    virtual void DrawLine(const Point<double> &p1, const Point<double> &p2) = 0;
};

#endif